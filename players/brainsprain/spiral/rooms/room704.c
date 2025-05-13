inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
int found;

search (arg){
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
"An aqueduct rises out of the ground.  Water rushes along the aqueduct "+
"and goes through a hole in the southern wall.  Along the western wall "+
"there is an alcove.  The walls and floor are slippery with condensation.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room703","northeast",
    sr+"/room705","south",
  });
  items = ({
    "alcove",
    "A small hole in the wall",
    "aqueduct",
    "A wooden trough",
      });
::reset(arg);
}
void init(){
    ::init();
    add_action("search","search");
}

