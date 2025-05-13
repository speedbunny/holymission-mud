inherit "obj/treasure";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
set_id("A morphic scroll");
set_alias("scroll");
set_short("A morphic scroll");
set_long(
"This scroll is rolled tightly but seems to quiver with power.  Strange "+
"symbols and letters cover both sides of the scroll.  It is sealed with "+
"a lump of wax.  The seal of Bismarck is pressed into the center of the "+
"wax.\n");
set_value(19000);
set_weight(1);
}
void init(){
  ::init();
  add_action("do_read","morph");
  }
do_read(string arg){
object cret;
if(!present(arg, environment(this_player()))) {
write("Morph what?\n");
return 1;
}

else if(this_player()->query_int() >= random(50)){
cret = present(arg, environment(this_player()));
if(query_once_interactive(cret)) {
 printf("You cannot do that to a player!\n");
 return 1;
}
filter_array(all_inventory(cret),#'destruct);
cret = present(arg, environment(this_player()));
destruct(cret);
write("You morph the "+arg+" into a sheep!\n");
cret = clone_object(bm+"/sheep.c");
move_object(cret,environment(this_player()));
destruct(this_object());

return 1;
}
else {
write("You are not capable on morphing this creature.\n");
return 1;
}
}

