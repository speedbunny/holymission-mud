inherit "/room/room";

reset(arg){
 if (!arg){
 clone_list=({1,3,"chest","/players/goldsun/nottingham/obj/g_chest",0,
	      2,1,"blade","/players/goldsun/obj/nothung_blade",0}); 
 set_light(1);
 short_desc=("Castle treasury");
 long_desc="You are in the small room with Nottingham treasure.\n"+
	   "You can see many chests with gold and silver in it.\n";
 
 smell="You smell gold and silver.";
 dest_dir=({"/players/goldsun/nottingham/room/castle/prison2","north"});

 items=({ "chests","A wooden chests with gold and silver" });
	  
 }
 ::reset(arg);
 replace_program("/room/room");
}

