inherit "/players/goldsun/lank/room/genCoast";

#define PPATH "/players/goldsun/lank/room/"

#include "/players/goldsun/gen/harb.h"

#define TP this_player()
#define CENTRAL_HARBOUR "players/goldsun/gen/room/central_harb"

string *boat_land;  /*  boat(s) that land here */

reset(arg){
 ::reset(arg);
 boat_land=({"atlanta","pinta"});
 if (arg) return;
 dest_dir=({PPATH + "coast2.c" , "northeast",
	    PPATH + "coast5.c" , "southeast",
	    PPATH + "lank1.c"  , "east"});
}


init(){
int i;

 ::init();
 
 if (TP && !TP->query_npc())
  for(i=0;i<sizeof(boat_land);i++)
    CENTRAL_HARBOUR->call_boat(file_name(this_object()),boat_land[i]);
  
}

     
