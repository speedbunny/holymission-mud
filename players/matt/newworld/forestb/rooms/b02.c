inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Bright Forest";
  long_desc =
    "    You cannot help but notice how open and airy these woods\n" +
    "are. The trees, though close enough together to enclose sections\n" +
    "of the forest, are spaced far enough apart to allow unhindered\n" +
    "passage between them. Sunlight filters down in shimmering beams\n" +
    "through their branches, speckling the forest floor with patches\n" +
    "of brightness.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b01", "west",
    NWFORESTB + "rooms/b03", "south",
    NWFORESTB + "rooms/b07", "southeast",
  });

  items = ({
    "forest", "The forest is very airy here",
    "trees", "Gnarled old trees, standing strong through the ages",
    "woods", "Calm, peaceful woods",
    "sunlight", "Filtered patches of light showing through the branches",
    "beams", "Brilliant sunbeams",
    "sunbeams", "Sunlight streaming down through the canopy overhead",
    "branches", "The branches form a sort of canopy over your head",
    "patches", "Patches of light on the forest floor",
    "canopy", "A mesh of branches above your head",
    "floor", "The forest floor",
  });
  replace_program("/room/room");
}
