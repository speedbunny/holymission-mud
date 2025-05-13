inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The edge of the plain";
  long_desc="Mountains surround this section of the plain on the north " +
            "and west, forming an impenetrable barrier in those " +
            "directions.  Further to the east and south, the grassland " +
            "flows out evenly.  The wind causes the grass to move in " +
            "waves which glisten in the bright sunlight.  The raucous " +
            "cry of a crow grates irritatingly on your ears.\n";

  dest_dir=({"/players/emerald/plain/p30","east",
             "/players/emerald/plain/p21","south",
             "/players/emerald/plain/p22","southeast",
             "/players/emerald/plain/p20","southwest",
           });

  items=({"mountains","High, cold, unclimbable mountains",
          "plain","A vast area of waving grass",
          "section","There is quite a bit more to the plain",
          "barrier","There is no way to climb the mountains",
          "grassland","The grass ripens to gold in the sunlight",
          "grass","Tall stems on grass",
          "waves","The grass stems bend in a wave-like motion",
          "sunlight","The light source",
        });

  clone_list=({
    1,1,"crow","obj/monster", ({
      "set_name","crow",
      "set_race","bird",
      "set_short","A black crow",
      "set_long","An annoying black crow cawing angrily at you.\n",
      "set_level",7,
      "set_wc",4,
      "add_money",70,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
