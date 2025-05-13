inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The sand dunes";
  long_desc="The ridge of the sand dunes slowly gives way to the gently " +
            "sloping beach which extends for some distance before being " +
            "engulfed by the clear blue water of the sea.  Across the " +
            "second line of dunes to the west extends a vast grassland.  " +
            "Far to the north, the mountains tower over the landscape.  " +
            "The leafy tops of the trees of the Ilkin Forest can just be " +
            "seen jutting over the tops of the southern dunes.\n";

  dest_dir=({"/players/emerald/plain/d07","north",
             "/players/emerald/plain/d03","south",
             "/players/emerald/plain/b08","east",
             "/players/emerald/plain/d04","west",
             "/players/emerald/plain/b10","northeast",
             "/players/emerald/plain/d06","northwest",
             "/players/emerald/plain/b06","southeast",
             "/players/emerald/plain/d02","southwest",
           });

  items=({"ridge","A range of sand dunes extending north and south",
          "dunes","High mounds of sand",
          "beach","A wide white sand beach",
          "water","Hydrogen and oxygen in a two to one ratio",
          "sea","A clear blue sea",
          "grassland","A vast open plain",
          "mountains","High grey mountains standing silent guard over " +
                      "the region",
          "landscape","It is dominated by the mountains",
          "tops","The tops of the trees of the Ilkin Forest",
          "trees","Tall woody vegetation",
          "forest","Entering the forest is quite perilous",
        });

  clone_list=({
    1,1,"spider","obj/monster", ({
      "set_name","brown spider",
      "set_alias","spider",
      "set_race","arachnid",
      "set_level",8,
      "set_short","A wooly brown spider",
      "set_long","An ugly and hairy brown spider.\n",
      "add_money",80,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
