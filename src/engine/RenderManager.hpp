#ifndef ENGINE_RENDERMANAGER_HPP
#define ENGINE_RENDERMANAGER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

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
   void Render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest);
   inline SDL_Renderer* GetRenderer() { return renderer; };
};

} // namespace engine

#endif // ENGINE_RENDERMANAGER_HPP