#include "std.h"
#include "../../../../obj/door.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
object obj_1,obj_2,key_obj,drunkard,amulet;
extra_reset() {


    MAKE_DOORS("players/topaz/angmar/fairyland/mountain","north","players/topaz/angmar/fairyland/tunnel","south","iron","auxd","A heavy door made of stone.\n",0,1,0)




/*    MAKE_KEY(key_obj,"big iron","auxd") */
}

TWO_EXIT("players/topaz/angmar/fairyland/mountain_top","up",
         "players/topaz/angmar/fairyland/mountain_foot","down",
"Misty Mountain",
"You are climbing misty mountain.\n",1)
