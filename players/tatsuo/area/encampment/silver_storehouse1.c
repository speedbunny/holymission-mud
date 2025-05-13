inherit "room/room";

#include "/players/tatsuo/area/tatsuo_defs.h"
#include "/players/tatsuo/area/room_functs.c"

reset(arg){
int mon_numbers;
   if(!arg) {
        set_light(1);
        short_desc="A small room";
        long_desc=
"You have entered a small room.  In the corner is a table and a book.\n"+
  "A scribe is stationed by the table, writing what enters and leaves\n"+
  "the room in a logbook.  A very strong door lies to the east\n"+
  "encampment.  At points the platform gets so narrow you have to look down\n"+
  "to walk or risk falling off.  The platform continues east and west along\n"+
  "the palisade.  Stairs also lead down.\n";
   dest_dir=({
            CAMPPATH+"silver_storehouse2.c", "east",
	    CAMPPATH+"encampment5.c", "west",
                 });
   items=({ 
     "wolfen","A large burly wolfen guard who eyes you warily",
     "table","A small table in the corner with a book resting on it",
     "book","A fat log of everything that has entered and left the east room",
   });
        smell = "You dont smell anything special";
     }  
    mon_numbers=(6-(filter_live(this_object(),"wolfen guard")));
    clone_x_of_y(mon_numbers,"/players/tatsuo/area/monsters/awolfen_guard");
    mon_numbers=(1-(filter_live(this_object(),"wolfen scribe")));
    clone_x_of_y(mon_numbers,"/players/tatsuo/area/monsters/wolfen_scribe");
}







