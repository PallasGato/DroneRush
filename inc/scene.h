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
    InputHandler* input_handler;

public:
    Scene(InputHandler& input_handler);
    virtual ~Scene() = default;

    void add_game_object(std::unique_ptr<GameObject> game_object);
    void add_ui_object(std::unique_ptr<UIobject> ui_object);
    void add_view_position(Vector2DF position_change);
    void render(SDL_Renderer& renderer);
    virtual void update(float delta_time) = 0;

    const Camera& get_camera() const;
    Camera& get_camera();
};
  
    