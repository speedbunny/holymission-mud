
inherit "room/room";

#include "/players/goldsun/gen/harb.h"   /* !!! this is a function
					which we need */

#define TP this_player()
#define CENTRAL_HARBOUR "players/goldsun/gen/room/central_harb"

string *boat_land;  /*  boat(s) that land here */

void reset(int arg){
 if (!arg){
       boat_land=({"atlanta"});   /* here write boat names that */
	  			 /* land here. This is for faster code */
		 
       set_light(1);
       short_desc=("Estern harbour");
       long_desc=("You are on the pier of Eastern harbour.\n");
  }
 ::reset(arg);
}

/*   this call boat if it is in central harbour   */
/*   copy this init				  */

init(){
int i;

 ::init();
 
 if (TP && !TP->query_npc())
  for(i=0;i<sizeof(boat_land);i++)
    CENTRAL_HARBOUR->call_boat(file_name(this_object()),boat_land[i]);
  
}

     
