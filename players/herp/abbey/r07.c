#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="The Library";
     long_desc=
"You seem to have entered the library.\n"+
"There are many books here, lying in tumbled heaps.\n"+
"There are obvious exits north, south and west.\n"+
"You see your reflection in the burnished metal door to the south.\n";
     dest_dir=({ PATH+"/r04","north",
		 PATH+"/r10","south",
		 PATH+"/r08","west" });
  }
}
init() {
  ::init();
  add_action("south","south");
  add_action("press","press");
}
long() { write(long_desc); }
south() {
  write("The door won't budge!\n");
  return 1;
}

press(str) {
  if (str!="the fourth and seventh above") {
     write("Press what?\n");
     return 1;
  }
  if (this_player()->query_quests("abbey")) {
     write("You already have solved this quest.\n"+
	   "You may not enter anymore.\n");
     return 1;
  } 
  write("The burnished door opens when you press the number.  You pass through\n");
  this_player()->move_player("south#"+PATH+"/r10");
  return 1;
}

