inherit "room/room";
#include "../harbour.h"

void reset(int arg){
 ::reset(arg);
 if (arg) return;
 set_light(1);
 short_desc=("In the Romlade's cottage");
 long_desc=
   "You are in the Romlade's cottage. Whole cottage is made of teak.\n"
   "In the walls are two windows. You have a nice view to harbour through\n"+
   "them. In the corner is a table with several chairs. Near the table is\n"+
   "a cupboard and bed. You can see a dirty pan on the stove in the left\n"+
   "corner. There is a small shelf with fishing tools above the bed.\n";


 smell="You smell teak";

 items=({"table","Wooden table. It looks old. There is nothing on it",
         "chair","It is made of wood",
         "cupboard","Wooden cupboard. It's closed and don't looks you could\n"+
                    "open it",
         "stove","Small stove in the corner with pan on it",
         "pan","The pan is dirty",
         "ceiling","There are fishing nets hanging down from it",
         "tools","The fishing tools. Romlade is a fisher",
         "shelf","A small shelf over Romlade's bed"
        });
 dest_dir=({ 
	ROOM + "road012","south",
           });

  CM("fisher");
  
}
