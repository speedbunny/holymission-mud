inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The beach beyond the dunes";
  long_desc="The rolling mounds of dunes to the west back straight into " +
            "the flanks of the mountains.  To the east, the white-sand " +
            "beach with its coating of shells and pebbles extends into " +
            "the rolling waves of the sea.  Only the cries of seagulls " +
            "and the roar of the surf can be heard in this empty land.\n";

  dest_dir=({"/players/emerald/plain/b16","north",
             "/players/emerald/plain/b12","south",
             "/players/emerald/plain/b15","east",
             "/players/emerald/plain/d10","west",
             "/players/emerald/plain/b17","northeast",
             "/players/emerald/plain/b13","southeast",
             "/players/emerald/plain/d09","southwest",
           });

  items=({"mounds","The sand dunes",
          "dunes","Mounds of accumulated sand",
          "flanks","The sides of the mountains",
          "mountains","High, grey, silent mountains",
          "beach","A wide sandy beach",
          "shells","Many varieties of shells",
          "pebbles","Small, round pebbles washed up by the waves",
          "waves","The roll on to the shore",
          "sea","A clear blue sea",
          "seagulls","They loudly voice their cries",
          "land","The beach and dunes",
        });

  clone_list=({
    1,1,"beetle","obj/monster", ({
      "set_name","beetle",
      "set_race","insect",
      "set_short","A black beetle",
      "set_long","An enormous black beetle with fierce pinchers.\n",
      "set_level",9,
      "set_wc",7,
      "add_money",60,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
