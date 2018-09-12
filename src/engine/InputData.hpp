#ifndef ENGINE_INPUTDATA_HPP
#define ENGINE_INPUTDATA_HPP

namespace engine {

enum InputType {
   QUIT,
   KEY_LEFT,
   KEY_RIGHT,
   KEY_UP,
   KEY_DOWN,
   KEY_SPACE,
   JOYSTICK
   // IDK probably more stuff to go here and/or these need to be renamed
};

struct InputData {
   // The type of the input, these will roughly map to SDL_event.type
   InputType input_type;
   // The value of the input (can be on/off for button or scalar for sticks)
   double input_value;
   // The input device the input came from
   int input_source;
};

} // namespace engine

#endif // ENGINE_INPUTDATA_HPP