inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="The beach beyond the dunes";
  long_desc="You are at the edge of the beach.  To the west begin the " +
            "dunes, and far beyond that, the high snow-capped peaks of the " +
            "mountains.  Only scrubby vegetation which can tolerate the " +
            "harsh, salty conditions of the seacoast grow along the border " +
            "of the beach.  To the east, the roaring surf pounds " +
            "unceasingly against the sand, filling your ears with its " + 
            "endless noise.\n";

  dest_dir=({"/players/emerald/plain/b14","north",
             "/players/emerald/plain/b10","south",
             "/players/emerald/plain/b13","east",
             "/players/emerald/plain/d09","west",
             "/players/emerald/plain/b15","northeast",
             "/players/emerald/plain/d10","northwest",
             "/players/emerald/plain/b11","southeast",
             "/players/emerald/plain/d07","southwest",
           });

  items=({"beach","A white-sand beach",
          "dunes","Mounds of accumulated sand",
          "peaks","Their caps of snow makes you think of winter",
          "mountains","Cold, silent mountains",
          "vegetation","Salt-loving weeds",
          "seacoast","The sea is to the east, the land to the west",
          "border","The edge of the dunes and the beach",
          "surf","The white-capped waves",
          "sand","Silica",
        });

  ::reset();
  replace_program("/room/room");

}
