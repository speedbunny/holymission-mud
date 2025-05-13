inherit "/room/room";

#include "/players/haplo/defs.h"

void reset(int arg) {
    if(!arg) {   
        set_light(1);
        
        short_desc = "Island";
        long_desc = "\
You stand before a door leading into what looks like a small pyramid. The \
wind is whipping around you stirring up the desert sand. The sun continues \
to beat mercilessly down on you.\n";

        dest_dir=({
         "/players/haplo/desert/rooms/path5","south",
        });
           
        items = ({
    "door","The door has some writing and a wierd symbol that should be examined closer",
    "triangle","Probably represents unity of the Eygptian nation. The indents \
seem to draw your attention",
   "symbol","It is the sun with a triangle in the center. There are indents \
at each corner of the triangle",
  "sand","It's a desert what do you think there would be",
  "sun","It is very hot and bright",
  "writing","BEWARE all who would enter this tomb lest the Pharoah's Curse \
take you. For all who enter through this door shall not be able to exit here",
   "indents","You might try pushing the indents on the triangle's corners",
   "corners","The corners look sorta like they could be pushed in",
   "sun","Probably represents Ra the Eygptian Sun god"
        });
           
        property = ({
        });
    }
    ::reset(arg);
}
init(){
 ::init();

    add_action("_push","push");
  }

_push(str){
 
  if(str == "indents" || str == "in indents"){
write("The door swings open and you walk through.\n");
this_player()->move_player("into the pyramid",
                           "/players/haplo/desert/rooms/pyramid1");
write("The door slams shut behind you sealing you in the pyramid!\n");
return 1;
}
 else{
  notify_fail("You aren't doing it properly.\n");
  return 0;
}
}
