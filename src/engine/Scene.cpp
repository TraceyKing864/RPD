#include "Scene.hpp"

namespace engine {

Scene::Scene() {
   SDL_Texture* temp_texture;
   SDL_Surface* loaded_surface = IMG_Load("../assets/archer.png");
	if( loaded_surface == NULL ) {
      printf( "Unable to load image! SDL_image Error: %s\n", IMG_GetError() );
   } else {
      SDL_SetColorKey( loaded_surface, SDL_TRUE, SDL_MapRGB( loaded_surface->format, 0, 0xFF, 0xFF ) );
      temp_texture = SDL_CreateTextureFromSurface(RenderManager::GetInstance().GetRenderer(), loaded_surface);
		if( temp_texture == NULL )
		{
			printf( "Unable to create texture! SDL Error: %s\n", SDL_GetError() );
		}
		SDL_FreeSurface( loaded_surface );
   }
   
   thing_to_render_ = new Renderable(temp_texture, 0, 0);
}

Scene::~Scene() {

}

void Scene::HandleEvent(const SDL_Event& e) {
   // lol events
}

void Scene::Update(unsigned int i) {
   thing_to_render_->Update(i);
}

void Scene::RenderAll() {
   thing_to_render_->Render();
}

} // namespace engine