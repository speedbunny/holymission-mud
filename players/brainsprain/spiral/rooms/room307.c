inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
int found;

int search (string arg){
object bottle;
int w;
if(arg != "alcove") {
write("You search and find nothing...\n");
return 1;
}
if (arg == "alcove") {
    if(!found) {
    write("You find a bottle in the alcove.\n");
    say(capitalize(this_player()->query_name())+" finds a bottle.\n");
bottle=clone_object(si+"/bottle");
transfer(bottle,this_player());
    found=1;
    return 1;
  }
    if(found){
    write("You search the alcove, but find nothing.\n");
      return 1;
    }
}
}

void reset(int arg){
  short_desc = "A dark room";
  long_desc =
"The walls of this room are lined with shelves.  They are about five "+
"feet long and two feet high.  There is also an alcove along the wall.  "+
"A fetid scent floats through the air.  The floor is covered in dust.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room306","east",
    sr+"/room308","west",
  });
  items = ({
    "alcove",
    "A small hole in the wall",
    "shelves",
    "On each shelf is the body of a dead goblin",
      });
  ::reset(arg);
}
void init(){
    ::init();
    add_action("search","search");
}
