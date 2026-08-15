#include "terrain.h"

Terrain::Terrain(){
    return;
}

Terrain::Terrain(TerrainType type, ResourceType resource){
    this->type = type;
    this->resource = resource;
    return;
}

void Terrain::setColor(Palette color){
    this->color = color;
}