inherit "/room/room";
#define NA "Lithius Castle"

void reset(int arg){
 if (!arg){
  set_light(1);
  short_desc="Castle hallway";
  long_desc=
  "This is a hallway in "+NA+". The walls are made of shiny\n"
 +"black stone. There is a throne on the north side of the room.\n"; 

 smell="You can smell nothing strange";

 dest_dir=({ "/players/goldsun/guild/room/boxes" ,"west",
	     "/players/goldsun/guild/room/tower1","east",
	     "/players/goldsun/guild/room","south"});

 items=({"walls","The walls are made of shiny black stone",
	 "wall","The wall is made of shiny stone",
	 "hall",long_desc,
	 "shiny stone","Very nice black shiny stone",
	 "throne","It is large golden throne with beautiful ornaments"
       });

  }
 replace_program("room/room");
}

