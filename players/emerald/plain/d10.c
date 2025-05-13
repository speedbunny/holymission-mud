inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The end of the sand dunes",
  long_desc="The dunes are blocked to the north and west by the high " +
            "sheer sides of the mountains.  Seabirds fly back and forth " +
            "to the sea from here.  They must have a few nests stashed " +
            "in the ledges of the mountain side.  The blue sea to the east "+
            "looks cool and refreshing compared to the heat of the dunes, " +
            "calling you to the water's edge with the unceasing sound of " +
            "the waves breaking on the beach.\n";

  dest_dir=({"/players/emerald/plain/b14","east",
             "/players/emerald/plain/d09","south",
             "/players/emerald/plain/b16","northeast",
             "/players/emerald/plain/b12","southeast",
             "/players/emerald/plain/d08","southwest",
           });

  items=({"dunes","High mounds of sand",
          "sides","They are nearly verticle and quite sheer",
          "mountains","Imposing, silent, grey mountains",
          "seabirds","They are catching fish for their young",
          "nests","The home of a bird",
          "ledges","Narrow ledges quite high on the mountain side",
          "sea","A clear blue sea",
          "waves","Long rolling waves which wash upon the sand",
        });
  clone_list=({
    1,1,"bird","obj/monster", ({
      "set_name","bird",
      "set_short","A small seabird",
      "set_long","A small seabird.  You are unsure as to its species.\n",
      "set_level",10,
      "set_race","bird",
      "add_money",40,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
