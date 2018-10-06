#ifndef PHYSICS_PHYSICSCORE_HPP
#define PHYSICS_PHYSICSCORE_HPP

#include <memory>
#include <queue>
#include <string>
#include <vector>
#include "../rpd/Actor.hpp"
#include "../rpd/Stage.hpp"

namespace physics {

class PhysicsCore {
public:
   static PhysicsCore& GetInstance();
   // static void Destroy();
   void Initialize(std::shared_ptr<std::vector<std::unique_ptr<rpd::Actor>>> actors,
         std::shared_ptr<rpd::Stage> stage);

   void CheckCollisions();

private:
   PhysicsCore();
   ~PhysicsCore();
   PhysicsCore(const PhysicsCore&) = delete;
   PhysicsCore& operator=(const PhysicsCore&) = delete;

   int x_min_ = 0;
   int y_min_ = 0;
   int x_max_;
   int y_max_;

   std::shared_ptr<std::vector<std::unique_ptr<rpd::Actor>>> actors_;
   std::shared_ptr<rpd::Stage> stage_;
};

} // namespace physics

#endif // PHYSICS_PHYSICSCORE_HPP
