inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="Entrance to the inner garden";
  long_desc="You have arrived in the royal garden.  The beauty of this " +
            "place overwhelms you. Flowers in different colours, shapes, " +
            "and sizes grow here, including many unknown varieties.  The " +
            "gardener does really good work here. The golden hedge " +
            "continues to the west.\n";

  items=({"flowers", "As you look around you notice roses, daisies, baby "+
                     "breath, lilies, and much, much more",
           "hedge","The golden hedge keeps out the wild animals so they "+
                   "won't eat the flowers",
           "garden","A riotious profusion of flowers",
        });

  dest_dir=({"/players/emerald/garden/gar_cor3", "north",
             "/players/emerald/garden/garden2", "south",
             "/players/emerald/garden/garden4", "east",
           });

  clone_list=({
    1,2,"rabbit","obj/monster", ({
      "set_name","rabbit",
      "set_short","A rabbit",
      "set_long","This rabbit is looking around for fresh vegetables to eat.\n",
      "set_race","mammal",
      "set_level",1,
      "set_al",-50,
      "set_wc",2,
      "set_ac",2,
      "add_money",50,
    }),
  });

  ::reset();
  replace_program("/room/room");
}
