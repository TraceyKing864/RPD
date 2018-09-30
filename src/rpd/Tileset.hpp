#ifndef RPD_TILESET_HPP
#define RPD_TILESET_HPP

#include "../engine/Renderable.hpp"
#include <string>
#include <memory>

namespace rpd {

class Tileset {
public:
   Tileset();
   ~Tileset();
   Tileset(const Tileset& other);
   Tileset& operator=(const Tileset& rhs);
   std::unique_ptr<engine::Renderable> getRenderable(int tile_id);
   int getTileCollision(int tile_id);
   double getTileCost(int tile_id);
   void loadTileset(std::string tileset_name);
   void unloadTileset();
private:
   std::string tileset_name_;
   std::map<int, std::unique_ptr<engine::Renderable> tile_renderables_;
   std::map<int, int> tile_collisions_;
   std::map<int, double> tile_costs_;

}

} // namespace rpd

#endif // RPD_TILE_HPP