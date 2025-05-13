inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The waterline";
  long_desc="The beach is rather rocky here.  Large chunks of black rocks " +
            "stick up out of the sand.  Behind them, seaweed, shells, and " +
            "pebbles have collected, protected from the action of the " +
            "waves as they retreat back out to sea.  A few sand fleas hop " +
            "over the beach.\n";

  dest_dir=({"/players/emerald/plain/b17","north",
             "/players/emerald/plain/b13","south",
             "/players/emerald/plain/b14","west",
             "/players/emerald/plain/b16","northwest",
             "/players/emerald/plain/b12","southwest",
           });

  items=({"beach","A white sand beach with lots of small rocks on it",
          "chunks","The rocks broke off larger boulders",
          "rocks","They have sharp edges",
          "sand","White grains of coarse sand",
          "seaweed","Mostly kelp and bladderwrack",
          "shells","The former homes of marine animals",
          "pebbles","Small rounded pebbles",
          "sea","A clear blue sea",
          "waves","Long, slow, rolling waves",
          "fleas","Nasty little sand fleas",
        });

  clone_list=({
    1,4,"flea","obj/monster", ({
      "set_name","sand flea",
      "set_race","insect",
      "set_alias","flea",
      "set_level",5,
      "set_short","A nasty sand flea",
      "set_long","An evil sand flea hopping over the beach.\n",
    }),
  });

  ::reset();
  replace_program("/room/room");

}
