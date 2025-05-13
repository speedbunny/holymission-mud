inherit "/room/room";

void reset(int arg) {
  if (arg) return;

  set_light(1);
  short_desc="On an island";

  long_desc="You are on a plateau on the volcanic island.  The air is full "+
            "of ash particles and you can hear the rumblings of the "+
            "volcano.  A small path on the east side of the plateau climbs "+
            "further up the volcano, while to the west, you can see the sea.\n";

  items=({"plateau","A plateau on the side of the volcano",
          "island","A large, active volcanic island in the sea",
          "air","It is choked with ash",
          "particles","Tiny particles of volcanic ash",
          "path","It leads up to the top of the volcano",
          "sea","The sea is far below you",
        });

  dest_dir=({"/players/emerald/island/room/i12", "up",
             "/players/emerald/island/room/i16", "north",
             "/players/emerald/island/room/i5", "south",
           });

  clone_list=({
    1,1,"snake","obj/monster",({
      "set_name","snake",
      "set_alias","red snake",
      "set_short","A red snake",
      "set_long","It looks like a rattlesnake but it's harmless.\n",
      "set_race","reptile",
      "set_level",4,
      "set_al",50,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
