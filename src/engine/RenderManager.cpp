#include "RenderManager.hpp"

namespace engine {

RenderManager::RenderManager() {
   if(SDL_Init(SDL_INIT_VIDEO) < 0) {
      throw(std::string("Could not init SDL: ") + SDL_GetError());
   }
   std::string title = "RPD Version 0.0.0.0.0.0.0.0.2";
   int width = 640;
   int height = 480;
   bool fullscreen = false;
   int flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN;
   if (fullscreen)
      flags = flags | SDL_WINDOW_MAXIMIZED;

   window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
             SDL_WINDOWPOS_CENTERED, width, height, flags);

   if(window_ == nullptr) {
      throw(std::string("Couldn't make a window: ")+SDL_GetError());
   }

   renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);

   if(renderer_ == nullptr)
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

void RenderManager::LoadTextures(const std::vector<std::string>& file_names) {
   for(auto &file_name : file_names) {
      SDL_Texture* temp_texture;
      SDL_Surface* loaded_surface = IMG_Load(file_name.c_str());
	   if( loaded_surface == NULL ) {
         printf( "Unable to load image! SDL_image Error: %s\n", IMG_GetError() );
      } else {
         SDL_SetColorKey( loaded_surface, SDL_TRUE, SDL_MapRGB( loaded_surface->format, 0, 0xFF, 0xFF ) );
         temp_texture = SDL_CreateTextureFromSurface(renderer_, loaded_surface);
	   	if( temp_texture == NULL )
	   	{
	   		printf( "Unable to create texture! SDL Error: %s\n", SDL_GetError() );
	   	}
	   	SDL_FreeSurface( loaded_surface );
      }
      loaded_textures_.insert(std::make_pair(file_name, temp_texture));
   }
}

void RenderManager::ClearRenderer() {
   SDL_RenderClear(renderer_);
}

void RenderManager::Render(std::string texture_id, SDL_Rect* src, SDL_Rect* dest) {
   SDL_RenderCopy(renderer_, loaded_textures_[texture_id], src, dest);
}

void RenderManager::SceneToScreen() {
   Scale();
   SDL_RenderPresent(renderer_);
}

void RenderManager::Scale() {
   const int viewport_width = 640;
   const int viewport_height = 480;
   SDL_RenderSetLogicalSize(renderer_, viewport_width, viewport_height);
}

} // namespace engine
