inherit "/room/room";
object excalibur;

reset(arg){

 if (!arg){
 
  set_light(1);
  short_desc="Throne room";
  long_desc=
   "You are in the Carmaalot throne room. The walls are made\n"+
   "of shiny stone. in the middle of the room there is a round table here.\n"+
   "There are many chairs around it.\n";

 smell="You can smell nothing special";

 dest_dir=({ "/players/goldsun/guild/room/magic" ,"north",
	     "/players/goldsun/guild/room/westyard","east",
	     "/players/goldsun/guild/room/treasury","south"});

 items=({"walls","The walls are made of shiny stone",
	 "wall","The wall is made of shiny stone",
	 "stone","Very nice white shiny stone",
	 "shiny stone","Very nice white shiny stone",
	 "table","An oak Round Table. Only the member of Round Table\n"
	            +"can sit at this table",
	 "chair","A nice wooden chair",
	 "chairs","Nice wooden chairs"
       });

  }
 ::reset();
}
init(){
 ::init();
add_action("do_sit","sit");
}

int do_sit(string str){
 return 1;
}

