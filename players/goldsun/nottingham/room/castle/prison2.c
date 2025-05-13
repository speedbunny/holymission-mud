inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);

 clone_list=({1,1,"gisbern",
	    "/players/goldsun/nottingham/monster/gisbern",0});

 short_desc=("Passage");
 long_desc="You are in the small passage of the castle cellar. The passage\n"+
	   "continues to the east and south. Torches along the wall give off\n"+
           "a smoky odour.\n";
 
 smell="You smell torch smoke.";
 property=({"has_fire"});
 dest_dir=({"/players/goldsun/nottingham/room/castle/prison1","north", 
	    "/players/goldsun/nottingham/room/castle/prison3","east",
	    "/players/goldsun/nottingham/room/castle/treasury","south"});

 items=({ "cellar" ,"Dump murky cellar of Nottingham castle",
	  "torches","They are attached to the wall",
	  "passage","A passage to the south and east"
	  
        });

 }
 ::reset(arg);
 replace_program("room/room");
}

