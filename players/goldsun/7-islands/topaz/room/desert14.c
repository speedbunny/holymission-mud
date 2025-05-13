inherit "/players/goldsun/gen/room/genDesert";
#define PATH "players/goldsun/7-islands/topaz/room/"

reset(arg){
if (!arg){
 clone_list=({1,3,"sandworm","players/goldsun/7-islands/topaz/monster/sandworm",0,
	    2,1,"dragon","players/goldsun/7-islands/topaz/monster/dragon",0,
            3,2,"vulture","players/goldsun/7-islands/topaz/monster/vulture",0});
 set_type("sandy");
 set_name("Topaz");
 set_storm(8,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    PATH+"desert15","north",
	        PATH+"desert8","northeast",
	        PATH+"desert9","east",
		PATH+"desert5","southeast",
		PATH+"desert10","south",
		PATH+"desert11","southwest",
		PATH+"desert3", "west"
	   });
}
 ::reset(arg);  
}

init(){
 ::init();
 add_action("enter","enter");
}


int enter(){
 write("Dune is closed now.\n");
 return 1;
}
