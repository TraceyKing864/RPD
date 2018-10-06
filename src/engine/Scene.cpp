#include "Scene.hpp"

namespace engine {

Scene::Scene() : physics_engine_(physics::PhysicsCore::GetInstance()),
      actors_(std::make_shared<std::vector<std::unique_ptr<rpd::Actor>>>()),
      stage_(std::make_shared<rpd::Stage>(640, 480)) {
   actors_->push_back(
      std::move(std::make_unique<rpd::Actor>(40, 40, 0, 0)));

   physics_engine_.Initialize(actors_, stage_);
}

Scene::~Scene() {

}

void Scene::HandleInput(std::queue<InputData> input_data) {
   // lol events
   while(!input_data.empty()) {
      (*actors_)[0]->ReceiveInput(input_data.front());
      input_data.pop();
   }
}

void Scene::UpdateAll(unsigned int ticks) {
   for(auto &object : *actors_) {
      object->Update(ticks);
   }
   physics_engine_.CheckCollisions();
}

void Scene::RenderAll() {
   // CURRENTLY RENDERS IN ARBITRARY ORDER.
   for(auto &object : *actors_) {
      object->Render();
   }
}

} // namespace engine