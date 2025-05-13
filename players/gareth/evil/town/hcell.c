inherit "room/room";
#include "/players/gareth/define.h"
reset(arg) {
  ::reset(arg);
  if(!arg) {

  set_light(1);
  short_desc = "Holding cell";
  long_desc = 
   "This room appears to never have been used.  It was intended to hold\n"+ 
   "trespassers and other prisoners who are caught by the guards.  Unfortunately\n"+
   "the drow don't take prisoners.  The cell is reinforced with metal bars\n"+ 
   "and is furnished with straw, a basin and leg irons.\n";
  
  items = ({
    "straw","A patch of straw for would be prisoners to sleep on",
    "basin","A basin for prisoners to relieve themsleves",
    "irons","Shackles for prisoners that become difficult to control",
    });
  
  dest_dir = ({
    ETOWN+"lvl1","up",
    
     });

}
}
