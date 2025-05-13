#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="A slight breeze brushes your face, sending a terrible chill " +
            "through your body.  Something in your mind tells you to turn " +
            "around and run for daylight!\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h10", "south",
           });

  clone_list=({
    1,1,"welem","/players/emerald/dungeon/monster/welem",0,
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
