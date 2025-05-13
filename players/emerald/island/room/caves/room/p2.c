inherit "/room/room";
void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="On a prairie";

  long_desc="An outcropping of volcanic rock blocks the prairie to the south "+
            "and west.  Further to the north and east, the open grassland "+
            "with its sprinkling of bushes continues.  The peaks of "+
            "mountains surround the area, while off to the northeast, a dark "+
            "forest begins.  A cloud of yellow vapour hangs in the air.\n";

  items=({"outcropping","The remnants of an old lava flow",
          "rock","Vast chunks of basalt",
          "prairie","An open prairie on top of the volcano",
          "grassland","An open prairie on the volcano",
          "bushes","Hardy little bushes",
          "peaks","The rounded tops of volcanic mountains",
          "mountains","Volcanic mountains",
          "area","The prairie and forest",
          "forest","A dark forest of firs and oaks",
          "cloud","A thick cloud of yellow volcano gasses",
          "vapour","Volcano gasses",
          "air","The air is almost pure up here",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/p3","east",
             "/players/emerald/island/room/caves/room/p6","north",
             "/players/emerald/island/room/caves/room/p5","northwest",
           });

  ::reset(arg);
  replace_program("/room/room");

}
