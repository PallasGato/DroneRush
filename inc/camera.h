#include <SDL3/SDL.h>

class Camera{
private:
    float x;
    float y;
public:
    Camera();
    Camera (float x_pos, float y_pos);
    void move(float x, float y);
};