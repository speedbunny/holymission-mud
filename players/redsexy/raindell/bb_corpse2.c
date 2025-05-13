//include and inherit standard stuff
inherit "/obj/corpse";
#include "/include/defs.h"
//we are going to be using some code called pluck_bluebird
  int pluck_bluebird();
//we are going to be using an integer we call find
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
//if the string isn't feathers - dont do anything!
   say(this_player()->query_name()+" plucks the corpse!\n");
//tell the other people in the room the person is plucking!
   pluck_bluebird();
//go to the pluck_bluebird bit of code
   return 1;
   }      

pluck_bluebird() {
//gotta tell the compiler you'll be using the term feathers to refer to an obj
  object feathers;
//if there are already feathers on the player
  if(present("feathers",this_player())) {
//Tell em
    write("You have already plucked some feathers!\n");
    return;
//find has happened.  They have feathers.
    find=1;
  }
  
  if(find) {
//if find=1 tell em
    write("You have already plucked some feathers!\n");
    return;
  }
//they've got this far so we tell em
  write("You carefully pluck the bluebird's feathers, then dispose of the carcass.\n");
//we define the object feathers
  feathers=clone_object("/players/redsexy/raindell/bb_feathers");
//we transfer the feathers to the player
  transfer(feathers,this_player());
//find now = 1
  find=1;
  return;
} 
