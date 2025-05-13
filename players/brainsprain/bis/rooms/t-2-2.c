inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

int climb(string arg){
  if (arg != "ladder up" && arg != "ladder down" && arg != "ladder"){
    write("Climb what?\n");
    return 1;
  }
  else if(arg == "ladder"){
    write("Climb the ladder up or down?\n");
    return 1;
  }
  else if(arg == "ladder down"){
    write("You climb the ladder.\n");
    this_player()->move_player("down#/players/brainsprain/bis/rooms/t-2-1.c");
    return 1;
  }
  else if(arg=="ladder up"){
    write("You climb the ladder.\n");
    this_player()->move_player("up#/players/brainsprain/bis/rooms/t-2-3.c");
    return 1;
  }
}



void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  
  short_desc = "Second floor of southwestern tower";
  long_desc =
    "The walls here are circular.  A ladder goes the entire length of the "+
    "eastern wall, connecting sections of the tower.  From above, the sound "+
    "of clinking metal and grunting can be heard.  Several of the ladder "+
    "rungs have begun to rot out.\n";
  set_light(1);
  items = ({
    "walls",
    "The walls of the tower",
    "tower",
    "The southwestern tower",
    "rungs",
    "They are mainly rotten and look treacherous to climb",
    "ladder",
    "A wooden ladder making it possible to get to the next floor",
  });
}
void init(){
  ::init();
  add_action("climb","climb");
}
