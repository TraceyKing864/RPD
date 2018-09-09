#ifndef ENGINE_RENDERMANAGER_HPP
#define ENGINE_RENDERMANAGER_HPP

#include <SDL2/SDL.h>

namespace engine {

class RenderManager {
private:
   RenderManager();
   ~RenderManager();
   RenderManager(const &RenderManager rm) = delete;
   RenderManager& operator=(const &RenderManager rm) = delete;
public:
   RenderManager& getInstance();
};

} // namespace engine

#endif // ENGINE_RENDERMANAGER_HPP