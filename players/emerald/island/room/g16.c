inherit "/room/room";

void reset(int arg) {
 if(arg) return;

 set_light(1);
 short_desc="In a cavern";

 long_desc="You are in a big cave in the volcano.  The walls are made of "+
           "black stones and there are lighted torches fixed to the "+
           "walls.  There are lots of tiny gnomish footprints on the "+
           "ground.\n";


  items=({"cave","The cave leads further to the north, east, and southeast",
          "stones","Big black stones compose the walls",
          "torches","They are lighted and fixed to the walls",
          "walls","The walls are dark and made of black stones",
          "ground","The ground is full of dark stones",
          "path","The path leads further to the north and east",
          "footprints","You see a lot of tiny gnomish footprints, leading "+
                      "in all directions",
          "volcano","You are just inside the volcano",
        });

  dest_dir=({"/players/emerald/island/room/g21","north",
             "/players/emerald/island/room/g13","southeast"
           });

  ::reset(arg);
  replace_program("/room/room");

}
