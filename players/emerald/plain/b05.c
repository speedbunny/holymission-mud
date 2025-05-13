inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The beach next to the waterline";
  long_desc="You are standing on a wide sandy beach just out of reach of " +
            "the breaking waves.  All sorts of interesting objects have " +
            "been tossed upon the beach from the movement of the water.  " +
            "Bits of corals and tendrils of seaweed partially cover a few " +
            "wet rocks.\n";

  dest_dir=({"/players/emerald/plain/b07","north",
             "/players/emerald/plain/b03","south",
             "/players/emerald/plain/b04","west",
             "/players/emerald/plain/b06","northwest",
             "/players/emerald/plain/b02","southwest",
           });

  items=({"beach","A gently sloping region of sand",
          "waves","Foamy waves which crash on to the sand",
          "objects","An assortment of shells, pebbles, and other oddments",
          "corals","Pink, grey, and blue coral chunks",
          "seaweed","Bladderwrack and kelp",
          "rocks","They are still wet",
        });

  clone_list=({
    1,1,"starfish","obj/monster", ({
      "set_name","starfish",
      "set_race","fish",
      "set_short","An orange starfish",
      "set_long","A small starfish clinging to a rock.\n",
      "set_level",7,
      "add_money",40,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
