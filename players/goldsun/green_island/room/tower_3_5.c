inherit "/players/goldsun/green_island/room/top_tower";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){

 dest_dir=({ PATH + "tower_3_4", "down"});
 }

 ::reset(arg);
 replace_program("/room/room");
}



