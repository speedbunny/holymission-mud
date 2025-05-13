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
"In the center of the room is one single column, formed from where a "+
"stalactite and a stalagmite have met.  Along the eastern wall there is "+
"an alcove.  The walls have a ledge at about four feet high that runs all "+
"the way around the room.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room403","southwest",
    sr+"/room405","north",
  });
  items = ({
    "alcove",
    "A small hole in the wall",
    "column",
    "A pearly gray column",
      });
  ::reset(arg);
}
void init(){
    ::init();
    add_action("search","search");
}
