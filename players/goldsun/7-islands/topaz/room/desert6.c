inherit "/players/goldsun/gen/room/genDesert";
#define PATH "players/goldsun/7-islands/topaz/room/"

reset(arg){
if (!arg){
 clone_list=({1,2,"sandworm","players/goldsun/7-islands/topaz/monster/sandworm",0,
	    2,1,"creature","players/goldsun/7-islands/topaz/monster/creature",0});
 set_type("sandy");
 set_name("Topaz");
 set_storm(12,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    PATH+"desert7","north",
	        PATH+"desert16","northeast",
	        PATH+"desert5", "southwest",
		PATH+"desert9", "west",
		PATH+"desert8","northwest"
	   });
}
 ::reset(arg);  
}

