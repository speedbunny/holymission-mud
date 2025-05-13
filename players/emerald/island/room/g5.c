#define TPN this_player()->query_name()

inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="In a cavern";

  long_desc="You are in a big cave in the volcano.  The walls are made of "+
            "black stones and there are lighted torches fixed to the "+
            "walls.  On the south wall there is a big iron pole leading up.  "+
            "A small path leads further to the east and you can hear some "+
            "noises coming from there.\n";

  items=({"stones","Big black stones lying on the ground",
          "torches","They are lighted and fixed to the walls",
         "wall","There is a pole along the south wall",
          "walls","The walls are dark and made of black stones",
          "path","The path leads further to the east",
          "pole","A big iron pole leading up",
          "volcano","You are inside the volcano"
          "cave","A large cave inside the volcano",
        });

  dest_dir=({"/players/emerald/island/room/g6","east"
           });

  ::reset(arg);

}

void init() {
  ::init();
  add_action("do_slide","slide");
  add_action("do_climb","climb");
}

do_slide(arg) {
  if(arg!="pole") {
    notify_fail("Slide what?\n");
    return 0;
  } 
  write("You are already at ground level.\n");
  return 1;
}

do_climb(arg) {
  if (!arg) {
    notify_fail("Climb what?\n");
    return 0;
  }
  if(arg=="pole") {
    write("You try to climb up the pole, but slide down again.\n");
    say(TPN+" tries to climb up the pole, but slides down again.\n");
    return 1;
  }
}
