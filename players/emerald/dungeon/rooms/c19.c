#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="There are claw marks on the walls.  They run in verticle " +
            "grooves on the basalt walls.  The creature that made them " +
            "is probably not terribly friendly.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h19", "south",
           });

  items=({"marks", "Deep grooves in the walls",
          "grooves","Formed by scratching claws on the walls",
          "walls", "They are made of basalt",
        });

  clone_list=({
    1,1,"werewolf","/players/emerald/dungeon/monster/wwolf",0,
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
