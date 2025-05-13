inherit "/room/room";
reset(arg){
 if (!arg){
 
  set_light(1);

  short_desc="Castle hallway";
  long_desc=
  "This is a hallway in Carmaalot castle. The walls are made of shiny\n"
 +"stone. The hallway continues to the west. To the north and south are\n"
 +"small passages with signs over them. On the east side are castle gates.\n"; 

 smell="You can smell nothing strange";
 dest_dir=({ "/players/goldsun/guild/room/other_shop" ,"south",
	     "/players/goldsun/guild/room","west",
	     "/players/goldsun/guild/room/stable","north",
	     "/players/goldsun/guild/room/carmaalot","east"});

 items=({"walls","The walls are made of shiny stone",
	 "wall","The wall is made of shiny stone",
	 "sign","Look at north sign or south sign",
	 "north sign","    'Castle stable'",
	 "south sign","    'Castle shop'",
	 "gates","Castle gates",
	 "hall","The hall is made of shiny stone",
	 "shiny stone","Very nice white shiny stone",
	 "passage","This passage leads to the south",
	 "passage 1","This passage leads to the south",
	 "passage 2","This passage leads to the north",
	 "passages","There are two passages. One leads to the north\n"
	   		+"and the seccond leads to the south"
       });

  }
 ::reset();
 replace_program("room/room");
}

