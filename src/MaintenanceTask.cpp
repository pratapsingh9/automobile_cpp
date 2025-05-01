#include "MaintenanceTask.h"

MaintenanceTask::MaintenanceTask(std::string name, std::string desc, std::vector<std::string> types)
    : taskName(std::move(name)), description(std::move(desc)), applicableVehicleTypes(std::move(types)) {}

std::string MaintenanceTask::getTaskName() const { return taskName; }
std::string MaintenanceTask::getDescription() const { return description; }

bool MaintenanceTask::isApplicable(const std::string& vehicleType) const {
    for (const auto& type : applicableVehicleTypes) {
        if (type == vehicleType) return true;
    }
    return false;
}