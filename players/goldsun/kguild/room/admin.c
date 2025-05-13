inherit "/room/room";

reset(arg){

 if (!arg){
 
 set_light(1);
 short_desc="Castle administratory";
 long_desc="You are in the castle administratory. This is the workroom of\n"+
   	   "Valdir the treasury administrator.\n";

 property=({"no_steal","no_fight"});

 smell="You can smell dusty air";

 dest_dir=({ "/players/goldsun/guild/room/treasury" ,"west"});

 items=({"walls","The walls are made of shiny stone",
	 "wall","The wall is made of shiny stone",
	 "stone","Very nice white shiny stone",
	 "shiny stone","Very nice white shiny stone"
       });

  }
 ::reset();
}
