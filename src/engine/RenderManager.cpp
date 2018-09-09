#include "RenderManager.hpp"

namespace engine {

RenderManager::RenderManager() {
   if(SDL_Init(SDL_INIT_VIDEO) < 0) {
      throw(std::string("Could not init SDL: ") + SDL_GetError());
   }
   std::string title = "RPD Version 0.00000001";
   int width = 640;
   int height = 480;
   bool fullscreen = false;
   int flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN;
   if (fullscreen)
      flags = flags | SDL_WINDOW_MAXIMIZED;

   window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, 
             SDL_WINDOWPOS_CENTERED, width, height, flags);

   if(window == NULL) {
      throw(std::string("Couldn't make a window: ")+SDL_GetError());
   }

   renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

   if(renderer == NULL) 
      throw std::string("Error in RenderManager(): NULL renderer.");
}

RenderManager::~RenderManager() {
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
}

RenderManager& RenderManager::GetInstance() {
   static RenderManager singleton;
   return singleton;
}

void RenderManager::Render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest) {
   SDL_RenderCopy(renderer, texture, src, dest);
}

} // namespace engine