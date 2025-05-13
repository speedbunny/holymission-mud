/* This is the SE - Corner */

#include "/players/tamina/defs.h"
inherit "room/room";

reset(arg) {

     set_light(0);
     short_desc = "East Wing";
     long_desc = 
   "The murky sunlight that filtered into the courtyard is suddenly gone\n"+ 
   "when you enter the darkened corridorin the east wing.  You are glad\n"+ 
   "however for your light, which is casting strange shadows against the\n"+ 
   "walls.  On the walls themselves are the rotten remains of old, old \n"+
   "tapestries, hanging limply on the grimy walls.  The corridor itself\n"+
   "turns and stretches into the gloomy north.  To your right, you can see\n"+
   "the rooms where the guards of the castle at one time stayed.\n";

     dest_dir = ({
   CROOMS + "ecorridor","north",
   CROOMS + "ecourt1","west",    
   CROOMS + "barracks","enter",
     });

     items = ({
    "tapestries",
  "What once must have been very grandiose tapestries, depicting great "+
  "battle scenes, are now sorry remnants of their past glory",
    "corridor",
  "Very gloomy, and not very inviting",
    "rooms",
  "These appear to be the disused barracks of the Castle Guards",
    "shadows",
  "Dancing shapes, that flit and shimmer in the gloom",  
     });

    ::reset (arg);

    RPR("room/room");
}
