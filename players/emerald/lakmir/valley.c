inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="A small valley";
  long_desc="You are in a small green valley which lies between the dark " +
            "forest to the east and a dark cave to the west.  The turf " +
            "is soft and springy under your feet.  Small flowers of blue " +
            "and white bloom in among the grass.\n";

  dest_dir=({"/players/emerald/lakmir/forest9","east",
             "/players/emerald/lakmir/cave","west",
           });

  items=({"valley","A small green valley",
          "forest","The trees look quite ancient and evil",
          "cave","It is big enough to enter",
          "turf","Nice thick grass",
          "flowers","Tiny flowers blooming at your feet",
          "feet","They support the weight of your body",
          "grass","Thick, healthy green grass",
        });

  ::reset();
  replace_program("/room/room");

}

