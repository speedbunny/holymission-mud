#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="As you enter the cell, you become aware of an ancient evil " +
            "presence.  It doesn't seem to like you very much, except " +
            "for the fact that you have become its next meal.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h22", "northeast",
           });

  items=({"walls", "Smooth walls with no visible cracks or seams",
          "floor", "You can't see the floor.  It's covered in bat guano",
        });

  smell="Ah, the wonderful scent of bat guano...";
  clone_list=({
    1,1,"bat","/players/emerald/dungeon/monster/vbat",0,
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
