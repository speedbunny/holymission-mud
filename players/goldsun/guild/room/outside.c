inherit "/room/room";
#define CN "Lithius Castle"

void reset(int arg){
 if (!arg){
  set_light(1);
  short_desc="In front of "+CN;
  long_desc="You are standing in front of great "+CN+". This is fighters "+
	    "stronghold. Castle is build of shiny black stone. The walls "+
	    "are sturdy and high. To the north you can see large gate and "+
	    "narrow path leads down to the south.\n";
   
 smell="You can smell nothing strange";

 dest_dir=({ "/players/goldsun/guild/room/hall","north",
	     "/room/eastroad5","down"});

 items=({"walls","The walls are made of shiny black stone",
	 "wall","The wall is made of shiny stone",
	 "shiny stone","Very nice black shiny stone",
         "gate","Large gate. It is made of heavy oak wood",
	 "path","A narrow path leads down"
       });

  }
 ::reset();
 replace_program("room/room");
}

