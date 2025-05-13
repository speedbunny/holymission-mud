#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="A sense of dread overcomes you as you enter the cell.  " +
            "It could just be from the inky blackness.  Or it could " +
            "be from the fact that a vicious ogre seems to have broken " +
            "its chains and is ready to slit your throat.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h1","west",
           });

  items=({"cell", "Dark, dirty, moldy, the basic dungeon cell",
          "chains", "Broken chains hanging from the wall.  From " +
                    "the size of them, the creature that broke them " +
                    "must be pretty darn strong",
        });

  clone_list=({
    1,1,"ogre","/players/emerald/dungeon/monster/ogre",0,
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
