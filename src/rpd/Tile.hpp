#ifndef RPD_TILE_HPP
#define RPD_TILE_HPP

#include "../engine/Renderable.hpp"
#include "../engine/InputData.hpp"
#include "Tileset.hpp"
#include <utility>

namespace rpd {

class Tile {
public:
   Tile(int tile_id, int tile_adjacency, Tileset ts, int x, int y, int z);
   ~Tile();
   Tile(const Tile& other);
   Tile& operator=(const Tile& rhs);
   std::pair<double, double> CalcCost(double actor_vel_x, double actor_vel_y);
   void ReceiveInput(engine::InputData input);
   void Update(int ticks);
   void Render();
   inline bool CollisionCheck(int actor_move_type) { return actor_move_type <= collision_; }
   inline void SetVariant(int variant) { tile_variant_ = variant; }

private:
   double pos_x_ = 0;
   double pos_y_ = 0;
   double pos_z_ = 0;
   engine::Renderable* renderable_ = nullptr;
   int tile_id_;
   int tile_variant_;
   int collision_;
   double cost_;
};

} // namespace rpd

#endif // RPD_TILE_HPP