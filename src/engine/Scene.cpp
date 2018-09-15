#include "Scene.hpp"

namespace engine {

Scene::Scene() {
   game_objects_.push_back(
      std::move(std::make_unique<rpd::Actor>(0, 0)));
   // game_objects_.back()->SetScale(4.0);
}

Scene::~Scene() {

}

void Scene::HandleInput(InputData input_data) {
   // lol events
}

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