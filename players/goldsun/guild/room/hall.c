inherit "/room/room";
#define NA "Lithius Castle"

void reset(int arg){
 if (!arg){
  set_light(1);
  short_desc="Castle hallway";
  long_desc=
  "This is a hallway in "+NA+". The walls are made of shiny\n"
 +"black stone. There are two small passages with small signs on the walls.\n"+
  "They leads to the west and to the east. You can see large gate to the south.\n";

 smell="You can smell nothing strange";
 dest_dir=({ "/players/goldsun/guild/room" ,"north",
	     "/players/goldsun/guild/room/pub","west",
	     "/players/goldsun/guild/room/outside","south",
	     "/players/goldsun/guild/room/other_shop","east"});

 items=({"walls","The walls are made of shiny black stone",
	 "wall","The wall is made of shiny stone",
	 "sign","Look at west sign or east sign",
	 "west sign","    'Castle pub'",
	 "east sign","    'Castle shop'",
	 "gates","Castle gates",
	 "hall",long_desc,
	 "shiny stone","Very nice black shiny stone",
	 "passage","This passage leads to the west",
	 "passage 1","This passage leads to the west",
	 "passage 2","This passage leads to the east",
	 "passages","There are two passages. One leads to the west\n"
	   		+"and the seccond leads to the east"
       });

  }
 ::reset();
 replace_program("room/room");
}

