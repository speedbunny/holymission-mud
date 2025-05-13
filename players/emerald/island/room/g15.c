inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="In a cavern";

  long_desc="You are in a big cave in the volcano.  The walls are made of "+
            "black stones and there are lighted torches fixed to the "+
            "walls.  You see a lot of little footprints leading in all "+
            "directions.  The air is really hot here.  To the northeast is "+
            "the entrance to a small building and there is a very loud "+
            "place to the west.\n";

  items=({"cave","The cave leads further to the northeast, southwest "+
                 "west, and north",
          "stones","Big black stones compose the walls",
          "torches","They are lighted and fixed to the walls",
          "walls","The walls are dark and made of black stones",
          "footprints","You see a lot of tiny gnomish footprints",
          "volcano","You are just inside the volcano",
          "lake","You see a little dark lake with hot steam coming from it"
        });

  dest_dir=({"/players/emerald/island/room/g12","southwest",
             "/players/emerald/island/room/g14","west",
             "/players/emerald/island/room/g19","north"
            });

  ::reset(arg);
  replace_program("/room/room");

}
