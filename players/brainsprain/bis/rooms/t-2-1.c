inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

int climb(string arg){
  if (arg != "ladder"){
    write("Climb what?\n");
    return 1;
  }
  else {
    write("You climb the ladder.\n");
    this_player()->move_player("up#/players/brainsprain/bis/rooms/t-2-2.c");
    return 1;
  }
}


void reset(int arg) {
  clone_list = ({ 1, 1, "dog1", bm+"/mastiff.c", 0, 
		  1, 1, "dog2", bm+"/dob.c", 0,                 
		  1, 1, "dog3", bm+"/germ.c", 0,                 
		  1, 1, "dog4", bm+"/bulldog.c", 0,                 
  });
  ::reset(arg);
  if(arg) return;  
  short_desc = "First floor of southeastern tower";
  long_desc =
    "A ladder sits against the eastern wall. A fence divides this room in "+
    "half with the western side serving as a kennel for the Count's prize "+
    "hunting dogs.  Along the western wall is a huge doggie-door.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-8.c","north",
  });
  items = ({
    "kennel",
    "The kennel of the Count's prize hunting dogs",
    "wall",
    "The eastern wall of the tower",
    "tower",
    "The southeastern tower",
    "ladder",
    "A wooden ladder making it possible to get to the next floor",
    "fence",
    "A thick iron fence",
    "doggie-door",
    "A door designed to give the dogs an access point to the outside",
  });
}
void init(){
  ::init();
  add_action("climb","climb");
}
