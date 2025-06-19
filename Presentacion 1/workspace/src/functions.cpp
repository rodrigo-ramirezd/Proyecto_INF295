#include "functions.hpp"

// Global maps to store customers and vehicles
map<int, Customer> tempCustomersMap;
map<int, Vehicle> tempVehiclesMap;

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

void assignRouteToVehicle(int vehicleId, double capacity) {
    // Create a new vehicle and add it to the global map
    tempVehiclesMap.emplace(vehicleId, Vehicle{vehicleId, capacity, 0.0, 0.0, {}});
}