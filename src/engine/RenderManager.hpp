#ifndef ENGINE_RENDERMANAGER_HPP
#define ENGINE_RENDERMANAGER_HPP

#include <SDL2/SDL.h>

namespace engine {

class RenderManager {
private:
   SDL_Window* window;
   SDL_Renderer* renderer;

   RenderManager();
   ~RenderManager();
   RenderManager(const RenderManager&) = delete;
   RenderManager& operator=(const RenderManager&) = delete;
public:
   static RenderManager& GetInstance();
   void Render(const SDL_texture& texture, const SDL_rect& src, const SDL_rect& dest);
};

} // namespace engine

#endif // ENGINE_RENDERMANAGER_HPP