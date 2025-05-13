#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="It's impossibly damp in here.  And HOT!  Goodness, you'd " +
            "think it would be freezing in here.  But when there's " +
            "firedrake in the cell, things get a bit warm!\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h2","west",
           });

  items=({"cell", "Dark, dirty, moldy, the basic dungeon cell",
        });

  clone_list=({
    1,1,"drake","/players/emerald/dungeon/monster/fdrake",0,
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
