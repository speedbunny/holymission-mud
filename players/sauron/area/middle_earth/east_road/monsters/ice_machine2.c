inherit "obj/monster"; 

#include "/players/sauron/defs.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    id("ice_machine");
    load_chat(20,({
      "A lump of ice floats by, almost sweeping you away.\n", 
    }));
  }
}
