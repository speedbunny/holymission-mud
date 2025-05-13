#define TPN this_player()->query_name()

inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="In a cavern";

  long_desc="You are in a big cave leading futher into the volcano.  The "+
            "walls are made of black stones and there are lighted torches "+
            "fixed to the walls.  To the south is a big iron pole which "+
            "leads up.  You see a lot of little footprints leading north, "+
            "northwest and northeast.  The air is hot here and you hear "+
            "many voices coming from the north.\n";

  items=({"cave","The cave leads further to the north, northeast and northwest",
          "stones","Big black stones lying on the ground",
          "torches","They are lighted and fixed to the walls",
          "walls","The walls are dark and made of black stones",
          "pole","A big iron pole leading up",
          "footprints","You see a lot of tiny gnomish footprints, leading "+
                      "in all directions",
          "volcano","You are inside the volcano",
        });


  dest_dir=({"/players/emerald/island/room/g11","north",
             "/players/emerald/island/room/g10","northwest",
             "/players/emerald/island/room/g12","northeast"
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
