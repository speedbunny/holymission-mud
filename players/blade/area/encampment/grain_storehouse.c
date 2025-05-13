inherit "room/room";

#include "/players/blade/area/blade_defs.h"
inherit ROOM_FUNCTS ;

reset(arg){
  int mon_numbers;

   if(!arg) {
        set_light(1);
        short_desc="A food storage room";
        long_desc=
"You are in a room which look like it houses enough food to feed an army.\n"+
  "Bags of grain are stacked all over the room.  Shelves hold enormous\n"+
  "amounts of other provisions.  You see cheese, kegs of beer, many kegs\n"+
  "of water, and what looks like coffee beans.  The room in unnaturally\n"+
  "quiet, and you think you should leave before someone discovers you in\n"+
  "here.\n";
   dest_dir=({
            CAMPPATH+"encampment3.c", "east",
	    CAMPPATH+"mess_hall.c","south",
                 });
   items=({ 
    "bags","These grain bags are stacked in orderly piles all around",
    "grain","Grains of all kinds are contained within the bags",
    "shelves","Rows of shelves that hold various provisions",
    "provisions","Many provisons line the shelves.  Perhaps you would like to look at\n something specific?",
    "cheese","Stacks of cheese line the shelves."
    "kegs","Many kegs are in this room.  Maybe you would like to look at a specific one",
    "kegs of beer","These kegs are filled with cheap beer",
    "kegs of water","These kegs are leaking on the floor",
    "water","Water spilled on the floor from a leaky keg",
    "coffee","Unground coffee beans",
    "beans","Unground coffee beans",
    "leaky keg","A keg of water that is leaking all over the floor",
  });
        smell = "You dont smell anything special";
      } 
 
    mon_numbers=(3-(filter_live(this_object(),"wolfen guard")));
   clone_x_of_y(mon_numbers,"/players/blade/area/monsters/wolfen_guard");
}












