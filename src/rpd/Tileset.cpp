#include "Tileset.hpp"

namespace rpd {

Tileset::Tileset(std::string tileset_name) {
   // @TODO: add better way to do this, hardcoded for now
   if(tileset_name == "town") {
      tileset_name_ = tileset_name;
      //0 = path
      tile_renderables_[0] = std::make_unique<engine::Renderable> ("../assets/path.png", 0 , 0);
      tile_collisions_[0] = COLLISION::STANDARD;
      tile_costs_[0] = 1;
      //1 = grass
      tile_renderables_[1] = std::make_unique<engine::Renderable> ("../assets/grass.png", 0 , 0);
      tile_collisions_[1] = COLLISION::STANDARD;
      tile_costs_[1] = 1;
      //2 = dirt
      tile_renderables_[2] = std::make_unique<engine::Renderable> ("../assets/dirt.png", 0 , 0);
      tile_collisions_[2] = COLLISION::STANDARD;
      tile_costs_[2] = 1;
   } else if(tileset_name == "mountains") {
      tileset_name_ = tileset_name;
      //0 = dirt
      tile_renderables_[0] = std::make_unique<engine::Renderable> ("../assets/dirt.png", 0 , 0);
      tile_collisions_[0] = COLLISION::STANDARD;
      tile_costs_[0] = 1;
      //1 = grass
      tile_renderables_[1] = std::make_unique<engine::Renderable> ("../assets/grass.png", 0 , 0);
      tile_collisions_[1] = COLLISION::STANDARD;
      tile_costs_[1] = 1;
      //2 = hills
      tile_renderables_[2] = std::make_unique<engine::Renderable> ("../assets/hills.png", 0 , 0);
      tile_collisions_[2] = COLLISION::MOUNTAINS;
      tile_costs_[2] = 0.5;
   } else if(tileset_name == "forest") {
      tileset_name_ = tileset_name;
      //0 = grass
      tile_renderables_[0] = std::make_unique<engine::Renderable> ("../assets/grass.png", 0 , 0);
      tile_collisions_[0] = COLLISION::STANDARD;
      tile_costs_[0] = 1;
      //1 = dirt
      tile_renderables_[1] = std::make_unique<engine::Renderable> ("../assets/dirt.png", 0 , 0);
      tile_collisions_[1] = COLLISION::STANDARD;
      tile_costs_[1] = 1;
      //2 = water
      tile_renderables_[2] = std::make_unique<engine::Renderable> ("../assets/water.png", 0 , 0);
      tile_collisions_[2] = COLLISION::WATER;
      tile_costs_[2] = 0.65;
   } else { // default is forest
      tileset_name_ = "forest";
      //0 = grass
      tile_renderables_[0] = std::make_unique<engine::Renderable> ("../assets/grass.png", 0 , 0);
      tile_collisions_[0] = COLLISION::STANDARD;
      tile_costs_[0] = 1;
      //1 = dirt
      tile_renderables_[1] = std::make_unique<engine::Renderable> ("../assets/dirt.png", 0 , 0);
      tile_collisions_[1] = COLLISION::STANDARD;
      tile_costs_[1] = 1;
      //2 = water
      tile_renderables_[2] = std::make_unique<engine::Renderable> ("../assets/water.png", 0 , 0);
      tile_collisions_[2] = COLLISION::WATER;
      tile_costs_[2] = 0.65;
   }
}

Tileset::~Tileset() {

}

Tileset::Tileset(const Tileset& other) {

}

Tileset& Tileset::operator=(const Tileset& rhs) {

}

engine::Renderable* Tileset::GetRenderable(int tile_id){
   return tile_renderables_[tile_id].get();
}

int Tileset::GetTileCollision(int tile_id) {
   return tile_collisions_[tile_id];
}

double Tileset::GetTileCost(int tile_id) {
   return tile_costs_[tile_id];
}

void Tileset::LoadTileset(std::string tileset_name) {
   UnloadTileset();
   // @TODO: add better way to do this, hardcoded for now
   if(tileset_name == "town") {
      tileset_name_ = tileset_name;
      //0 = path
      tile_renderables_[0] = std::make_unique<engine::Renderable> ("../assets/path.png", 0 , 0);
      tile_collisions_[0] = COLLISION::STANDARD;
      tile_costs_[0] = 1;
      //1 = grass
      tile_renderables_[1] = std::make_unique<engine::Renderable> ("../assets/grass.png", 0 , 0);
      tile_collisions_[1] = COLLISION::STANDARD;
      tile_costs_[1] = 1;
      //2 = dirt
      tile_renderables_[2] = std::make_unique<engine::Renderable> ("../assets/dirt.png", 0 , 0);
      tile_collisions_[2] = COLLISION::STANDARD;
      tile_costs_[2] = 1;
   } else if(tileset_name == "mountains") {
      tileset_name_ = tileset_name;
      //0 = dirt
      tile_renderables_[0] = std::make_unique<engine::Renderable> ("../assets/dirt.png", 0 , 0);
      tile_collisions_[0] = COLLISION::STANDARD;
      tile_costs_[0] = 1;
      //1 = grass
      tile_renderables_[1] = std::make_unique<engine::Renderable> ("../assets/grass.png", 0 , 0);
      tile_collisions_[1] = COLLISION::STANDARD;
      tile_costs_[1] = 1;
      //2 = hills
      tile_renderables_[2] = std::make_unique<engine::Renderable> ("../assets/hills.png", 0 , 0);
      tile_collisions_[2] = COLLISION::MOUNTAINS;
      tile_costs_[2] = 0.5;
   } else if(tileset_name == "forest") {
      tileset_name_ = tileset_name;
      //0 = grass
      tile_renderables_[0] = std::make_unique<engine::Renderable> ("../assets/grass.png", 0 , 0);
      tile_collisions_[0] = COLLISION::STANDARD;
      tile_costs_[0] = 1;
      //1 = dirt
      tile_renderables_[1] = std::make_unique<engine::Renderable> ("../assets/dirt.png", 0 , 0);
      tile_collisions_[1] = COLLISION::STANDARD;
      tile_costs_[1] = 1;
      //2 = water
      tile_renderables_[2] = std::make_unique<engine::Renderable> ("../assets/water.png", 0 , 0);
      tile_collisions_[2] = COLLISION::WATER;
      tile_costs_[2] = 0.65;
   } else {   //default is forest
      tileset_name_ = "forest";
      //0 = grass
      tile_renderables_[0] = std::make_unique<engine::Renderable> ("../assets/grass.png", 0 , 0);
      tile_collisions_[0] = COLLISION::STANDARD;
      tile_costs_[0] = 1;
      //1 = dirt
      tile_renderables_[1] = std::make_unique<engine::Renderable> ("../assets/dirt.png", 0 , 0);
      tile_collisions_[1] = COLLISION::STANDARD;
      tile_costs_[1] = 1;
      //2 = water
      tile_renderables_[2] = std::make_unique<engine::Renderable> ("../assets/water.png", 0 , 0);
      tile_collisions_[2] = COLLISION::WATER;
      tile_costs_[2] = 0.65;
   }
}

void Tileset::UnloadTileset() {
   tile_renderables_.clear();
   tile_collisions_.clear();
   tile_costs_.clear();
}

} // namespace rpd
