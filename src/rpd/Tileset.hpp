#ifndef RPD_TILESET_HPP
#define RPD_TILESET_HPP

#include "../engine/Renderable.hpp"
#include <string>
#include <memory>
#include <map>
#include <utility>

namespace rpd {

enum MOVE_TYPE {
   WALKING,
   FLYING,
   AQUATIC,
   GHOST
};

enum COLLISION {
   STANDARD,    // just your regular ol ground
   PASSABLE,    // always passable
   WATER,       // if you can pass through water
   WALL,        // if you can pass through walls
   MOUNTAINS,   // if you can pass over mountains
   IMPASSABLE   // nothing can pass through this
};

class Tileset {
public:
   Tileset(std::string tileset_name);
   ~Tileset();
   Tileset(const Tileset& other);
   Tileset& operator=(const Tileset& rhs);
   engine::Renderable* GetRenderable(int tile_id);
   int GetTileCollision(int tile_id);
   double GetTileCost(int tile_id);
   void LoadTileset(std::string tileset_name);
   void UnloadTileset();
private:
   std::string tileset_name_;
   std::map<int, std::unique_ptr<engine::Renderable> > tile_renderables_;
   std::map<int, int> tile_collisions_;
   std::map<int, double> tile_costs_;

};

} // namespace rpd

#endif // RPD_TILESET_HPP
