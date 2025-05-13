inherit "/room/room";

#include <room_defs.h>

int move(string str) {
  if(!str)
    str = query_verb();

  if(str=="west" && present("tunnel dwarf", TO) && TP->INV < 15) {
    write("The tunnel dwarf blocks your way westward.\n");
    return 1;
  }
  return ::move(str);
}

void reset(int arg){
  clone_list = ({
    1, 1, "tunnel dwarf", "obj/monster", ({
      "set_name", "A tunnel dwarf",
      "set_level", 10,
      "set_race", "dwarf",
      "set_alias_list", ({ "tunnel dwarf", "guard" }),
      "set_size", 2,
      "set_al", -100,
      "set_short", "A tunnel dwarf",
      "set_long", "A short and sturdy tunnel dwarf standing guard.\n",
      "set_wc", 5,
      "set_ac", 1,
    }),
    -1, 1, "battleaxe", "obj/weapon", ({
      "set_name", "battleaxe",
      "set_wc", 14,
      "set_short", "A dwarven battleaxe",
      "set_long", "This axe is a finely crafted item.\n",
      "set_alias_list", ({ "axe", "dwarven battleaxe" }),
      "set_weight", 4,
      "set_value", 250,
    })
  });

  ::reset(arg);
  if(arg) return;

  set_light(0);
  short_desc = "Tunnel";
  long_desc =
    "In a tunnel in the mines.\n";

  items = ({
    "tunnel", "It is dark",
  });

  dest_dir=({
    MINES + "tunnel17", "north",
    MINES + "tunnel15", "west",
  });
}

