#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "headers.hpp"

extern map<int, Customer> tempCustomersMap;
extern map<int, Vehicle> tempVehiclesMap;

int readInstances(const std::string& filename);
void assignRouteToVehicle(int vehicleId, double capacity);

#endif // FUNCTIONS_HPP