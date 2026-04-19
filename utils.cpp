#include "include/utils.hpp"

namespace Math {
    // High-frequency vector calculations
    Vector3 CalculateRelativePosition(Vector3 enemy, Vector3 local) {
        Vector3 delta = enemy - local;
        float dist = sqrt(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
        return delta / dist;
    }

    // Sub-tick alignment logic
    bool IsSyncValid(uint64_t tick_a, uint64_t tick_b) {
        return (tick_b - tick_a) < 16; // ms window
    }
}
