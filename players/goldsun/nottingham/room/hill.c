inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Steep hill");
 long_desc="You are climbing up a steep hill. It is covered with\n"+
	   "moss, grass and bushes. You can see a small forest down\n"+
	   "the hill. \n";		   

 smell="You feel damp forest air.";

 dest_dir=({ "/players/goldsun/nottingham/room/hill2","up",
   	    "/players/goldsun/nottingham/room/r5","down"});

 items=({  
	   "hill","It is covered with moss, grass and bushes",
	   "trees","Old, huge trees",
	   "bushes","Dense green bushes",
	   "bush","Dense green bush",
	   "tree","Tall old oak",
	   "moss","Red-green moss. It looks very soft",
	   "grass","The grass is waving in the wind"
        });

 }
 ::reset(arg);
 replace_program("room/room");
}

