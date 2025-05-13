inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A grassy plain";


  long_desc="Grass surrounds you on three sides in this flat open plain.  " +
            "Mountains rise to the north, dominating the landscape with " +
            "their snow-capped peaks.  The long grass ripples and bends " +
            "in the breeze, glinting gold in the sunlight.  The dark " +
            "green leaves of a clump of white yarrow contrast sharply " +
            "with the grass.  To the south is the edge of the dread " +
            "Ilkin Forest, noted for its evil spirits.\n";

  dest_dir=({"/players/emerald/plain/p14","north",
             "/players/emerald/plain/p06","east",
             "/players/emerald/plain/p04","west",
             "/players/emerald/plain/p15","northeast",
             "/players/emerald/plain/p13","northwest",
             "/players/emerald/plain/p02","southwest",
           });

  items=({"grass","Tall ripe grass",
          "plain","A large area of grassland",
          "mountains","Tall peaks which break up the skyline",
          "peaks","Dark greay peaks capped with snow",
          "leaves","Dark green feathery leaves of yarrow",
          "yarrow","Tall stems of white flowers",
          "forest","The evil and thick Ilkin Forest",
        });

  clone_list=({
    1,1,"hawk","obj/monster", ({
      "set_name","red-tailed hawk",
      "set_alias","hawk",
      "set_race","bird",
      "set_level",17,
      "set_aggressive",1,
      "set_wc",13,
      "add_money",400,
      "set_short","A sharp-eyed red-tailed hawk",
    }),
  });

  ::reset();
  replace_program("/room/room");

}
