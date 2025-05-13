#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="It's cold in here and you shiver incessantly.  And, " +
            "could that be?!?  Nah...  But it is!  It's SNOW!  " +
            "Well, the cell IS home to a snowman, erm, excuse me, " +
            "a snow-being.  No one has ever gotten close enough to " +
            "it to find out its sex.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h3","east",
           });

  items=({"cell", "It's full of snow!",
          "snow","White particles of frozen water",
        });

  clone_list=({
    1,1,"snowman","/players/emerald/dungeon/monster/hermie",0,
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
