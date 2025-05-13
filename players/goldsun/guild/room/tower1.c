inherit "/room/room";
#define NA "Lithius Castle"

void reset(int arg){
 if (!arg){
  set_light(1);
  short_desc="Castle tower";
  long_desc=
  "This is a tower of "+NA+". The walls are made of shiny\n"
 +"black stone. \n";

 smell="You can smell nothing strange";

 dest_dir=({ "/players/goldsun/guild/room/hall2" ,"west"});

 items=({"walls","The walls are made of shiny black stone",
	 "wall","The wall is made of shiny stone",
	 "tower",long_desc,
	 "shiny stone","Very nice black shiny stone"
       });

  }
 replace_program("room/room");
}

