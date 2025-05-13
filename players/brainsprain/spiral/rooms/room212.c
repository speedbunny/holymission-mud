inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
int found;

int search (string arg){
object bottle;
int w;
if(arg != "crack") {
write("You search and find nothing...\n");
return 1;
}
if (arg == "crack") {
    if(!found) {
    write("You find a bottle in the crack.\n");
    say(capitalize(this_player()->query_name())+" finds a bottle.\n");
bottle=clone_object(si+"/bottle");
transfer(bottle,this_player());
    found=1;
    return 1;
  }
    if(found){
    write("You search the crack, but find nothing.\n");
      return 1;
    }
}
}

void reset(int arg){

  short_desc = "Swirling Walls";
  long_desc =
"Hunks of metamorphic rock lie on the ground.  The walls are formed of "+
"swirled rocks, that look as if someone stirred the walls.  Along the "+
"northern wall is a crack that runs from floor to ceiling.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room211","west",
    sr+"/room213","east",
  });
  items = ({
    "walls",
    "The walls form intricate, strangely beautiful patterns",
    "rock",
    "Pieces of marble that lie scattered across the floor",
    "crack",
    "A crack, about five inches wide in the center",
      });
    ::reset(arg);
}
void init(){
    ::init();
    add_action("search","search");
}
