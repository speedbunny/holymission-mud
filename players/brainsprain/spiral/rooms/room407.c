inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
int w;

int get(string str){
object torch;
if(str != "torch") {
write("Get what?\n");
return 1;
}
if (str == "torch") {
  if (w >0) {
write("ok.\n");
say(capitalize(this_player()->query_name())+" takes a torch.\n");
torch = clone_object(si+"/torch");
move_object(torch, this_player());
w=w-1;
return 1;
}
  if(w=0){
  write("There is no torch.\n");
  return 1;
}
}
}


void reset(int arg){
  short_desc = "Storage room";
  long_desc =
"This room is filled to the brim with torches.  They lie strewn about the "+
"room in typical goblin organizational patterns.  There are at least one "+
"hundred torches stacked in this room.  What few sections of the wall are "+
"visible are a sickly green color.\n";
    w = 100;
    set_light(0);
    dest_dir = ({
    sr+"/room406","southeast",
    sr+"/room408","west",
  });
items = ({
  "torches",
  "Wow there are a lot of them, try 'get'ting one",
      });
  ::reset(arg);
}
void init(){
  ::init();
  add_action("get","get");
  }
