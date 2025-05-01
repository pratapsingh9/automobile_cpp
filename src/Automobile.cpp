
#include "Automobile.h"

Automobile::Automobile(std::string make, std::string model, int year, int odometer)
    : make(std::move(make)), model(std::move(model)), year(year), odometerReading(odometer) {}

std::string Automobile::getMake() const { return make; }
std::string Automobile::getModel() const { return model; }
int Automobile::getYear() const { return year; }
int Automobile::getOdometerReading() const { return odometerReading; }

void Automobile::setOdometerReading(int reading) { odometerReading = reading; }