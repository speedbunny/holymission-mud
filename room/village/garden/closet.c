inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  set_light(1);
  short_desc = "Chantilly's closet";
  long_desc =
    "This room appears to be a closet but is huge in itself. There "+
    "are clothes and boxes piled in here, and a bed in the corner.\n";

  items = ({
    "clothes", "They are women's clothes, and probably are Chantilly's",
    "boxes", "They contain clothes, hats, shoes and other things",
    "bed", "Why would a bed be in the closet? It is hard to say",
  });

  dest_dir = ({
    VILLAGE_GARDEN + "bedroom", "south",
  });

  ::reset(arg);
  replace_program("/room/room");
}

