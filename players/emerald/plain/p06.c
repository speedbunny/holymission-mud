inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A grassy plain";

  long_desc="You are at the edge of a grassy plain.  The grassland " +
            "extends further to the north, east, and west.  To the " +
            "south begins the dark and thick Ilkin Forest.  Far to the north "+
            "rise the snow-capped peaks of tall grey mountains.  Near the " +
            "edge of the forest is a purple bush to which the butterflies " +
            "are flocking.\n";

  dest_dir=({"/players/emerald/plain/p15","north",
             "/players/emerald/plain/p07","east",
             "/players/emerald/plain/p05","west",
             "/players/emerald/plain/p16","northeast",
             "/players/emerald/plain/p14","northwest",
           });

  items=({"plain","A flat area of grassland",
          "grassland","Long stems of grass rippling in the breeze",
          "forest","An evil forest of ill-repute",
          "peaks","Sharp jagged peaks outlined against the sky",
          "mountains","High grey mountains",
          "bush","A beautiful bush with long spikes of purple flowers",
          "butterflies","A multitude of gaily coloured butterflies",
        });

  clone_list=({
    1,3,"butterfly","obj/monster", ({
      "set_name","butterfly",
      "set_race","insect",
      "set_level",5,
      "set_short","A brightly coloured butterfly",
      "set_long","A delicate and graceful butterfly.\n",
      "add_money",50,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
