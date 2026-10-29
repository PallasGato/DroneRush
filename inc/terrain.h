#pragma once
#include "palette.h"

enum class TerrainType{
    Grass,
    Water
};

enum class ResourceType{
    None,
    Gold
};

class Terrain{
private:
    TerrainType type;
    ResourceType resource;
    Palette color;
public:
    Terrain();
    Terrain(TerrainType type, ResourceType resource);
    
    void set_color(Palette color);
    Palette get_color() const;
};