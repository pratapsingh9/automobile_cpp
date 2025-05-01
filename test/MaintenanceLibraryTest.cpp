#include <gtest/gtest.h>
#include "MaintenanceLibrary.h"
#include "ElectricCar.h"
#include "GasCar.h"
#include "MaintenanceTask.h"

TEST(MaintenanceLibraryTest, AddAndRemoveVehicle) {
    MaintenanceLibrary library;
    
    // Add vehicles
    library.addVehicle(std::make_unique<ElectricCar>("Tesla", "Model S", 2023, 1000));
    library.addVehicle(std::make_unique<GasCar>("Honda", "Civic", 2022, 20000));
    
    // Verify count
    EXPECT_EQ(library.listVehicles().size(), 2);
    
    // Remove vehicle
    bool removed = library.removeVehicle("Honda", "Civic", 2022);
    EXPECT_TRUE(removed);
    EXPECT_EQ(library.listVehicles().size(), 1);
}

TEST(MaintenanceLibraryTest, MaintenanceTaskAssignment) {
    MaintenanceLibrary library;
    auto* electricCar = library.listVehicles()[0];
    
    // Create valid task for electric car
    auto batteryTask = std::make_unique<MaintenanceTask>(
        "Battery Check", 
        "Inspect battery health",
        std::vector<std::string>{"electric"}
    );
    
    bool added = library.addMaintenanceTask(electricCar, std::move(batteryTask));
    EXPECT_TRUE(added);
    
    // Create invalid task for electric car
    auto oilTask = std::make_unique<MaintenanceTask>(
        "Oil Change",
        "Change engine oil",
        std::vector<std::string>{"gas", "diesel"}
    );
    
    added = library.addMaintenanceTask(electricCar, std::move(oilTask));
    EXPECT_FALSE(added); // Should fail - wrong vehicle type
}

TEST(MaintenanceLibraryTest, ListMaintenanceTasks) {
    MaintenanceLibrary library;
    auto* gasCar = library.listVehicles()[0];
    
    auto tireTask = std::make_unique<MaintenanceTask>(
        "Tire Rotation",
        "Rotate tires for even wear",
        std::vector<std::string>{"electric", "gas", "diesel"}
    );
    
    library.addMaintenanceTask(gasCar, std::move(tireTask));
    
    auto tasks = library.listMaintenanceTasks(gasCar);
    EXPECT_EQ(tasks.size(), 1);
    EXPECT_EQ(tasks[0]->getTaskName(), "Tire Rotation");
}