#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="This room has all the classic characteristics of a tomb.  It is "+
            "still, silent, and very, very frightening.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h14", "west",
           });


  clone_list=({
    1,1,"wight","/players/emerald/dungeon/monster/wight",0,
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
