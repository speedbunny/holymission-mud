#include "/players/tamina/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

     set_light(0);
     short_desc = "East Wing (portal, w, n)";
     long_desc = 
   "The murky sunlight that filtered into the courtyard is suddenly gone\n"+ 
   "when you enter the darkened corridorin the east wing.  The darkness\n"+ 
   "not seem natural to you...  You are glad however for your light, which\n"+ 
 "is casting strange shadows against the walls.  On the walls themselves\n"+
   "are the rotten remains of old, old tapestries, hanging limply on the \n"+
   "grimy walls.  The corridor itself stretches on into the gloomy north.\n"+
   "To your right, you can see the rooms where the guards of the castle\n"+
   "at one time stayed.\n";

     dest_dir = ({
   CROOMS + "ecorridor","north",
   CROOMS + "courtyard","west",    
   CROOMS + "barracks","enter",
     });

     items = ({
"tapestries","What once must have been very grandiose tapestries, depicting\n"
             "great battle scenes, are now sorry remnants of their past\n"
             "glory",
"corridor","Very gloomy, and not very inviting",
"rooms","These appear to be the disused barracks of the Castle Guards",
       });

}
