inherit "/players/brainsprain/goldsun/7-islands/rooms/rgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 if (!arg){
 clone_list=({
  1,random(3),"coast_monster",im+"/coast_monster",0});
 dest_dir=({ 
  ir+"/rcoast6","north",
  ir+"/vulcano16","southwest"
	   });
  
 }
 ::reset(arg);
}
