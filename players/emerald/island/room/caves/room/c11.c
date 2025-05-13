inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="At an opening";

  long_desc="You are just inside a hidden cave in the volcano.  An opening "+
            "to the north leads out to the sunshine, while the passage leads "+
            "south into darkness.  A grassy prarie can be seen beyond the "+
            "opening, filled with sunshine.\n";

  items=({"cave","A hidden cave inside the volcano",
          "volcano","An active volcano, rumbling and thundering",
          "opening","It leads to a prarie",
          "passage","A hidden passage through the volcano",
          "darkness","Inky blackness lurks to the south",
          "prarie","A lush, green prarie",
          "sunshine","Nice, warm sunshine",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/c10","south",
             "/players/emerald/island/room/caves/room/p1","up",
           });

  ::reset();
  replace_program("/room/room");

}
