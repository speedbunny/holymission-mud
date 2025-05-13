#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg) {

  if(arg) return;

  set_light(0);

  short_desc="A cell in the dungeon";

  long_desc="As you enter the cell, you feel as if the light breezes of " +
            "springtime are carrying you away, amidst a stench of evil.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/h17", "north",
           });


  clone_list=({
    1,1,"pixie","obj/monster", ({
      "set_name","pixie",
      "set_long","An evil woodland pixie.\n",
      "set_level",13,
      "set_race","fairy",
      "set_alignment",-200,
      "add_money", 120,
    }),
  });

  ::reset();
  replace_program(DOOR_ROOM);

}
