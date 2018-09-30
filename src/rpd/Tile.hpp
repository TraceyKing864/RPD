#ifndef RPD_TILE_HPP
#define RPD_TILE_HPP

namespace rpd {

enum move_type {
   GHOST = 1,
   FLYING = 2,
   AQUATIC = 3,
   WALKING = 4
}

enum collision {
   IMPASSABLE = 0,   //nothing can pass through this
   WALL = 1,         //if you can pass through walls
   MOUNTAINS = 2,    //if you can pass over mountains
   WATER = 3,        //if you can pass through water
   STANDARD = 4,     //just your regular ol ground
   PASSABLE = 7      //always passable
}

class Tile {
public:
   Tile(int tile_id, int tile_adjacency, Tileset ts, int x, int y, int z);
   ~Tile();
   Tile(const Tile& other);
   Tile& operator=(const Tile& rhs);
   std::pair<double> calcCost(double actor_vel_x, double actor_vel_y);
   void ReceiveInput(engine::InputData input);
   void Update(int ticks);
   void Render();
   inline bool collisionCheck(int actor_move_type) { return actor_move_type <= collision_; }
   inline void setVariant(int variant) { tile_variant_ = variant; }


private:
   double pos_x_ = 0;
   double pos_y_ = 0;
   double pos_z_ = 0;
   std::unique_ptr<engine::Renderable> renderable_ = nullptr;
   int tile_id_;
   int tile_variant_;
   int collision_;
   double cost_;
}

} // namespace rpd

#endif // RPD_TILE_HPP