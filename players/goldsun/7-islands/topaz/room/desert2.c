inherit "/players/goldsun/gen/room/genDesert";
#define PATH "players/goldsun/7-islands/topaz/room/"

reset(arg){
if (!arg){
 clone_list=({1,2,"native","players/goldsun/7-islands/topaz/monster/native",0});
 set_type("sandy");
 set_name("Topaz");
 set_storm(8,12); 
 items=({"topaz",long_desc
         });
 dest_dir=({    PATH+"desert12","north",
	        PATH+"desert11","northeast",
		PATH+"desert3", "east",
		PATH+"desert1","west"
	   });
}
 ::reset(arg);  
}

