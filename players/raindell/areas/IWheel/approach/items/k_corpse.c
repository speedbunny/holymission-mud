inherit "/obj/corpse";
#include "/include/defs.h"

  int pluck_kestral();
  int find;

reset(arg) {
  ::reset(arg);
	set_name("kestral");
 }

void init() {
  ::init();    
   add_action( "_pluck", "pluck" ); 
}

int _pluck(string str) {
  if(str!="feathers") return 0;
   say(TP->NAME+" plucks the feathers from the corpse of the kestral!\n");
   pluck_kestral();
   return 1;
   }      

pluck_kestral() {
  object kfeathers;
  if(present("kfeathers",TP)) {
    write("You have already plucked the feathers, there are no more!\n");
    return;
    find=1;
  }

  if(find) {
write("You have already plucked the feathers, there are no more!\n");
    return;
  }

  write("You carefully pluck the kestral's feathers, then dispose of the carcass.\n");
  kfeathers=clone_object("/players/raindell/areas/IWheel/approach/items/k_feathers");
  transfer(kfeathers,TP);
  find=1;
  destruct(TO);
  return;

} 