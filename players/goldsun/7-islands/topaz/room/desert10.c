inherit "/players/goldsun/gen/room/genDesert";
#define PATH "players/goldsun/7-islands/topaz/room/"

reset(arg){
if (!arg){
 clone_list=({1,1,"creature","players/goldsun/7-islands/topaz/monster/creature",0});
 set_type("sandy");
 set_name("Topaz");
 set_storm(10,11);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    PATH+"desert14","north",
	        PATH+"desert9","northeast",
	        PATH+"desert5","east",
		PATH+"desert4","south",
		PATH+"desert3","southwest",
		PATH+"desert11", "west",
		PATH+"desert13","northwest"
	   });
}
 ::reset(arg);  
}

