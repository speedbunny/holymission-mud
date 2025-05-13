#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="A chill goes up your spine.  You can feel great evil in " +
            "this room, and a pervasive sense of death and despair.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h20", "north",
           });


  clone_list=({
    1,1,"wight","/players/emerald/dungeon/monster/wight",0,
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
