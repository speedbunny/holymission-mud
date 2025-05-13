inherit "room/room";
#include "../harbour.h"

void reset(int arg){
 ::reset(arg);
 if (arg) return;
 set_light(1);
 short_desc=("In the Valerio's cottage");
 long_desc=
   "You are in the Valerio's cottage. It isn't large, but there is\n"+
   "enough room for a bed, wooden table with chairs, stove and \n"+
   "cupboard. Through a small window you can see a harbour. Large\n"+
   "fishing nets are hanging from the wooden ceiling. \n";

 smell="You smell salty air";
 items=({"table","Wooden table. It looks old. There is nothing on it",
         "chair","It is made of wood",
	"cupboard","It's a nice cupboard made of wood",
                    "open it",
         "stove","Small stove in the corner",
         "ceiling","There are fishing nets hanging down from it",
         "nets","Large fishing nets",
         "net","This fishing net looks new"
        });
 dest_dir=({ 
		ROOM + "road006","west",
           });

  CM("fisher");
  CM("fisher");
  
}
