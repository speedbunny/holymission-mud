#include "../monkway.h"
inherit "room/room";
   object bush;
  

reset(arg) {
   if (!bush) {
      bush=clone_object("players/whisky/quest/obj/bush");
      move_object(bush,this_object());
      }

  ::reset(arg);
  

  if (arg) return;
  set_light(1);
  short_desc = "On a path";
  long_desc =
    "You are standing on a path to the entrance of a dark forest.\n"+
    "The forest looks so dark that you shiver from going further.\n"+
    "You can see a lit meadow to the south and some big rocks to \n"+
    "the east and west.\n";
   
    
  items =
    ({    
     "forest","The dark forest makes you shiver, it looks like the head of a devil",      
     "bottom","A dark and earthy bottom",
     "rocks","Some big black rocks",
     "meadow","You see a beautiful, lit meadow to the south",
      });
  
  dest_dir= ({
      PATH+"forest/f1","north",
      PATH+"meadow12","south",
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
    if (arg!="rock" || arg!="rocks") return;
    write("You can't take them they are too heavy for you.\n");
    return 1; 
   }
    
