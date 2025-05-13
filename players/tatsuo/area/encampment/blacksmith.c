inherit "room/room";

#include "/players/tatsuo/area/tatsuo_defs.h"
inherit ROOM_FUNCTS ;

reset(arg){
  int mon_numbers;

   if(!arg) {
        set_light(1);
        short_desc="The blacksmith shop";
        long_desc=
  "A cramped area where four smiths toil night and day, making the metal\n"+
  "products necessary to continue the mine's operation.  This includes\n"+
  "nails, tools, picks, axes, wheel rims, keys, locks, horseshoes, and\n"+
  "numerous other products.\n";
   dest_dir=({
            CAMPPATH+"horse_stables.c", "south",
	    CAMPPATH+"encampment4.c","west",
                 });
   items=({ 
    "products","There are many products.  Which would you like to look at",
    "nails","A few nails are cooling off in a bucket",
    "tools","Many tools are in the process of being made",
    "picks","These broken picks are here to be repaired",
    "axes","These axes need sharpening",
    "wheel rims","Freshly made wheel rims are in the corner",
    "keys","Keys hang from a nail in the wall",
    "locks","New locks lie on a small table in the corner",
    "horseshoes","These horseshoes are cooling off"
    "bucket","A bucket filled with water and nails",
    "water","Water fills a bucket and cools off newly made nails",
  });
        smell = "You smell nothing special.";
      }
    mon_numbers=(4-(filter_live(this_object(),"wolfen blacksmith")));
    clone_x_of_y(mon_numbers,"/players/tatsuo/area/monsters/wolfen_blacksmith");
}












