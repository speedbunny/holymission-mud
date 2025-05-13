inherit "/room/room";

#include <room_defs.h>

void reset(int arg) {
  set_light(1);
  short_desc = "Chantilly's kitchen";
  long_desc =
    "Chantilly's kitchen is very clean and organised. There appears "+
    "to be everything one would need in a home, including some "+
    "magical items, like a pump that pours water continuously "+
    "when turned on and cooking pots and pans that cook food "+
    "without the need of a fire. There is a large table that "+
    "can sit 8 in here with chairs around it.\n";

  items = ({
    "items", "The magical items include pots and pans and a pump",
    "pump", "It is magical and only need to be pumped once and "+
      "it continues pumping by itself",
    "pots", "The magical pots and pans cook food without the need "+
      "of a fire",
    "pans", "The magical pots and pans cook food without the need "+
      "of a fire",
    "pots and pans", "The magical pots and pans cook food without "+
      "the need of a fire",
    "table", "The table is a sturdy oak table",
    "chairs", "There are eight chairs around the table",
  });

  dest_dir = ({
    VILLAGE_GARDEN + "living_room", "south",
  });

  ::reset(arg);
  replace_program("/room/room");
}

