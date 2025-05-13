inherit "/players/goldsun/gen/room/genDesert";
#define PATH "players/goldsun/7-islands/topaz/room/"

reset(arg){
if (!arg){
 clone_list=({1,3,"creature","players/goldsun/7-islands/topaz/monster/creature",0,
	    2,1,"native","players/goldsun/7-islands/topaz/monster/native",0,
	    3,1,"dragon","players/goldsun/7-islands/topaz/monster/dragon",0});
 set_type("sandy");
 set_name("Topaz");
 set_storm(5,21);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    PATH+"desert8","west",
	        PATH+"desert16","east",
		PATH+"desert6", "south",
		PATH+"desert9","southwest"
	   });
}
 ::reset(arg);  
}
