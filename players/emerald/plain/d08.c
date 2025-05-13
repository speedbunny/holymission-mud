inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The end of the dunes";
  long_desc="The mountains encroach on the range of dunes, rising high to " +
            "the north and west.  Further to the east lies another range " +
            "of dunes.  Beyond that, the waves wash peacefully against " +
            "the shore.  Heatwaves shimmer in the air above the dunes, " +
            "in stark contrast with the snow-capped peaks which tower " +
            "above.\n";

  dest_dir=({"/players/emerald/plain/d09","east",
             "/players/emerald/plain/d06","south",
             "/players/emerald/plain/d10","northeast",
             "/players/emerald/plain/d07","southeast",
           });

  items=({"mountains","Sheer grey walls which cannot be scaled",
          "range","A ridge of sand dunes running north and south",
          "dunes","High mounds of white sand",
          "waves","White-crested blue waves",
          "heatwaves","They dance before your eyes",
          "peaks","The snow which covers them looks nice and cool",
        });

  clone_list=({
    1,10,"fly","obj/monster", ({
      "set_name","fly",
      "set_race","insect",
      "set_level",4,
      "set_short","A buzzing fly",
      "set_long","A nasty, annoying, irritating fly.\n",
      "add_money",10,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
