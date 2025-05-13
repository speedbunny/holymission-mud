inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="Under the shadow of the mountains";
  long_desc="This is the farthest northern corner of the grassy plain.  " +
            "Mountains form a barrier to the north and east, their snow-" +
            "capped peaks reminding you that summer ephemeral.  Across " +
            "the waving grass, to the south, stands the dark treeline of " +
            "the deep Ilkin Forest.\n";

  dest_dir=({"/players/emerald/plain/p25","south",
             "/players/emerald/plain/p32","west",
             "/players/emerald/plain/p26","southeast",
             "/players/emerald/plain/p24","southwest",
           });

  items=({"corner","The plain is blocked by the mountains",
          "plain","A vast flat area of grassland",
          "mountains","Silent grey mountains",
          "barrier","The mountains cannot be climbed",
          "peaks","They are hidden beneath a blanket of snow",
          "grass","It ripens in the summer sunlight",
          "treeline","The edge of the Ilkin Forest",
          "forest","Oh, the rumours of evil from that forest..",
        });

  clone_list=({
    1,1,"eagle","obj/monster", ({
      "set_name","golden eagle",
      "set_alias","eagle",
      "set_race","bird",
      "set_level",20,
      "set_wc",10,
      "add_money",700,
      "set_short","A golden eagle",
      "set_long","A free and wild golden eagle.\n",
    }),
  });

  ::reset();
  replace_program("/room/room");

}
