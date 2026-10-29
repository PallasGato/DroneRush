#include "terrain.h"

Terrain::Terrain(){
    return;
}

Terrain::Terrain(TerrainType type, ResourceType resource){
    this->type = type;
    this->resource = resource;
    return;
}

void Terrain::set_color(Palette color){
    this->color = color;
}

Palette Terrain::get_color() const{
    return color;
}