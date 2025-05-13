#define TPN this_player()->query_name()

inherit "/room/room";
void reset(int arg) {


 if(arg) return;

 set_light(1);

 short_desc="In a cavern";

 long_desc="You are in a big cave in the volcano.  The walls are made of "+
           "black stones and there are lighted torches fixed to the "+
           "walls.  You see a lot of little footprints leading in all "+
           "directions.  This is a crossroad which leads further into "+
           "a strange town.  A hot lake lies to the east.\n";

  items=({ "cave","The cave leads further to the northwes, northeast "+
                  "and southeast",
          "stones","Big black stones compose the walls",
          "torches","They are lighted and fixed to the walls",
          "walls","The walls are dark and made of black stones",
          "footprints","You see a lot of tiny gnomish footprints",
          "volcano","You are inside of it",
          "sign","Something is written on it",
          "lake","You see a dark lake with steam rising from it",
        });

  dest_dir=({"/players/emerald/island/room/g16","northwest",
             "/players/emerald/island/room/g10","southeast",
             "/players/emerald/island/room/g18","northeast"
            });
  ::reset(arg);

}

void init() {
  ::init();
  add_action("do_read","read");
}

do_read(arg) {

  if(arg!="sign") {
    notify_fail("Read what?\n");
    return 0;
  }
  write("You read:\n\nGrnzgrrg (GiantsAreNotAllowedInOurTown) \n\n");
  say(TPN+" reads the sign.\n");
  return 1;
}
