#pragma once

#include <list>
#include <vector>
#include <SDL3/SDL.h>
#include <memory>
#include "game_object.h"
#include "input_handler.h"
#include "geometry.h"
#include "ui_object.h"
#include "camera.h"
class Scene{
private:
    std::list<std::unique_ptr<GameObject>> game_objects = {};
    std::vector<std::unique_ptr<UIobject>> ui_objects = {};
protected:
    Camera camera;

public:
    Scene();
    virtual ~Scene() = default;

    void add_game_object(std::unique_ptr<GameObject> game_object);
    void add_ui_object(std::unique_ptr<UIobject> ui_object);
    void add_view_position(Vector2DF position_change);
    void render(SDL_Renderer& renderer);
    virtual void update(InputHandler& input_handler) = 0;

    const Camera& get_camera() const;
    Camera& get_camera();
};
  
    