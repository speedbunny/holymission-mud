inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A rocky beach";
  long_desc="The waves crash and break into foamy spray against the rocks " +
            "of the coastline.  Here and there are tiny patches of sand, " +
            "reflecting the sunlight in stark contrast to the dark wet " +
            "boulders which form the beach.  Seaweed tossed up by the " +
            "waves is draped over the rocks.  A few shells are scattered " +
            "about the sand.\n";

  dest_dir=({"/players/emerald/plain/b20","north",
             "/players/emerald/plain/b17","south",
             "/players/emerald/plain/b18","west",
             "/players/emerald/plain/b16","southwest",
           });

  items=({"waves","Foamy, rolling waves",
          "spray","The spray glistens in the sunlight",
          "rocks","Huge, wet boulders",
          "coastline","The meeting of land and sea",
          "sunlight","It sparkles off the wet rocks",
          "boulders","Huge chunks of rock from the mountains",
          "beach","It is nearly covered in rocks",
          "seaweed","Long tendrils of kelp",
          "shells","The former home of marine animals",
          "sand","Coarse-grained particles of silica",
        });

  clone_list=({
    1,1,"jellyfish","obj/monster", ({
      "set_name","jellyfish",
      "set_alias","fish",
      "set_short","A jellyfish",
      "set_long","A jellyfish which has been washed up on the beach.\n",
      "set_level",14,
      "add_money",155,
      "set_wc",10,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
