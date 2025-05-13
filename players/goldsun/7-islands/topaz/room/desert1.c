inherit "/players/goldsun/gen/room/genDesert";
#define PATH "players/goldsun/7-islands/topaz/room/"

reset(arg){
if (!arg){
 clone_list=({1,1,"sandworm","players/goldsun/7-islands/topaz/monster/sandworm",0,
	    2,4,"native","players/goldsun/7-islands/topaz/monster/native",0});
 set_type("sandy");
 set_name("Topaz");
 set_storm(7,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    PATH+"desert12","northeast",
		PATH+"desert2","east",
		PATH+"coast1", "south"
	   });
}
 ::reset(arg);  
}

init(){
 ::init();
 add_action("down","south");
}


down(){
 write("   ***** You are F A A *********\n\n");
 write("   ***** A A A A A A A *********\n\n");
 write("   ***** a a a a a a a *********\n\n");
 write("   ***** a a a l i n g *********\n\n");
 return ::move("south");
}
