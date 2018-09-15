#ifndef ENGINE_RENDERMANAGER_HPP
#define ENGINE_RENDERMANAGER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace engine {

class RenderManager {
public:
   static RenderManager& GetInstance();
   // static void Destroy();
   
   // If this functionality remains here it could be part of the 'Init/Config' functionality
   void LoadTextures(const std::vector<std::string>& file_names);

   void ClearRenderer();
   void Render(std::string texture_id, SDL_Rect* src, SDL_Rect* dest);
   void SceneToScreen(); // TODO: maybe call this PushFrame() or something?

   //inline SDL_Renderer* GetRenderer() { return renderer_.get(); };

private:
   RenderManager();
   ~RenderManager();
   RenderManager(const RenderManager&) = delete;
   RenderManager& operator=(const RenderManager&) = delete;

   void Scale();

   SDL_Window* window_;
   SDL_Renderer* renderer_;
   std::map<std::string, SDL_Texture*> loaded_textures_;
};

} // namespace engine

#endif // ENGINE_RENDERMANAGER_HPP
