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
 dest_dir=({    PATH+"desert9","north",
	        PATH+"desert6","northeast",
		PATH+"desert4", "southwest",
		PATH+"desert10","west",
	        PATH+"desert14","northwest"
	   });
}
 ::reset(arg);  
}

