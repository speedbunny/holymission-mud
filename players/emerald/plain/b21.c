inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A rocky coastline";
  long_desc="Long strands of seaweed wrapped around the rocks of the " +
            "coastline make the rocks quite slippery.  As the sea surges " +
            "around rocks in the surf several feet below the edge of the " +
            "coastline, falling in would be quite painful, if not deadly.  " +
            "The coastline grades severly upwards to the north as it " +
            "hugs the edge of the mountains.  To the south it grades " +
            "downwards, eventually ending in a sandy beach.\n";

  dest_dir=({"/players/emerald/plain/b22","north",
             "/players/emerald/plain/b20","south",
           });

  items=({"strands","Long tendrils of kelp",
          "seaweed","Dark green kelp",
          "rocks","They are quite wet and make footing treacherous",
          "sea","A dark blue sea",
          "coastline","The meeting of sea and land",
          "mountains","Tall mountains which tower to the west",
          "beach","A wide sandy beach",
        });

  clone_list=({
    1,3,"snail","obj/monster", ({
      "set_name","snail",
      "set_short","A sea snail",
      "set_long","A brown sea snail clinging to some seaweed.\n",
      "set_level",6,
      "set_ac",10,
      "add_money",30,
      "set_race","mollusc",
    }),
  });

  ::reset();
  replace_program("/room/room");

}

