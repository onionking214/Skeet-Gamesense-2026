#include "include/stdafx.hpp"
#include "include/telemetry.hpp"

// Skeet Tactical Vector Analytics - Entry Point
int main() {
    SetConsoleTitleA("Skeet Vector Analytics: Telemetry Node");
    
    if (!Telemetry::InitializeKernel()) {
        std::cerr << "[!] Error: Failed to initialize telemetry bridge." << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "[*] Skeet Core active. Awaiting simulation heartbeat..." << std::endl;
    
    while (Telemetry::IsActive()) {
        Telemetry::UpdateSpatialVectors();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    return EXIT_SUCCESS;
}
