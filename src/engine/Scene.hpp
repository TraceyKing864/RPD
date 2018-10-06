#ifndef ENGINE_SCENE_HPP
#define ENGINE_SCENE_HPP

#include "InputData.hpp"
#include "Renderable.hpp"
#include "RenderManager.hpp"
#include "../physics/PhysicsCore.hpp"
#include "../rpd/Actor.hpp"
#include "../rpd/Stage.hpp"
#include <queue>

namespace engine {

class Scene {
public:
   Scene();
   ~Scene();

   void HandleInput(std::queue<InputData> input_data);
   void UpdateAll(unsigned int ticks);
   void RenderAll();

private:
   physics::PhysicsCore& physics_engine_; // = physics::PhysicsCore::GetInstance();

   std::shared_ptr<std::vector<std::unique_ptr<rpd::Actor>>> actors_;
   std::shared_ptr<rpd::Stage> stage_;
};

} // namespace engine

#endif // ENGINE_SCENE_HPP
