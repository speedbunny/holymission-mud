inherit "/players/goldsun/7-islands/diamond/room/genInland";
#define PATH "players/goldsun/7-islands/diamond/room/"

void reset(int arg){
if (!arg){

 clone_list=({1,1,"man","players/goldsun/7-islands/diamond/monster/snow_man",0,
              2,1,"yeti","players/goldsun/7-islands/diamond/monster/yeti",0,
	      3,1,"wolf","players/goldsun/7-islands/diamond/monster/wolf",0});

 dest_dir=({    PATH+"inland8","east"
	   });
 }
 ::reset(arg);  
}

