inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Bright Forest";
  long_desc =
    "    This is a crude, narrow path winding through the forest,\n" +
    "leading northwest and northeast. Nature is omnipresent and\n" +
    "flourishing in Her splendor; this place is beautiful. A calm\n" +
    "unlike any you have ever felt settles over you as you gaze\n" +
    "about in contented happiness at the scene before you.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b12", "northwest",
    NWFORESTB + "rooms/b17", "northeast",
  });

  items = ({
    "forest", "A beatiful section of the forest",
    "path", "An overgrown path",
    "scene", "Your mind eagerly drinks in the scene before you",
  });
  replace_program("/room/room");
}
