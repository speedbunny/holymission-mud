inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The end of the rocky coastline";
  long_desc="You have reached the end of the rocky coastline.  To the " +
            "north, the mountains run straight into the sea, with no " +
            "buffering coastline between them and the endless sea.  The " +
            "high cliffs to the west are quite sheer, although you can " +
            "sea the nest of some sort of bird perched high on a ledge.\n";

  dest_dir=({"/players/emerald/plain/b22","south",
           });

  items=({"end","The coastline only goes further to the south",
          "coastline","The area between the mountains and the sea",
          "mountains","High, silent, grey mountains",
          "sea","A deep blue sea",
          "cliffs","High, sheer cliffs that cannot be climbed",
          "nest","It is difficult to see, perched so high on the cliff",
          "ledge","A horizontal face of the cliff",
        });

  clone_list=({
    1,1,"bird","obj/monster", ({
      "set_name","albatross",
      "set_race","bird",
      "set_level",20,
      "set_short","A huge white albatross",
      "set_long","A white albatross.  It has a vast wingspan.\n",
      "add_money",500,
      "set_wc",15,
      "set_ac",15,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
