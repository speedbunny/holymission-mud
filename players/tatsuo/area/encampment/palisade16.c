inherit "room/room";

#include "/players/tatsuo/area/tatsuo_defs.h"
#include ROOM_FUNCTS

reset(arg) {
  int mon_numbers;
    if(!arg) {
        set_light(1);
        short_desc="A narrow platform";
        long_desc=
"You are on top of a narrow wooden platform placed behind palisade.  Guards\n"+
  "are stationed at various points along the platform to guard against\n"+
  "attacks, and alert the others in the event of an assault on the\n"+
  "encampment.  At points the platform gets so narrow you have to look down\n"+
 "to walk or risk falling off.  The platform south along the palisade.\n";
   dest_dir=({
            CAMPPATH+"palisade15.c",   "south",
                 });
   items=({ 
     "palisade","A large 18ft wall which encircles the encampment.  A wolfen guard stands on top.",
     "wolfen","A large burly wolfen guard who eyes you warily",
     "platform","A narrow platform that runs the length of the palisade",
     "stairs","They lead down off of the palisade",
   });

        smell = "You dont smell anything special";
      }
    mon_numbers=(2-(filter_live(this_object(),"wolfen guard")));
    clone_x_of_y(mon_numbers,"/players/tatsuo/area/monsters/wolfen_guard");
}






