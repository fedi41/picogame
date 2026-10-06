#include "animations.h"


float distance_v2(Vector2 p1, Vector2 p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrtf(dx * dx + dy * dy);
}

Vector2 move_towards_v2(Vector2 current, Vector2 target, float max_distance_delta) {
    float dx = target.x - current.x;
    float dy = target.y - current.y;
    float dist = sqrtf(dx * dx + dy * dy);

    if (dist <= max_distance_delta || dist < 0.0001f) {
        return target;
    }

    return (Vector2){
        .x = current.x + (dx / dist) * max_distance_delta,
        .y = current.y + (dy / dist) * max_distance_delta
    };
}
