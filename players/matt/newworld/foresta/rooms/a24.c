inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(-2);
  short_desc = "Evil Place";
  long_desc =
    "    Here the evil and the darkness seem to pulsate and radiate;\n" +
    "they stem from the chill air in this place. Waves of unbearably\n" +
    "terrible images and sensations flood your body and soul, and\n" +
    "you struggle to keep your footing. Even the trees seem sinister,\n" +
    "jutting branches at you tauntingly. You have an overwhelming\n" +
    "urge to flee.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a23", "east",
  });

  items = ({
    "darkness", "A blackness so thick you can almost feel it",
    "trees", "Wasted away, the trees seem to move with another life",
    "branches", "Hanging low, the branches tear at you as you move",
    "evil", "You can almost see the evil in the air here",
  });

  clone_list = ({
    1, 1, "dragon", NWFORESTA + "monsters/blackdragon", 0
  });
  ::reset(arg);
  replace_program("/room/room");
}
