#include "mroom.h"

reset(arg) {
    int i;
    if(!present("shiriff"))
	set_light(1);
    short_desc="Sheriff road";
    long_desc=
    "You are at a road where it goes east and west. There is a small\n"+
    "house where shiriffss are keeping watch from. This is the local\n"+
    "sheriff outpost.\n";
    dest_dir = ({
      SHIRE+"/road2", "west",
      SHIRE+"/sheriff2", "east",
    });
    clone_list = ({1,6, "shiriff", "obj/monster", 
    ({"set_name", "shiriff", "set_race", "hobbit", "set_long", "This is a shiriff that's in charge of taking care of the Shire.\n"+
      "As a lawman, he wears a Robin Hood style hat with a feather in\n"+
      "it and carries a shortsword. Right now it looks like he's eyeing\n"+
      "you and trying to gauge just how tough you are and what your business\n"+
      "is here.\n",
      "set_gender", 1, "set_level", 4, "set_hp", 70, "set_al", 150, 
      "set_size", 2
    }),
      -1,1, "sword", "obj/weapon", ({
      "set_name", "short sword", "set_alias", "sword", "set_short", "Short sword",
      "set_long", "A short sword used by the shiriffs of the Shire. It is a small\n"+
      "but well balanced sword.\n",
      "set_class", 8, "set_weight", 2, "set_value", 40
    }),
    });
    ::reset();
    replace_program("/room/room");
}

