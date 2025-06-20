#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "headers.hpp"

extern map<int, Customer> tempCustomersMap;
extern map<int, Vehicle> tempVehiclesMap;
extern time_t startTime, middleTime;
extern double GreedyTime, hcTime, totalTime;

int readInstances(const string& filename);
void assignRouteToVehicle(int vehicleId);
int solInstance(const string& filename);

#endif // FUNCTIONS_HPP