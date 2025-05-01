#include "ElectricCar.h"

ElectricCar::ElectricCar(std::string make, std::string model, int year, int odometer)
    : Automobile(std::move(make), std::move(model), year, odometer) {}

std::string ElectricCar::getType() const { return "electric"; }