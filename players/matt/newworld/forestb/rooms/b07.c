inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Open Space";
  long_desc =
    "    This space is very open, much like most of this forest.\n" +
    "Passages through the trees lie in many directions, the air\n" +
    "is fresh and clean, and you are revived with a new energy\n" +
    "as you take in the scene before you. Towering elms and oaks\n" +
    "silently withstand the ages even as you watch them.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b12", "east",
    NWFORESTB + "rooms/b03", "west",
    NWFORESTB + "rooms/b08", "south",
    NWFORESTB + "rooms/b02", "northwest",
  });

  items = ({
    "space", "A wide-open wood",
    "trees", "Mighty oaks and elms",
    "forest", "A brightly-lit area",
    "passages", "Openings between trees allowing you to progress further",
    "scene", "A serene, invigorating scene",
    "elms", "Noble elm trees that proudly stand straight and tall",
    "oaks", "Huge ancient oak trees",
  });
  replace_program("/room/room");
}
