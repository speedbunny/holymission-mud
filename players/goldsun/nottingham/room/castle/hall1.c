inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Hallway");
 long_desc="Palace hallway. Lighted torches are fixed to the wall.\n"+
	   "You notice the passages to the north and south. To the\n"+
           "west is throne room and to the east you can see a courtyard.\n";
	  
 
 smell="You smell smoke of torches.";

 property=({"has_fire"});

 dest_dir=({ "/players/goldsun/nottingham/room/castle/guardroom","north",
	    "/players/goldsun/nottingham/room/castle/throne","west",	
             "/players/goldsun/nottingham/room/castle/kitchen","south"});

 items=({  
           "residence","It is the residence of nottingham sheriff" ,
	   "passages","A small passages leades to the north and south",
  	   "courtyard","A courtayrd to the east. It looks very nice"
        });

 }
 ::reset(arg);
 replace_program("room/room");
}

