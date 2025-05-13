inherit "room/room";

#include "/players/blade/area/blade_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The lookout's tower",
        long_desc=
  "You are on top of a wooden platform placed behind the gateway.  The\n" +
  "lookout can call down to the gatekeeper whether the would be entrant\n"+
  "is friend or foe.  There are also two archers stationed here so that\n"+
  "any enemies of the encampment can be dealt with in an efficient manner.\n"+
  "A narrower platform continues east and west around the palisade.\n";
   dest_dir=({
            CAMPPATH+"palisade1.c", "east",
	    CAMPPATH+"palisade11.c", "west", 
                 });
   items=({ 
     "palisade","A large 18ft wall which encircles the encampment.  A wolfen guard stands on top",
     "wolfen","A large burly wolfen guard who eyes you warily",
     "platform","That is were the lookout and the guards stand",
   });

        smell = "You dont smell anything special";
	move_object((clone_object(MPATH+"wolfen_archer.c")),this_object());
	move_object((clone_object(MPATH+"wolfen_archer.c")),this_object());
	move_object((clone_object(MPATH+"wolfen_lookout.c")),this_object());
      }
    if(arg){
      if(!(present(this_object())&&(this_object()->query_name()=="wolfen lookout")))
	move_object((clone_object(MPATH+"wolfen_archer.c")),this_object());
      if(!(present(this_object())&&(this_object()->query_name()=="wolfen guard")))
	move_object((clone_object(MPATH+"wolfen_guard.c")),this_object());
    }
  }






