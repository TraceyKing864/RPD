#include "Scene.hpp"

namespace engine {

Scene::Scene() {
   game_objects_.push_back(
      std::move(std::make_unique<Renderable>("../assets/archer.png", 0, 0)));
   game_objects_.back()->SetScale(4.0);
}

Scene::~Scene() {

}

/* void Scene::HandleEvent(const SDL_Event& e) {
   // lol events
} */

void Scene::UpdateAll(unsigned int ticks) {
   for(auto &object : game_objects_) {
      object->Update(ticks);
   }
}

void Scene::RenderAll() {
   // CURRENTLY RENDERS IN ARBITRARY ORDER.
   for(auto &object : game_objects_) {
      object->Render();
   }
}

} // namespace engine