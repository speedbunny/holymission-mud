inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

void north(){
write_file("/players/brainsprain/log.enter", TP->query_real_name()+"\n");
return;
}
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  
  short_desc = "Town pier";
  long_desc =
    "The sides of the docks are crammed with ships in various stages of "+
    "docking, leaving, and unloading.  To the south, the main cargo junk "+
    "to Ezo Island has a reserved section of the pier, if it is not there, "+
    "it should be arriving at any minute.  As you look out over the ocean "+
    "you see many boats traveling to the mainland.\n";
  set_light(1);
  dest_dir = ({
    br+"/pier1","north",
    "/room/sea","south",
  });
  items = ({
    "ocean",
    "A small bay on the ocean",
    "boats",
    "They are traveling to the mainland",
    "ships",
    "Ships of all sizes",
    "pier",
    "The loading pier for Towpath",
    "dock",
    "The dock where all the boats rest",
  });
  


}


void init(){
  ::init();
  add_action("north","north");
}
