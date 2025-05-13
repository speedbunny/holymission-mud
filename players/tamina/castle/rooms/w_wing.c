#include "/players/tamina/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

     set_light(0);
     short_desc = "West Wing (enter fountain, e, n)";
     long_desc = 
   "The mirky sunlight that filtered into the courtyard is suddenly gone\n"+ 
   "when you enter the darkened corridor.  The darkness does not seem\n"+
   "natural to you...  You are glad however for your light, which is\n"+ 
   "casting strange shadows against the walls.  On the walls themselves\n"+
   "are the rotten remains of old, old tapestries, hanging limply on the \n"+
   "grimy walls.  The corridor itself stretches on into the gloomy north.\n"+
   "To your left, you can see what seems to be a store room of sorts.\n";
     
       dest_dir = ({
   CROOMS + "wcorridor","north",
   CROOMS + "courtyard","east",    
   CROOMS + "store_room","enter",
     });

}
