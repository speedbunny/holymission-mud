inherit "/players/goldsun/gen/room/genDesert";
#define PATH "players/goldsun/7-islands/topaz/room/"

reset(arg){
if (!arg){
 clone_list=({1,3,"sandworm","players/goldsun/7-islands/topaz/monster/sandworm",0,
	    2,1,"native","players/goldsun/7-islands/topaz/monster/native",0});
 set_type("sandy");
 set_name("Topaz");
 set_storm(10,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    PATH+"desert11","north",
	        PATH+"desert10","northeast",
	        PATH+"desert4","east",
		PATH+"desert2", "west",
		PATH+"desert12","northwest"
	   });
}
 ::reset(arg);  
}

