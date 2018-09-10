#ifndef ENGINE_RENDERMANAGER_HPP
#define ENGINE_RENDERMANAGER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <vector>

namespace engine {

class RenderManager {
public:
   static RenderManager& GetInstance();
   // static void Destroy();

   void LoadTextures(std::vector<std::string> file_names);

   void ClearRenderer();
   void Render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest);
   void SceneToScreen(); // TODO: maybe call this PushFrame() or something?

   inline SDL_Renderer* GetRenderer() { return renderer_; };

private:
   SDL_Window* window_;
   SDL_Renderer* renderer_;

   RenderManager();
   ~RenderManager();
   RenderManager(const RenderManager&) = delete;
   RenderManager& operator=(const RenderManager&) = delete;

   void Scale();
};

} // namespace engine

#endif // ENGINE_RENDERMANAGER_HPP
