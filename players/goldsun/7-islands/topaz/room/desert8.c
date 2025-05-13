inherit "/players/goldsun/gen/room/genDesert";
#define PATH "players/goldsun/7-islands/topaz/room/"

reset(arg){
if (!arg){
 clone_list=({1,1,"sandworm","players/goldsun/7-islands/topaz/monster/sandworm",0,
	    2,1,"vulture","players/goldsun/7-islands/topaz/monster/vulture",0});
 set_type("sandy");
 set_name("Topaz");
 set_storm(10,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    PATH+"desert15","west",
	        PATH+"desert7","east",
	        PATH+"desert6","southeast",
		PATH+"desert9", "south",
		PATH+"desert14","southwest"
	   });
}
 ::reset(arg);  
}
