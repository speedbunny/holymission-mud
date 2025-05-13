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
torch=clone_object("/obj/torch");
transfer(torch,this_player());
w=w-1;
return 1;
}
  if(w){
  write("There is no torch.\n");
  return 1;
}
}
}

void reset(int arg){
  short_desc = "Storage room";
  long_desc =
"This room is filled to the brim with torches.  They lie strewn about the "+
"room in typical orcish organizational patterns.  There are at least one "+
"hundred torches stacked in this room\n";
    w = 10;
    set_light(0);
    dest_dir = ({
    sr+"/room707","southeast",
    sr+"/room705","northwest",
  });
items = ({
  "torches",
  "Wow there are a lot of them, try 'get'ting one",
      });
  clone_list = ({ 
       1, 2, "monster", sm+"/orc_guard.c", 0,
       2, 1, "mon2", sm+"/orc_taskmaster.c", 0,
        });
  ::reset(arg);
}
void init(){
  ::init();
  add_action("get","get");
  }
