inherit "obj/treasure";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
set_id("potion");
set_alias("potion");
set_short("A healing potion");
set_long(
"This potion is made of a thick red fluid.  As you swirl the bottle the "+
"liquid sticks to the side of the bottle.  Small flakes of gold float "+
"in the mixture.  Around the stem of the bottle is a a filgaree in silver.\n");
set_value(4000);
set_weight(1);
}
void init(){
  ::init();
  add_action("do_drink","drink");
  }
do_drink(string arg){
if (arg != "potion"){
write("Drink what?\n");
return 1;
} 
else {
write("You feel much better as you swallow the red substance.\n");
say(capitalize(this_player()->query_name())+" drinks something.\n");
this_player()->heal_self(50);
write("The bottle shatters in you hand!\n");
destruct(this_object());
return 1;
}
}


