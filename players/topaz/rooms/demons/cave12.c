inherit "room/room";

#include "/players/topaz/defs.h"

int found;
reset(arg) {
  found=0;
  if(!arg) {

     short_desc = "Demon's trash room";
     long_desc = "This is the demons' trash room.\n" +
                 "It stinks in here!!\n" +
                 "There is trash everywhere!  It's a trash room, sure,\n" +
                 "but this is ridiculous!  At least they could keep it a\n" +
                 "little bit neat!  Who knows what could be in that trash?!\n";

      dest_dir = ({"players/topaz/rooms/demons/cave11","northeast",
 
                     });

     items =({"room","There is trash all over the place",
              "trash","It could contain anything.  Maybe you should search it",
              });
       set_light (1);
       smell="Your nose refuses to obey you!";
return 1; }}

init() {
  ::init();

    add_action("_search","search");
}

_search(str) {
  object gemstone;
  if(!id(str)) {
  write("Search what?\n");
  return 1;
  }
  if((str=="trash"||str=="the trash") && !found) {
  write("You search the trash and find a small gem!\n");
  say(TP->query_name() + " searches the trash and finds something.\n");
  transfer(gemstone=clone_object(OBJS + "demons/gemstone"),TP);
  found=1;
  return 1;
  }
}
