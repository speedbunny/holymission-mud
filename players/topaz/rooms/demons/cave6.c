inherit "room/room";

#include "/players/topaz/defs.h"

object topazdemon;
int found;
reset(arg) {
  found=0;

  if(!topazdemon) {
     move_object(topazdemon=clone_object(MNST + "demons/guard"),TO);
  }
  if(arg) return;
     short_desc = "A dark passageway";
     long_desc = "As you walk into the room you are surprised to see a\n" +
                 "desk in one corner.  A very little bit of light comes\n" +
                 "from the tunnel to the east, but not enough to see by.\n" +
                 "From the south you hear some growling and moaning.\n";

      dest_dir = ({"players/topaz/rooms/demons/cave5","east",
                   "players/topaz/rooms/demons/cave7","south",
 
                     });

     items =({"passageway","It is dark",
              "desk","The desk looks important",
              "the desk","The desk looks important",
              });
       set_light (0);
       smell = "You still smell faint traces of smoke.";
}
init(){
  ::init();

        add_action("search", "search");
        }

search(str) {
     object key;
     if(!id(str)) {
     write("Search what?\n");
     return 1;
}
    if(present("topazdemon")) {
    write("The demon won't let you do that!\n");
    return 1;
}
    if((str=="desk" || str=="the desk") && !found){
    write("You search the desk and find a key!\n");
    say(this_player()->query_name() + " searches the desk and finds something.\n");
move_object(key=clone_object(OBJS + "demons/shacklekey"),this_object());
    found=1;
    return 1; }
}
