inherit "/obj/corpse";
#include "/include/defs.h"

  int pluck_bluebird();
  int find;

reset(arg) {
  ::reset(arg);
	set_name("bluebird");
 }

void init() {
  ::init();    
   add_action( "_pluck", "pluck" ); 
}

int _pluck(string str) {
  if(str!="feathers") return 0;
   say(TP->NAME+" plucks the feathers from the corpse of the bluebird!\n");
   pluck_bluebird();
   return 1;
   }      

pluck_bluebird() {
  object bfeathers;
  if(present("bfeathers",TP)) {
    write("You have already plucked the feathers, there are no more!\n");
    return;
    find=1;
  }

  if(find) {
write("You have already plucked the feathers, there are no more!\n");
    return;
  }

  write("You carefully pluck the bluebird's feathers, then dispose of the carcass.\n");
  bfeathers=clone_object("/players/raindell/areas/IWheel/approach/items/bb_feathers");
  transfer(bfeathers,TP);
  find=1;
  destruct(TO);
  return;

} 