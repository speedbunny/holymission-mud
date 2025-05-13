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
"Several stones sit in the corner in what seems to be a religious "+
"pattern.  One stone sits about six inches higher than the rest of them.  "+
"The walls are covered in small cracks, one of which opens up to an "+
"alcove in the western wall.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room603","northwest",
    sr+"/room605","east",
  });
  items = ({
    "alcove",
    "A small hole in the wall",
    "stones",
    "Pieces of granite arranged in an obscure shape",
      });
::reset(arg);
}
void init(){
    ::init();
    add_action("search","search");
}
