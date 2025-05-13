inherit "/room/room";

#include "/room/room_defs.h"

int move(string str) {
  if(!str)
    str = query_verb();
  switch(str) {
    case "north" :
      if(!TP->IMM && TP->INV < 10) {
        if(present("orc", TO)) {
        write("An orc bars your way.\n");
        return 1;
      }
      }
  }
  return ::move(str);
}

void reset(int arg) {
  clone_list = ({
    1, 8, "orc", "obj/orc", 0,
  });

  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc="The orc fortress";
  long_desc=
    "This is the local strong point of the orcs. There is an " +
    "entrance to a small room to the north.\n";

  dest_dir=({
    ORC_VALLEY + "orc_treasure", "north",
    ORC_VALLEY + "orc_vall", "south",
  });

  items=({
    "point", "It seems this place could flood with orcs",
    "entrance", "It's beautiful, at least, for orc standards",
    "room", "It looks very important",
  });
}

