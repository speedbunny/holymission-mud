inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
int eaten;
int eat(string arg){
	if (arg != "flour"){
	write("That is not edible.\n");
	return 1;
}
if (arg == "flour"){
	if(!eaten) {
		this_player()->heal_self(5);
		write("The flour tastes good!!\n");
		say(capitalize(this_player()->query_name())+" eats some flour.\n");
		eaten = 1;
		return 1;
	}
	else {
		write("There is no more flour.\n");
		return 1;
	}
}
}

void reset( int arg){
    ::reset(arg);
   if(arg) return;
 short_desc = "The goblin pantry";
  long_desc =
"The sigil on the wall clearly identifies this room as the property of the "+
"goblins.  The walls of this pantry are lined with bags of flour.  One of "+
"the bags is open and a cup filled with flour sits on top of it.\n";
  set_light(1);
  eaten=0;
  dest_dir = ({
    sr+"/room204","east",
    sr+"/room206","southwest",
  });
  items = ({
    "sigil",
    "The word 'Gulgug' in fancy letters",
    "cup",
    "A cup full of flour",
    "walls",
    "The walls are lined with bags of flour, covering the entire wall",
    "grain",
    "Grain is spilled all over the floor and leaks out of several bags",
    "bag",
    "Decaying bags of grain",
    "flour",
    "A tasty looking cup of flour",
  });
}
void init(){
  ::init();
  add_action("eat","eat");
  }
