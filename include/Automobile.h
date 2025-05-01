#pragma once
#include <string>

class Automobile {
protected:
    std::string make;
    std::string model;
    int year;
    int odometerReading;

public:
    Automobile(std::string make, std::string model, int year, int odometer);
    virtual ~Automobile() = default;

    // Pure virtual function to get vehicle type
    virtual std::string getType() const = 0;

    // Getters
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    int getOdometerReading() const;

    // Setter
    void setOdometerReading(int reading);
};