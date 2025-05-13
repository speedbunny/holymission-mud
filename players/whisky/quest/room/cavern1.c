#include "../monkway.h"
inherit "room/room";
  

reset(arg) {

  ::reset(arg);
  

  if (arg) return;
  smell="You  smell blooming flowers !";
  set_light(0);
  short_desc = "In a dark cavern";
  long_desc =
    "You are standing in a dark cavern. There are stones all around you.\n"+
    "The bottom is dark and earthy. It's really cold and wet here.\n"+
    "The cavern leads further to the east and west.\n";
   
    
  items =
    ({    
     "stones","Some big black stones",      
     "bottom","A dark and earthy bottom",
      });
  
  dest_dir= ({
      PATH+"rock","east",
      PATH+"cavern2","west",
      });
    
  }

  init() {
    add_action("search","search");
    add_action("pass","pass");
    add_action("pass","climb");
    add_action("take","get");
    ::init();
   }

 
     
  search(arg) {
    if (!arg) return;
    write("You search around, but find nothing.\n");
    say(TPN+" searches around.\n");
    return 1;
   }
     
   
  take(arg) {
    if (arg!="stones" || arg!="stone") return;
    write("You can't take them they are too heavy for you.\n");
    return 1; 
   }
    
