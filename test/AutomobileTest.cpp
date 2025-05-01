#include <gtest/gtest.h>
#include "ElectricCar.h"
#include "GasCar.h"
#include "DieselCar.h"

TEST(AutomobileTest, ElectricCarCreation) {
    ElectricCar car("Tesla", "Model 3", 2023, 5000);
    EXPECT_EQ(car.getType(), "electric");
    EXPECT_EQ(car.getMake(), "Tesla");
    EXPECT_EQ(car.getModel(), "Model 3");
    EXPECT_EQ(car.getYear(), 2023);
    EXPECT_EQ(car.getOdometerReading(), 5000);
}

TEST(AutomobileTest, GasCarCreation) {
    GasCar car("Toyota", "Camry", 2022, 15000);
    EXPECT_EQ(car.getType(), "gas");
    EXPECT_EQ(car.getMake(), "Toyota");
}

TEST(AutomobileTest, OdometerUpdate) {
    DieselCar car("Ford", "F-150", 2021, 30000);
    car.setOdometerReading(35000);
    EXPECT_EQ(car.getOdometerReading(), 35000);
}