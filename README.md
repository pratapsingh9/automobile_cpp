# 🚗 Automobile Maintenance Library

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![CMake](https://img.shields.io/badge/CMake-3.14+-brightgreen.svg)
![License](https://img.shields.io/badge/License-MIT-orange.svg)
![Tests](https://github.com/yourusername/automobile-maintenance/actions/workflows/tests.yml/badge.svg)

A modern C++ library for managing vehicle maintenance tasks with type-safe operations and polymorphic vehicle support.

## 📋 Table of Contents
- [Features](#-features)
- [Installation](#-installation)
- [Usage](#-usage)
- [API Reference](#-api-reference)
- [Testing](#-testing)
- [Contributing](#-contributing)
- [License](#-license)

## ✨ Features
- **Vehicle Type Support**:
  - 🔋 Electric vehicles
  - ⛽ Gasoline vehicles
  - 🚛 Diesel vehicles
- **Maintenance Tracking**:
  - ✅ Task type validation
  - 📅 Maintenance history
  - 🔍 Task-vehicle compatibility checking
- **Modern C++**:
  - Smart pointers (`std::unique_ptr`)
  - Polymorphic design
  - RAII resource management
- **Extensible Architecture**:
  - Easy to add new vehicle types
  - Custom maintenance task support

## 📦 Installation

### Prerequisites
- C++17 compatible compiler (GCC 8+, Clang 7+, MSVC 2019+)
- CMake 3.14+
- Git
- Google Test (for testing, optional)

### Build Steps

```bash


# Configure and build
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --parallel

# Run tests (optional)
ctest --output-on-failure

# Install (optional)
sudo cmake --install .