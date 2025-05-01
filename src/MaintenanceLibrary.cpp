#include "MaintenanceLibrary.h"

void MaintenanceLibrary::addVehicle(std::unique_ptr<Automobile> vehicle) {
    vehicles.push_back({std::move(vehicle), {}});
}

bool MaintenanceLibrary::removeVehicle(const std::string& make, const std::string& model, int year) {
    auto it = std::remove_if(vehicles.begin(), vehicles.end(), [&](const VehicleEntry& entry) {
        return entry.vehicle->getMake() == make && 
               entry.vehicle->getModel() == model && 
               entry.vehicle->getYear() == year;
    });
    if (it != vehicles.end()) {
        vehicles.erase(it, vehicles.end());
        return true;
    }
    return false;
}

std::vector<Automobile*> MaintenanceLibrary::listVehicles() const {
    std::vector<Automobile*> result;
    for (const auto& entry : vehicles) {
        result.push_back(entry.vehicle.get());
    }
    return result;
}

bool MaintenanceLibrary::addMaintenanceTask(Automobile* vehicle, std::unique_ptr<MaintenanceTask> task) {
    for (auto& entry : vehicles) {
        if (entry.vehicle.get() == vehicle) {
            if (task->isApplicable(vehicle->getType())) {
                entry.tasks.push_back(std::move(task));
                return true;
            }
        }
    }
    return false;
}

std::vector<MaintenanceTask*> MaintenanceLibrary::listMaintenanceTasks(Automobile* vehicle) const {
    std::vector<MaintenanceTask*> result;
    for (const auto& entry : vehicles) {
        if (entry.vehicle.get() == vehicle) {
            for (const auto& task : entry.tasks) {
                result.push_back(task.get());
            }
        }
    }
    return result;
}