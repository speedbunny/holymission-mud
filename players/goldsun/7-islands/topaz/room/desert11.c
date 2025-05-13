inherit "/players/goldsun/gen/room/genDesert";
#define PATH "players/goldsun/7-islands/topaz/room/"

reset(arg){
if (!arg){
 clone_list=({1,1,"vulture","players/goldsun/7-islands/topaz/monster/vulture",0});
 set_type("sandy");
 set_name("Topaz");
 set_storm(10,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    PATH+"desert13","north",
	        PATH+"desert14","northeast",
	        PATH+"desert10","east",
		PATH+"desert4","southeast",
		PATH+"desert3","south",
		PATH+"desert2", "southwest",
		PATH+"desert12","west"
	   });
}
 ::reset(arg);  
}

