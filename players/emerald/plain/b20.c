inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A rocky cove";
  long_desc="The rocky coastline has formed around a cove.  In the blue " +
            "water of the cove, several crabs can be seen swimming " +
            "around.  All around is nothing but the black rocks of the " +
            "mountains and the shore.  To the south, some sand has " +
            "accumulated and the coastline widens into a true beach.  " +
            "Above, the cliffs of the mountains tower over the cove.\n";

  dest_dir=({"/players/emerald/plain/b21","north",
             "/players/emerald/plain/b19","south",
             "/players/emerald/plain/b18","southwest",
           });

  items=({"coastline","You are there",
          "cove","A recess in the rocks where the water forms a deep pool",
          "water","It is quite deep in the cove",
          "rocks","They form the coast, the cove, and the mountains",
          "mountains","High, silent, cold mountains",
          "shore","The area between the mountains and the sea",
          "sand","White sand",
          "crabs","They look happy in the water",
          "beach","A sandy beach",
          "cliffs","Sheer cliffs that cannot be climbed",
        });

  clone_list=({
    1,1,"crab","obj/monster", ({
      "set_name","crab",
      "set_race","crab",
      "set_short","A rock crab",
      "set_long","A crab from the cove.  It does not look happy.\n",
      "set_level",14,
      "set_wc",12,
      "set_ac",13,
      "add_money",400,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
