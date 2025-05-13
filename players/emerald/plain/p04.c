
inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A large grassy plain";

  long_desc="You are standing in the middle of a grassy plain.  The long " +
            "stems of grass ripple in the summer breeze.  A few lavender " +
            "geraniums add a touch of colour to the golden sea.  High " +
            "mountain peaks rise into the sky far to the north.  Dark " +
            "trees line the southeastern border, marking the edge of the " +
            "thick Ilkin Forest.\n";

  dest_dir=({"/players/emerald/plain/p13","north",
             "/players/emerald/plain/p02","south",
             "/players/emerald/plain/p05","east",
             "/players/kryll/rooms/path/ep14","west",
             "/players/emerald/plain/p14","northeast",
             "/players/kryll/rooms/path/ep15","northwest",
             "/players/kryll/rooms/path/ep13","southwest",
           });

  items=({"plain","A large flat area of grass",
          "stems","Golden stalks of grass",
          "geraniums","Small plants with delicate lavender flowers",
          "peaks","High snow-capped peaks",
          "trees","Ancient oaks and maples with thick branches forming " +
                  "an impenetrable barrier",
          "forest","The dark and dangerous Ilkin Forest",
        });

  clone_list=({
    1,1,"worm","obj/monster", ({
      "set_name","worm",
      "set_short","An earthworm",
      "set_level",2,
      "set_race","worm",
    }),
  });

  ::reset();
  replace_program("/room/room");

}
