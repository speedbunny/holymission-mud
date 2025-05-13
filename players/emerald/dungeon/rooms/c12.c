#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="This is a tiny cell.  You almost hit your head on " +
            "the ceiling.  You can reach the opposite walls is you " +
            "stretch out your arms.  But it does have an occupant, " +
            "and that occupant doesn't seem all too happy to see you.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h4","southeast",
           });

  items=({"cell", "A normal moldy, dirty, cramped cell",
          "walls", "Mold-encrusted stone walls",
          "ceiling","Moldy and quite repulsive",
        });

  clone_list=({
    1,1,"orc","/players/emerald/dungeon/monster/orc",0,
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
