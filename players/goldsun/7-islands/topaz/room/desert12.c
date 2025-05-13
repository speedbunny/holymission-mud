inherit "/players/goldsun/gen/room/genDesert";
#define PATH "players/goldsun/7-islands/topaz/room/"

reset(arg){
if (!arg){
 clone_list=({1,1,"creature","players/goldsun/7-islands/topaz/monster/creature",0});
 set_type("sandy");
 set_name("Topaz");
 set_storm(7,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    PATH+"desert13","northeast",
	        PATH+"desert11","east",
		PATH+"desert3","southeast",
		PATH+"desert2", "south",
		PATH+"desert1","southwest"
	   });
}
 ::reset(arg);  
}

