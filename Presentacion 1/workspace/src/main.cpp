#include "functions.hpp"


int main() {
    string filename = "./workspace/resources/GA1.txt";
    string outFilename = "./workspace/output/GA1.txt";

    if(readInstances(filename) == 1){
        return 1;
    }

    // --- Now we have the problem with data loaded ---
    // This block is just for demonstration purposes
    //cout << "Datos cargados:" << endl;
    //cout << "Numero de nodos: " << tempCustomersMap.size() << endl;
    //for (const auto& cust : tempCustomersMap) {
    //    cout << "  Node ID: " << cust.second.id
    //         << ", Type: " << cust.second.type
    //         << ", Coords: (" << cust.second.x << ", " << cust.second.y << ")"
    //         << ", Demand: " << cust.second.demand << endl;
    //}
//
    //cout << "Numero de vehiculos: " << tempVehiclesMap.size() << endl;
    //for (const auto& veh : tempVehiclesMap) {
    //    cout << "  Vehicle ID: " << veh.second.id << ", Capacity: " << veh.second.capacity << endl;
    //}
    // --- End of data loading demonstration ---

    // Example of calculating distance between two customers
    // This is just a demonstration; in practice, you would use this in your routing logic
    //if (tempCustomersMap.size() > 1) {
    //    // Get iterators to the first two customers in the map
    //    auto it1 = tempCustomersMap.begin();
    //    auto it2 = next(tempCustomersMap.begin(), 1);
    //    cout << "Distancia entre nodo " << it1->second.id << " y nodo "
    //         << it2->second.id << ": " << it1->second.calculateDistance(it2->second) << endl;
    //}
    // End of demonstration

    startTime = time(nullptr);

    // Assign routes to vehicles with Greedy Algorithm    
    for (const auto& vehicle : tempVehiclesMap) {
        assignRouteToVehicle(vehicle.second.id);
    }
    middleTime = time(nullptr);
    GreedyTime = difftime(middleTime, startTime);

    // Improve the solution with Hill Climbing (HC) algorithm
    middleTime = time(nullptr);
    // for (const auto& vehicle : tempVehiclesMap) {
    //     hillClimbing(vehicle.second.id, vehicle.second.capacity);
    // }
    hcTime = difftime(time(nullptr), middleTime);

    // Write the output
    if (solInstance(outFilename) == 1) {
        return 1;
    }

    return 0;
}