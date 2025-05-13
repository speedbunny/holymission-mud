inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The northern edge of the plain";
  long_desc="You are standing in the midst of a sea of grass at the " +
            "northern edge of a vast plain.  Cold and silent mountains " +
            "rise up sharply to the north, forming the boundary of the " +
            "plain.  Sunlight glistens off of their snow-capped peaks.  " +
            "Far across the waving grass to the south lies the ancient " +
            "evil of the Ilkin Forest.\n";

  dest_dir=({"/players/emerald/plain/p28","east",
             "/players/emerald/plain/p26","west",
             "/players/emerald/plain/p17","south",
             "/players/emerald/plain/p18","southeast",
             "/players/emerald/plain/p16","southwest",
           });

  items=({"sea","The grass is as unending as the sea",
          "grass","Long stems of grass",
          "plain","An open area of grassland",
          "mountains","High grey mountains",
          "boundary","None can cross it",
          "peaks","They are blanketed in snow",
          "forest","The ancient, dreaded Ilkin Forest",
        });

  clone_list=({
    1,1,"coyote","obj/monster", ({
      "set_name","coyote",
      "set_race","canine",
      "set_level",14,
      "set_short","A brown coyote",
      "set_long","A cunning and bold coyote.\n",
      "add_money",250,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
