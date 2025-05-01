#include <iostream>
#include <vector>
#include "MaintenanceLibrary.h"
#include "ElectricCar.h"
#include "MaintenanceTask.h"

int main() {
    MaintenanceLibrary library;
    
    // Add some vehicles
    library.addVehicle(std::make_unique<ElectricCar>("Tesla", "Model S", 2020, 15000));
    library.addVehicle(std::make_unique<ElectricCar>("Nissan", "Leaf", 2019, 25000));
    
    // List all vehicles
    const auto vehicles = library.listVehicles();
    if (vehicles.empty()) {
        std::cerr << "No vehicles found in the library!\n";
        return 1;
    }
    
    std::cout << "Vehicles in library:\n";
    for (const auto* vehicle : vehicles) {
        std::cout << vehicle->getMake() << " " << vehicle->getModel() 
                  << " (" << vehicle->getYear() << ")\n";
    }
    
    // Add maintenance tasks to first vehicle
    auto* tesla = vehicles[0];
    std::vector<std::unique_ptr<MaintenanceTask>> tasks;
    tasks.push_back(std::make_unique<MaintenanceTask>(
        "Battery Check",
        "Check battery health and capacity",
        std::vector<std::string>{"electric"}
    ));
    tasks.push_back(std::make_unique<MaintenanceTask>(
        "Tire Rotation",
        "Rotate tires for even wear",
        std::vector<std::string>{"electric", "gas", "diesel"}
    ));
    
    for (auto& task : tasks) {
        if (!library.addMaintenanceTask(tesla, std::move(task))) {
            std::cerr << "Failed to add task.\n";
        }
    }
    
    // List maintenance tasks
    const auto currentTasks = library.listMaintenanceTasks(tesla);
    std::cout << "\nMaintenance tasks for Tesla Model S:\n";
    for (const auto* task : currentTasks) {
        std::cout << "- " << task->getTaskName() 
                  << ": " << task->getDescription() << "\n";
    }
    
    return 0;
}