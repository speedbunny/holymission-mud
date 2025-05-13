inherit "/room/room";

#include "/players/redsexy/guild/guilddefs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Narrow Passage";
  long_desc =
    "    This is a very dim passage cut by living hands into the rock\n" +
    "of the mountain. To the northeast the passage continues deeper\n" +
    "in towards darker regions; you can see the bright light of day\n" +
    "to the west.\n";

  dest_dir = ({
    "players/redsexy/guild/rooms/passage02", "northeast",
    "players/matt/newworld/road/rooms/road17", "west",
  });

  items = ({
    "light", "Bright light streaming in from an opening to the west",
    "opening", "It leads outside",
    "passage", "The passage is dark and musty",
    "rock", "The rough grey rock of the mountain",
    "mountain", "You stand within a man-made passage in the mountain",
  });
  replace_program("/room/room");
}
