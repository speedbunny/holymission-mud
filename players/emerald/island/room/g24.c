inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="In a cavern";
  long_desc="You are in a big cave inside the volcano.  The walls are made "+
            "of black stones and there are lighted torches fixed to the "+
            "walls.  There are lots of tiny footprints leading in various "+
            "directions.  To the east is a steaming lake, and to the north "+
            "is a building.  You can hear noises coming from the building.\n";

  items=({"cave","The cave leads further to the north and south",
          "walls","Thick black walls",
          "stones","Big black stones compose the walls",
          "torches","They are lighted and fixed to the walls",
          "footprints","You see a lot of tiny gnomish footprints, leading "+
                       "north and south",
          "volcano","You are inside the volcano",
          "building","You can see a small building to the north",
          "lake","You see adark lake with steam rising from it"
        });

  dest_dir=({"/players/emerald/island/room/g28","north",
             "/players/emerald/island/room/g19","south",
           });

  ::reset(arg);
  replace_program("/room/room");
 
}
