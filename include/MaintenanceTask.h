#pragma once
#include <vector>
#include <string>

class MaintenanceTask {
    std::string taskName;
    std::string description;
    std::vector<std::string> applicableVehicleTypes;

public:
    MaintenanceTask(std::string name, std::string desc, std::vector<std::string> types);
    
    std::string getTaskName() const;
    std::string getDescription() const;
    bool isApplicable(const std::string& vehicleType) const;
};