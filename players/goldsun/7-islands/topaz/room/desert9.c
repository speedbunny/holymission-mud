inherit "/players/goldsun/gen/room/genDesert";
#define PATH "players/goldsun/7-islands/topaz/room/"

reset(arg){
if (!arg){
 clone_list=({1,3,"vulture","players/goldsun/7-islands/topaz/monster/vulture",0,
	    2,1,"creature","players/goldsun/7-islands/topaz/monster/creature",0});
 set_type("sandy");
 set_name("Topaz");
 set_storm(9,17);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    PATH+"desert8","north",
	        PATH+"desert7","northeast",
	        PATH+"desert6","east",
		PATH+"desert5","south",
		PATH+"desert10","southwest",
		PATH+"desert14", "west",
		PATH+"desert15","northwest"
	   });
}
 ::reset(arg);  
}
