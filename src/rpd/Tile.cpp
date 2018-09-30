#include "Tile.hpp"

namespace rpd {

Tile::Tile(int tile_id, int tile_adjacency, Tileset ts, int x, int y, int z) :
      pos_x_(x), pos_y_(y), pos_z_(z), renderable_(ts.getRenderable(tile_id)),
      tile_id_(tile_id), tile_variant_(4), collision_(ts.getTileCollision(tile_id)),
      cost_(ts.getTileCost(tile_id)) {

}

Tile::~Tile() {

}

Tile::Tile(const Tile& other) : 
      pos_x_(other.pos_x_), pos_y_(other.pos_y_), pos_z_(other.pos_z_), 
      renderable_(other.renderable_), 
      tile_id_(other.tile_id_), 
      tile_variant_(other.tile_variant_), 
      collision_(other.collision_),
      cost_(other.cost_) {
 
}

Tile& Tile::operator=(const Tile& rhs) {
   pos_x_ = rhs.pos_x_;
   pos_y_ = rhs.pos_y_;
   pos_z_ = rhs.pos_z_;
   renderable_ = rhs.renderable_;
   tile_id_ = rhs.tile_id_;
   tile_variant_ = rhs.tile_variant_;
   collision_ = rhs.collision_;
   cost_ = rhs.cost_;
}

std::pair<double, double> Tile::CalcCost(double actor_vel_x, double actor_vel_y) {
   return std::make_pair(actor_vel_x * cost_, actor_vel_y * cost_);
}

void Tile::ReceiveInput(engine::InputData input) {
   //nah fam this is a tile
}

void Tile::Update(int ticks) {
   //nah fam this is a tile
}

void Tile::Render() {
   renderable_->Render(pos_x_, pos_y_);
}

} // namespace rpd