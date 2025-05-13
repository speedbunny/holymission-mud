inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A grassy plain";
  long_desc="You find yourself standing in the golden sunlight while the " +
            "breeze bends the grass in waves across the plain.  To the " +
            "northeast, the long ridge of high grey mountain peaks forms " +
            "the edge of the plain, blocking any exit.  South lies the " +
            "leafy tops of the Ilkin Forest.  Down around your feet, " +
            "something scurries through the grass.\n";

  dest_dir=({"/players/emerald/plain/p28","north",
             "/players/emerald/plain/p09","south",
             "/players/emerald/plain/p19","east",
             "/players/emerald/plain/p17","west",
             "/players/emerald/plain/p27","northwest",
             "/players/emerald/plain/p10","southeast",
             "/players/emerald/plain/p08","southwest",
           });

  items=({"grass","Long golden stems of grass",
          "waves","Waves of grass billow in the breeze",
          "plain","A vast flat area of grassland",
          "ridge","A chain of mountains to the north and east",
          "mountains","High, unclimbable grey mountains",
          "forest","An ancient forest of great evil",
          "tops","The canopy of the trees of the forest",
          "feet","Flat appendages used for locomotion",
        });

  clone_list=({
    1,1,"mouse","obj/monster", ({
      "set_name","field mouse",
      "set_alias","mouse",
      "set_race","rodent",
      "set_short","A grey field mouse",
      "set_long","A hungry grey field mouse, scrounging for food.\n",
      "set_level",6,
      "add_money",20,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
