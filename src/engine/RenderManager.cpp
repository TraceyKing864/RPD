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

   window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, 
             SDL_WINDOWPOS_CENTERED, width, height, flags);

   if(window_ == NULL) {
      throw(std::string("Couldn't make a window: ")+SDL_GetError());
   }

   renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);

   if(renderer_ == NULL) 
      throw std::string("Error in RenderManager(): NULL renderer.");
}

RenderManager::~RenderManager() {
   SDL_DestroyRenderer(renderer_);
   SDL_DestroyWindow(window_);
   SDL_Quit();
}

RenderManager& RenderManager::GetInstance() {
   static RenderManager singleton;
   return singleton;
}

void RenderManager::ClearRenderer() {
   SDL_RenderClear(renderer_);
}

void RenderManager::Render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest) {
   SDL_RenderCopy(renderer_, texture, src, dest);
}

void RenderManager::SceneToScreen() {
   Scale();
   SDL_RenderPresent(renderer_);
}

void RenderManager::Scale() {
   const int viewport_width = 320;
   const int viewport_height = 240;
   SDL_RenderSetLogicalSize(renderer_, viewport_width, viewport_height);
}

} // namespace engine
