inherit "/room/room";

reset(arg){

 if (!arg){
 clone_list=({1,1,"valdir","/players/goldsun/guild/monster/valdir",0});
 set_light(1);
 short_desc="Castle treasury";
 long_desc="You are in the castle treasury. You can drop here your stuff.\n"
	  +"Only Knights can enter this room.\n";

 property=({"no_steal"});

 smell="You can smell fresh air";

 dest_dir=({ "/players/goldsun/guild/room/roundtable" ,"north",
	     "/players/goldsun/guild/room/admin" , "east",
	     "/players/goldsun/guild/room/library","up"});

 items=({"walls","The walls are made of shiny stone",
	 "wall","The wall is made of shiny stone",
	 "stone","Very nice white shiny stone",
	 "shiny stone","Very nice white shiny stone",
	 "stairs","The stairs leads up"
       });

  }
 ::reset(arg);
 replace_program("room/room");
}
