#pragma once
#include "Automobile.h"

class ElectricCar : public Automobile {
public:
    ElectricCar(std::string make, std::string model, int year, int odometer);
    std::string getType() const override;
};