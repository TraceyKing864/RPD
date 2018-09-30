#ifndef RPD_TILESET_HPP
#define RPD_TILESET_HPP

#include "../engine/Renderable.hpp"
#include <string>
#include <memory>
#include <map>
#include <utility>

namespace rpd {

enum MOVE_TYPE {
   GHOST = 1,
   FLYING = 2,
   AQUATIC = 3,
   WALKING = 4
};

enum COLLISION {
   IMPASSABLE = 0,   //nothing can pass through this
   WALL = 1,         //if you can pass through walls
   MOUNTAINS = 2,    //if you can pass over mountains
   WATER = 3,        //if you can pass through water
   STANDARD = 4,     //just your regular ol ground
   PASSABLE = 7      //always passable
};

class Tileset {
public:
   Tileset(std::string tileset_name);
   ~Tileset();
   Tileset(const Tileset& other);
   Tileset& operator=(const Tileset& rhs);
   engine::Renderable* getRenderable(int tile_id);
   int getTileCollision(int tile_id);
   double getTileCost(int tile_id);
   void loadTileset(std::string tileset_name);
   void unloadTileset();
private:
   std::string tileset_name_;
   std::map<int, std::unique_ptr<engine::Renderable> > tile_renderables_;
   std::map<int, int> tile_collisions_;
   std::map<int, double> tile_costs_;

};

} // namespace rpd

#endif // RPD_TILE_HPP