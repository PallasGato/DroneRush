
#include "geometry.h"

Vector2DF screen_to_world(const Vector2DF& point, const Vector2DF& world_position){
    return {point.x + world_position.x, point.y + world_position.y};
}