inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
int w;

int get(string str){
  object sword;
  if(str != "sword") {
    write("Get what?\n");
    return 1;
  }
if (str == "sword") {
  if (w >0) {
  write("You pick up the sword.\n");
  say(capitalize(this_player()->query_name())+" takes a sword.\n");
  sword=clone_object(si+"/sword");
transfer(sword,this_player());
w=w-1;
return 1;
}
  if(w){
  write("There is no sword.\n");
  return 1;
}
}
}

void reset(int arg){
  short_desc = "Orcish Armoury";
  long_desc =
"The walls are lined with shelves and racks containing swords.  Shields "+
"sit in the corner in a stack, strapped down.  An anvil sits in the center "+
"of the room.  Several discarded shards of metal lie around the anvil.\n";
    w = 10;
    set_light(0);
    dest_dir = ({
    sr+"/room702","northeast",
    sr+"/room704","southwest",
  });
items = ({
  "racks",
  "Racks filled with weapons",
  "shelves",
  "Shelves filled with weapons",
  "shields",
  "Large shields with an odd emblem on them",
  "anvil",
  "A massive anvil used to forge new weapons",
  "shards",
  "pieces of a broken sword",
  "swords",
  "Rusty swords that line then shelves and racks of this room",
      });
  ::reset(arg);
}

void init(){
  ::init();
  add_action("get","get");
  }
