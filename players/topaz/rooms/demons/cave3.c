inherit "room/room";

#include "/players/topaz/defs.h"

int enter(string arg) {
    if(!arg) {
        notify_fail("Enter what?\n");
    }
    if(arg=="crevice"||arg=="the crevice") {
        write("You manage to squeeze yourself into the crevice.\n");
        say(TP->NAME + " manages to squirm into the crevice in the wall.\n");
        MP("into the crevice#players/topaz/rooms/demons/crevice");
    }
    else notify_fail("Enter what?\n");
    return 1;
}
reset(arg) {
  if(!arg) {

     short_desc = "A cavern";
     long_desc = "There is flickering light coming from the big cavern to the south.\n" +
                 "On the north wall you see a small crevice.\n";

      dest_dir = ({"players/topaz/rooms/demons/cave4","south",
                   "players/topaz/rooms/demons/cave1","west",
 
                     });

     items =({"crevice","The crevice looks big enough for you to fit in it",
              "north wall","The crevice looks big enough for you to fit in it",
              "wall","The crevice looks big enough for you to fit in it",
              "light","Flickering light.  Seems like firelight",
              });
       set_light (1);
       smell = "The stench of death is unmistakable.";
        property = ({"no_teleport",});
return 1; }}

init(){
  ::init();

       add_action("enter", "enter");
}
