inherit "/obj/corpse";
#include "/include/defs.h"

  int pluck_swallow();
  int find;

reset(arg) {
  ::reset(arg);
	set_name("swallow");
 }

void init() {
  ::init();    
   add_action( "_pluck", "pluck" ); 
}

int _pluck(string str) {
  if(str!="feathers") return 0;
   say(TP->NAME+" plucks the feathers from the corpse of the swallow!\n");
   pluck_swallow();
   return 1;
   }      

pluck_swallow() {
  object sfeathers;
  if(present("sfeathers",TP)) {
    write("You have already plucked the feathers, there are no more!\n");
    return;
    find=1;
  }

  if(find) {
write("You have already plucked the feathers, there are no more!\n");
    return;
  }

  write("You carefully pluck the swallow's feathers, then dispose of the carcass.\n");
  sfeathers=clone_object("/players/raindell/areas/IWheel/approach/items/s_feathers");
  transfer(sfeathers,TP);
  find=1;
  destruct(TO);
  return;

} 