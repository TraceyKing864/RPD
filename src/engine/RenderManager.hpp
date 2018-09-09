#ifndef ENGINE_RENDERMANAGER_HPP
#define ENGINE_RENDERMANAGER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
   void Render(const SDL_Texture& texture, const SDL_Rect& src, const SDL_Rect& dest);
   inline SDL_Renderer* GetRenderer() { return renderer; };
};

} // namespace engine

#endif // ENGINE_RENDERMANAGER_HPP