inherit "/obj/corpse";
#include "/include/defs.h"
  int pluck_bluebird();
  int find;

reset(arg) {
  ::reset(arg);
 }

void init() {
  ::init();    
   add_action( "_pluck", "pluck" ); 
}

int _pluck(string str) {
  
   if(str!="feathers") return 0;
   say(this_player()->query_name()+" plucks the corpse!\n");
   pluck_bluebird();
   return 1;
   }      

pluck_bluebird() {
  object feathers;

  if(present("feathers",this_player())) {
    write("You have already plucked some feathers!\n");
    return;
    find=1;
  }
  
  if(find) {
    write("You have already plucked some feathers!\n");
    return;
  }

  write("You carefully pluck the bluebird's feathers, then dispose of the carcass.\n");
  feathers=clone_object("/players/redsexy/raindell/bb_feathers");
  transfer(feathers,this_player());
  find=1;
  return;
} 
