#ifndef HEADERS_HPP
#define HEADERS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Define constants for node types for better readability
enum NodeType {
    DEPOT = 0,
    LINEHAUL = 1,
    BACKHAUL = 2
};

struct Customer {
    int id;
    NodeType type;
    double x, y;
    double demand;
    bool isVisited;

    // Constructor
    Customer(int id, NodeType type, double x, double y, double demand = 0.0)
        : id(id), type(type), x(x), y(y), demand(demand), isVisited(false) {}

    // Method to calculate distance to another customer
    double calculateDistance(const Customer& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
};

struct Vehicle {
    int id;
    double capacity;
    double currentLoad; // Track current load on the vehicle
    double routeDistance; // Total distance traveled by the vehicle
    vector<int> currentRoute; // Stores customer IDs in order of visit
};

#endif // HEADERS_HPP