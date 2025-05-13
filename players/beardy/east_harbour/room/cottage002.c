inherit "room/room";
#include "../harbour.h"

void reset(int arg){
 ::reset(arg);
 if (arg) return;
 set_light(1);
 short_desc=("In the Fubioso's cottage");
 long_desc=
   "You are in the Fubioso's cottage. You can see a table with the chairs\n"+
   "in the middle of it, stove in the right corner and fishing rod with\n"+
   "fishing boots in the left corner. There are bed and cupboard by the walls.\n" +
   "This cottage is large with two windows. The floor is made of oak wood\n"+
   "and looks clearly.\n";
 smell="You smell salty air";
 items=({"table","Wooden table. It looks old. There is nothing on it",
         "chair","It is made of wood",
	"cupboard","It's made out of wood",
                    "open it",
         "stove","Small stove in the corner",
	"floor","It's a wooden floor and you can see no dust at all",
         "rod","A long fishing rod",
         "boots","Fubioso's fishing boots. They are wet"
        });
 dest_dir=({ 

	ROOM + "road008","east",
           });
  
  CO("note");
}
