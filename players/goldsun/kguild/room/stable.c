inherit "/room/room";
reset(arg){

 if (!arg){
  clone_list=({1,3,"horse","/players/goldsun/guild/monster/horse",0});
  set_light(1);

  short_desc="Castle stable";
  long_desc=
  "You are in the castle stable. There are many box\n"
 +"for the knights horses. The walls are faced with teak wood.\n";
 

 smell="You can smell horse odour";
 dest_dir=({ "/players/goldsun/guild/room/hall" ,"south"});

 items=({"walls","The walls are made of shiny stone",
	 "wall","The wall is made of shiny stone",
	 "shiny stone","Very nice white shiny stone",
	 "boxes","They are made of teak wood",
	 "wood","Smelly teak wood",
	 "box","It is made of teak wood"


       });

  }
 ::reset();
 replace_program("room/room");
}

