inherit "/room/room";

#include "/players/redsexy/guild/guilddefs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Dark Passage";
  long_desc =
    "    The weight of the ages is almost palpable here, pushing down\n" +
    "upon you heavily. You sense the very old, very mysterious, very\n" +
    "powerful aura that surrounds this place as you look about.\n" +
    "    To the north you can barely make out a dead end, and to the\n" +
    "south lies the way out.\n";

  dest_dir = ({
    "players/redsexy/guild/rooms/passage04", "north",
    "players/redsexy/guild/rooms/passage02", "south",
  });

  items = ({
    "dead end", "The light is very poor, but you can see no exits",
    "passage", "A dark passage deep within the mountain",
  });
  replace_program("/room/room");
}
