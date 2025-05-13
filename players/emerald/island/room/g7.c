inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="In a cavern";

  long_desc="You are in a big cave in the volcano.  The walls are made of "+
            "black stones and there are lighted torches fixed to the "+
            "walls.  Heavy stones are lying on the ground and there is a "+
            "small path leading further east and west.  You can hear "+
            "some voices coming from the east.\n";

  items=({"cave","The cave leads further to the east and west",
          "stones","Big black stones lying on the ground",
          "torches","They are lighted and fixed to the walls",
          "walls","The walls are dark and made of black stones",
          "ground","The ground is full of dark stones",
          "path","The path is dark and leads further to the east and west",
          "volcano","You are just inside the volcano"
        });

  dest_dir=({"/players/emerald/island/room/g6","west",
             "/players/emerald/island/room/g8","east"
           });

  ::reset(arg);
  replace_program("/room/room");

}
