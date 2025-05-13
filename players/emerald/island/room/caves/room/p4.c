inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="On a prairie";

  long_desc="A dark forest begins far off to the northeast, while the "+
            "prairie itself continues to the north and west for some "+
            "distance.  The peaks of mountains surround the area, and a "+
            "cloud of yellow vapour hangs in the air.  Small bushes and "+
            "grass grow in profusion in the rich soil.\n";

  items=({"forest","A mixed forest of firs and oaks",
          "prairie","A small prairie on the plateau of the volcano",
          "peaks","The tops of volcanic mountains",
          "mountains","Volcanic mountains",
          "area","An open prarie",
          "cloud","A could of yellow volcano gasses",
          "vapour","Yellow volcano gasses",
          "air","The air is almost pure up here",
          "bushes","Their twigs have been nibbled on",
          "grass","Thick, lush prarie grass",
          "soil","Nutrient-rich volcanic soil",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/p3","west",
             "/players/emerald/island/room/caves/room/p9","northeast",
             "/players/emerald/island/room/caves/room/p8","north",
           });

  ::reset(arg);
  replace_program("/room/room");

}
