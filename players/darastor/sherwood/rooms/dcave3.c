inherit "/room/room";
#include "../dig.h"
#include "/players/patience/GenObj/move_blocked.h"

reset(arg){
if (!arg){ 
 clone_list=({1,1,"saliman","/players/goldsun/sherwood/monster/saliman",0,
 	      2,5,"gem","/players/goldsun/sherwood/obj/gem",0,
	      3,1,"gold","/players/goldsun/sherwood/obj/gold",0,
	      4,3,"diamond","/players/goldsun/sherwood/obj/diamond",0,
	      5,1,"silver","/players/goldsun/sherwood/obj/silver",0}); 
 
 set_light(0);
 short_desc=("A cave");
 long_desc=("You are in the dark small cave.\n"
	   +"You can see huge treasury here. A lot of\n"
           +"diamonds, gems, gold and silver are here.\n"
	   +"This place is not safe for you.\n");
 smell="You smell damp air.";

 dest_dir=({"/players/goldsun/sherwood/room/shwood20","up"});
 items=({"cave","Dark highwaymen cave",
	 "small cave","Dark highwaymen cave",
         "dark cave","This is Saliman's treasury",
	 "highwaymen cave","This is Saliman's treasury",
	 "treasury","You can see a lot of gold, silver, diamonds and gems"
		});
 }
 ::reset();
 }
 
init(){
 ::init();
add_action("dig","dig");
}

