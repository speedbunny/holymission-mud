#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="The only sound that greets your ears in this utter darkness " +
            "is a long, slow, scraping sound.  The instigator of that sound " +
            "is probably very happy to see you.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h15","west",
           });


  clone_list=({
    1,1,"spider","/players/emerald/dungeon/monster/spider",0,
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
