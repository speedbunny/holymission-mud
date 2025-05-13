inherit "/players/goldsun/gen/room/genDesert";
#define PATH "players/goldsun/7-islands/topaz/room/"

reset(arg){
if (!arg){
 set_type("sandy");
 set_name("Topaz");
 set_storm(10,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    PATH+"desert10","north",
	        PATH+"desert5","northeast",
		PATH+"coast4", "south",
		PATH+"desert3","west"
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
