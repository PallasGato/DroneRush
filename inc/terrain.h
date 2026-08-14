#pragma once

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
public:
    Terrain();
    Terrain(TerrainType type, ResourceType resource);
    TerrainType get_type();
};