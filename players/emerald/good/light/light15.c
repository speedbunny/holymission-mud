inherit "room/room";

#define TPN this_player()->query_name()
#define TR tell_room
void reset(int arg) {

  if(arg) return;

  set_light(1);

  long_desc="You have reached the end of the ravine.  The walls still " +
            "look dry and steep, but you might be able to climb up if you " +
            "are lucky.\n";

  short_desc="End of ravine";

  dest_dir=({"players/emerald/good/light/light9", "north",
           });

  items=({"walls","The river walls look climbable here",
          "wall","The wall looks climbable",
          "ravine","An old dry riverbed",
        });

  ::reset();

}

void init() {
  ::init();
  add_action("_climb","climb");
}

_climb(str)  {

  switch(str) {
    case "walls" :
    case "wall" :
    case "the walls" :
    case "the wall" :
    if (random(10) <4) {
      write("You try hard to climb, but you slide back down.\n");
      say(TPN + " tries to climb the river wall but fails.\n");
      return 1;
    }
    write("You succeed in climbing up the ravine wall.\n");
    say(TPN + " climbs up out of the ravine.\n");
    TR("players/emerald/good/light/light16",TPN+" climbs out of the ravine.\n");
    this_player()->move_player("up#players/emerald/good/light/light16");
    return 1;
    default :
    write("Climb what?\n");
    return 1;
  }
}

