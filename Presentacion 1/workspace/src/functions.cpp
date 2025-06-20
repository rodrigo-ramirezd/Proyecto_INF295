#include "functions.hpp"

// Global maps to store customers and vehicles
map<int, Customer> tempCustomersMap;
map<int, Vehicle> tempVehiclesMap;
time_t startTime, middleTime;
double GreedyTime = 0.0, hcTime = 0.0, totalTime = 0.0;

// Function to read instances from a file
int readInstances(const string& filename) {

    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }
    // 1. Read Number of Nodes
    int numNodes;
    inputFile >> numNodes;
    
    // 2. Read Node Information (Type, ID, Coords)
    for (int i = numNodes; i > 0; --i) {
        int type_node_int, id_node;
        double coord_x, coord_y;
        inputFile >> type_node_int >> id_node >> coord_x >> coord_y;
        
        // Cast integer type to enum NodeType
        NodeType type_node = static_cast<NodeType>(type_node_int);
        
        // Create a temporary customer object (demand will be added later)
        tempCustomersMap.emplace(id_node, Customer(id_node, type_node, coord_x, coord_y));
    }
    
    // 3. Read Vehicle Information
    int numVehicles;
    double vehicleCapacity;
    inputFile >> numVehicles >> vehicleCapacity;
    
    for (int i = 0; i < numVehicles; ++i) {
        tempVehiclesMap.emplace(i + 1, Vehicle{i + 1, vehicleCapacity, vehicleCapacity, 0.0, {}});
    }
    
    // 4. Read Demands for Customers
    for (int i = numNodes - 1; i > 0; --i) { // Loop for numNodes - 1 demands
        int id_node_demand;
        double demand_val;
        inputFile >> id_node_demand >> demand_val;
        
        // Find the customer in the map and update their demand
        auto it = tempCustomersMap.find(id_node_demand);
        if (it != tempCustomersMap.end()) {
            it->second.demand = demand_val;
        } else {
            cerr << "Error: Demand specified for unknown node ID: " << id_node_demand << endl;
            // Handle error: perhaps exit or throw an exception
        }
    }
    return 0;
};

// Function to assign a route to a vehicle
void assignRouteToVehicle(int vehicleId) {
    auto vehicleIt = tempVehiclesMap.find(vehicleId);
    if (vehicleIt == tempVehiclesMap.end()) {
        cerr << "Error: Vehicle ID " << vehicleId << " not found." << endl;
        return;
    }

    Vehicle& vehicle = vehicleIt->second;
    vehicle.currentRoute.push_back(0);

    // Greedily assign customers to the vehicle's route
    // 1st 'for' assign only LINEHAUL customers that haven't been visited and can fit in the vehicle.
    for (auto& auxCustomer : tempCustomersMap) {
        Customer& customer = auxCustomer.second;

        if (customer.type == LINEHAUL && !customer.isVisited && (vehicle.currentLoad - customer.demand >= 0.0)) {
            vehicle.currentLoad -= customer.demand;
            customer.isVisited = true;

            int lastCustomerId = vehicle.currentRoute.back();
            Customer& lastCustomer = tempCustomersMap.find(lastCustomerId)->second;
            double distance = customer.calculateDistance(lastCustomer);
            vehicle.routeDistance += distance;
            vehicle.currentRoute.push_back(customer.id);
        }
    }

    // 2nd 'for' assign BACKHAUL customers that haven't been visited and can fit in the vehicle.
    for (auto& auxCustomer : tempCustomersMap) {
        Customer& customer = auxCustomer.second;

        if (customer.type == BACKHAUL && !customer.isVisited && (vehicle.currentLoad + customer.demand <= vehicle.capacity)) {
            vehicle.currentLoad += customer.demand;
            customer.isVisited = true;

            int lastCustomerId = vehicle.currentRoute.back();
            Customer& lastCustomer = tempCustomersMap.find(lastCustomerId)->second;
            double distance = customer.calculateDistance(lastCustomer);
            vehicle.routeDistance += distance;
            vehicle.currentRoute.push_back(customer.id);
        }
    }
}

// Function to solve the instance (currently a placeholder)
int solInstance(const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    outputFile << "RESULTADOS DE LA SOLUCIÓN" << endl;
    outputFile << "Valor Función de Evaluación: " << endl;
    outputFile << "#Clientes Atendidos: " << tempCustomersMap.size() << endl;
    outputFile << "#Vehiculos: " << tempVehiclesMap.size() << endl;
    outputFile << "Tiempo de Ejecución Total[s]: " << totalTime << endl;
    outputFile << "Tiempo de Ejecución del algoritmo Greedy[s]: " << GreedyTime << endl;
    outputFile << "Tiempo de Ejecución del algoritmo HC+FI[s]: " << hcTime << endl;
    outputFile << "----------------------------------------------------------" << endl;
    for (auto i = tempVehiclesMap.begin(); i != tempVehiclesMap.end(); ++i) {
        outputFile << "Vehículo ID: " << i->second.id << endl;
        outputFile << "Ruta asignada: ";
        for (const auto& nodeId : i->second.currentRoute) {
            outputFile << "->" << nodeId;
        }
        outputFile << endl << "Distancia Recorrida: " << i->second.routeDistance << endl;
        outputFile << "Demanda Total: " << i->second.currentLoad << endl;
        outputFile << "----------------------------------------------------------" << endl;
    }

    return 0;
}