inherit "room/room";
 
#include "/players/jake/defs.h"
 
void reset(int arg) {
  if(arg) return;
 
  clone_list=({
    1,1,"pigeon","/players/jake/Old_area/monster/pigeon",0,
  });

  set_light(1);
  short_desc = "gard9";
  long_desc = 
    "This area is surrounded by beautiful shrubbery. "+
    "In the center is a gigantic statue of Jake. "+
    "@@see_pigeon@@\n";
 
  items = ({
    "statue","A handsome statue of Jake",
    "shrubbery","Beautiful shrubbery"
  });
 
  dest_dir = ({
    NEW + "gard10","south",
    NEW + "gard8","east",
  });
  
  ::reset(arg);
}

string see_pigeon() {
  if(present("pigeon", this_object()))
    return "A pigeon sits on the statue's shoulder.";
  else
    return "Other than the statue, this place is empty.";
}
