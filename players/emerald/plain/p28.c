inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The edge of the plain";
  long_desc="The chain of mountains to the north angles to the southeast, " +
            "creating a barrier to the expansion of the plain.  High, " +
            "almost sheer, cliffs form the base of the mountains, with " +
            "craggy sides and peaks further up the mountains.  To the " +
            "south, the grassland continues until the northern boundary " +
            "of the dark Ilkin Forest.\n";

  dest_dir=({"/players/emerald/plain/p27","west",
             "/players/emerald/plain/p18","south",
             "/players/emerald/plain/p19","southeast",
             "/players/emerald/plain/p17","southwest",
           });

  items=({"chain","A high ridge of mountains forming the northern and " +
                  "eastern boundary",
          "mountains","Their snow-capped peaks jut into the sky",
          "barrier","The mountains are unclimbable",
          "plain","A vast open section of grassland",
          "cliffs","They rise upwards for hundreds of feet",
          "sides","Rocky, uneven mountain sides",
          "peaks","They are tipped with a coating of snow",
          "grassland","So named on account of the dominant vegetation",
          "boundary","The meeting of plain and forest",
          "forest","A haven for evil",
        });

  clone_list=({
    1,1,"lynx","obj/monster", ({
      "set_name","lynx",
      "set_race","feline",
      "set_short","A hungry lynx",
      "set_long","A tawny lynx ranging far from its home territory.\n",
      "set_level",18,
      "set_aggressive",1,
      "add_money",450,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
