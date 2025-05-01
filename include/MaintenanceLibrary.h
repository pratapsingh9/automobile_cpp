#pragma once
#include <vector>
#include <memory>
#include "Automobile.h"
#include "MaintenanceTask.h"

class MaintenanceLibrary {
public:
    struct VehicleEntry {
        std::unique_ptr<Automobile> vehicle;
        std::vector<std::unique_ptr<MaintenanceTask>> tasks;
    };

private:
    std::vector<VehicleEntry> vehicles;

public:
    void addVehicle(std::unique_ptr<Automobile> vehicle);
    bool removeVehicle(const std::string& make, const std::string& model, int year);
    std::vector<Automobile*> listVehicles() const;
    bool addMaintenanceTask(Automobile* vehicle, std::unique_ptr<MaintenanceTask> task);
    std::vector<MaintenanceTask*> listMaintenanceTasks(Automobile* vehicle) const;
};