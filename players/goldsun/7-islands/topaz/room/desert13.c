inherit "/players/goldsun/gen/room/genDesert";
#define PATH "players/goldsun/7-islands/topaz/room/"

reset(arg){
if (!arg){
 set_type("sandy");
 set_name("Topaz");
 set_storm(5,13);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    PATH+"desert15","northeast",
	        PATH+"desert14","east",
	        PATH+"desert10","southeast",
		PATH+"desert11", "south",
		PATH+"desert12","southwest"
	   });
}
 ::reset(arg);  
}

