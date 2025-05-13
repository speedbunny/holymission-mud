inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
int found;
int search (string arg){
  object bottle;
  int w;
  if(arg != "alcove") {
    write("You search and find nothing...\n");
    return 1;
  }
  if (arg == "alcove") {
    if(!found) {
      write("You find a bottle in the alcove.\n");
      say(capitalize(TP->query_name())+" finds a bottle.\n");
      bottle=clone_object(si+"/bottle");
      transfer(bottle,TP);
      found=1;
      return 1;
    }
    if(found){
      write("You search the alcove, but find nothing.\n");
      return 1;
    }
  }
}

void reset(int arg) {
  ::reset(arg);  
  if(arg) return;
  short_desc = "Floor with thick slime on it";
  long_desc =
    "A pool of thick slime lies six inches on the the floor.  The bottom "+
    "six inches of the wall are much wider than the rest of the room.  "+
    "An alcove has been carved into the northern wall.  Several "+
    "animal carcasses float in the slime.\n";
  items = ({
    "pool",
    "A pool of slime",
    "wall",
    "The slime has eaten away at it",
    "carcasses",
    "Several carcasses boil as the acidic slime eats away at them",
    "slime",
    "A thick black slime that makes you ankles tingle",
    "alcove",
    "A small hole in the wall",
  });

  set_light(0);
  dest_dir = ({
    sr+"/room110","west",
    sr+"/room111","east",
  });
}
void init(){
  ::init();
  add_action("search","search");
}

