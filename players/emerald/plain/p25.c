inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A grassy plain";
  long_desc="The rushing of the breeze past your ears is the only sound " +
            "which can be heard in this vast, grassy plain.  It ruffles the "+
            "grass stems, churning them into waves which travel far out " +
            "into the plain.  The ridge of mountains to the north takes " +
            "a southward bend here.  The craggy sides are unclimbable at " +
            "this point.\n";

  dest_dir=({"/players/emerald/plain/p33","north",
             "/players/emerald/plain/p15","south",
             "/players/emerald/plain/p26","east",
             "/players/emerald/plain/p24","west",
             "/players/emerald/plain/p16","southeast",
             "/players/emerald/plain/p32","northwest",
             "/players/emerald/plain/p14","southwest",
           });

  items=({"plain","An immense flat area of grassland",
          "stems","They are turning golden in the sunlight",
          "grass","Tall plants of grass",
          "waves","The grass bends and rises in waves",
          "ridge","A line of mountains which towers over the plain",
          "mountains","They rise silent and cold over the plain",
          "sides","A jumbled mass of planes and fractures",
        });

  clone_list=({
    1,1,"antelope","obj/monster", ({
      "set_name","antelope",
      "set_race","ruminant",
      "set_short","An imposing antelope",
      "set_long","An old, imposing antelope munching the grass shoots.\n",
      "set_level",20,
      "add_money",300,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
