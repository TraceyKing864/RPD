#ifndef ENGINE_INPUTDATA_HPP
#define ENGINE_INPUTDATA_HPP

namespace engine {

enum InputType {
   QUIT,
   MOVE_LEFT,
   MOVE_RIGHT,
   MOVE_UP,
   MOVE_DOWN,
   MOVE_SPACE,
   // should this exist or just be abstracted to a direction?
   JOYSTICK
   // IDK probably more stuff to go here and/or these need to be renamed
};

struct InputData {
   // The type of the input, these will roughly map to SDL_event.type
   InputType input_type;
   // The value of the input (can be on/off for button or scalar for sticks)
   // NOTE: currently using this to signify key-up vs key-down
   double input_value;
   // The input device the input came from
   int input_source;
};

} // namespace engine

#endif // ENGINE_INPUTDATA_HPP