#include "../monkway.h"
inherit "room/room";
    object bear;

  

reset(arg) {

    if (!bear) {
       bear=clone_object("players/whisky/quest/monster/cave_bear");
       move_object(bear,this_object());
      }
  ::reset(arg);
  

  if (arg) return;
  set_light(0);
  short_desc = "In a dark cavern";
  long_desc =
    "You are standing in a dark cavern. There are stones all around you.\n"+
    "The bottom is dark and earthy. It's really cold and wet here.\n"+
    "There is some moonlight coming from the west. The cavern leads\n"+
    "further to the east and west.\n";
   
    
  items =
    ({    
     "stones","Some big black stones",      
     "bottom","A dark and earthy bottom",
     "light","You see some moonlight shining into the dark cavern",
      });
  
  dest_dir= ({
      PATH+"swamps","west",
      PATH+"cavern1","east",
      });
    
  }

  init() {
    add_action("search","search");
/*
    add_action("pass","pass");
    add_action("pass","climb");
*/
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

status move(string arg)
{
   object mob;

    if (!arg)
        arg = query_verb();
    if (arg =="west" && (mob=present("cave bear",this_object())) &&
        living(mob))
    {
        write("You try to go west but the huge cave bear is in the way.\n");
        return 1;
    }
    return ::move(arg);
}

        
    
