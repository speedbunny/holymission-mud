inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="The sand dunes";
  long_desc="The sand dunes slope gently down to a wide sandy beach.  The " +
            "valleys and slopes of the dunes support a minimal cover of " +
            "scrubby vegetation.  The tracks of an unknown animal meander " +
            "in between the dunes, heading inland towards the mountains.  " +
            "The roar of the sea fills your ears, and you can think of " +
            "nought save its endless song.\n";

  dest_dir=({"/players/emerald/plain/d10","north",
             "/players/emerald/plain/d07","south",
             "/players/emerald/plain/b12","east",
             "/players/emerald/plain/d08","west",
             "/players/emerald/plain/b14","northeast",
             "/players/emerald/plain/b10","southeast",
             "/players/emerald/plain/d06","southwest",
           });

  items=({"dunes","Small mounds of wind-blown sand",
          "beach","A long stretch of white-sand beach",
          "valleys","Troughs between the dunes",
          "slopes","The sides of the dunes",
          "vegetation","Hardy grasses and shrubs",
          "tracks","Small footprints from an animal",
          "mountains","High, grey, sheer mountains",
          "sea","A clear blue sea",
        });

  ::reset();
  replace_program("/room/room");

}
