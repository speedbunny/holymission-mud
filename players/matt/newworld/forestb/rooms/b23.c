inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Bright Forest";
  long_desc =
    "    The path here leads east into a small well-lit clearing\n" +
    "and northwest back towards the crossroads. The forest is so\n" +
    "lush, so thick, so untouched by mankind that your spirit\n" +
    "cries out in sheer joy, communing with nature in a way that\n" +
    "it never has before.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b24", "east",
    NWFORESTB + "rooms/b22", "northwest",
  });

  items = ({
    "forest", "The forest is breathtaking",
    "path", "The path is old and overgrown",
    "clearing", "You can see a bright clearing to the east",
  });
  replace_program("/room/room");
}
