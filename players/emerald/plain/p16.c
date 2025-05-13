inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="An open grassy plain";
  long_desc="The only sound out in the midst of the plain is that of the " +
            "grass brushing against each other as the wind rushes by.  The "+
            "high, silent peaks of the mountains to the north stand silent "+
            "guard over the open plain.  Away to the south, the dark trees "+
            "of the Ilkin Forest lurk in black contemplation over the " +
            "uneasy boundary between forest and plain.\n";

  dest_dir=({"/players/emerald/plain/p26","north",
             "/players/emerald/plain/p07","south",
             "/players/emerald/plain/p17","east",
             "/players/emerald/plain/p15","west",
             "/players/emerald/plain/p27","northeast",
             "/players/emerald/plain/p25","northwest",
             "/players/emerald/plain/p08","southeast",
             "/players/emerald/plain/p06","southwest",
            });

  items=({"plain","An immense flat area of grassland",
          "grass","Long stems of ripening grass",
          "peaks","High snow-capped mountain peaks",
          "mountains","High, craggy, grey mountains",
          "trees","Their leaves and branches are unaffected by the breeze",
          "forest","It contains ancient evil",
        });

  clone_list=({
    1,1,"skunk","obj/monster", ({
      "set_name","skunk",
      "set_race","rodent",
      "set_short","A small black skunk",
      "set_long","A terrified black skunk.\n",
      "set_level",8,
      "add_money",30,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
