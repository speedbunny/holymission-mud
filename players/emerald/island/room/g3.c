#define TP  this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()

inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light( 1 );

  short_desc="In a cavern";

  long_desc="You are in a big cave that leads into the volcano.  The walls "+
            "are made of shiny black stones and there are lighted torches "+
            "fixed to the walls.  An iron pole in the south wall leads up.  "+
            "You see a small path leading further to the west and you "+
            "hear some human noises coming from there.\n";

  items=({"cave","A cave in the volcano",
          "stones","Big black stones lying on the ground",
          "torches","They are lighted and fixed to the walls",
          "walls","The walls are dark and made of black stones",
          "path","The path leads further to the west",
          "pole","A big iron pole leading up.  It might be possible to "+
                 "slide on it",
          "volcano","You are just inside the volcano"
        });

  dest_dir=({"/players/emerald/island/room/g4","west"
           });

  ::reset(arg);

}

void init() {
  ::init();
  add_action("do_slide","slide");
  add_action("do_climb","climb");
}

do_slide (arg) {
  if(arg!="pole") {
    notify_fail("Slide what?\n");
    return 0;
  }
  write("You are already at the bottom of the pole.\n");
  return 1;
}

do_climb(arg) {
  if(!arg) {
    notify_fail("Climb what?\n");
    return 0;
  } 
  if(arg=="pole") {
    write("You try to climb up the pole, but slide down again.\n");
    say(TPN+" tries to climb up the pole, but slides down again.\n");
    return 1;
  }

}
