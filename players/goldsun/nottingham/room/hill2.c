inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Top of the hill");
 long_desc="You are standing on the top of hill. It is covered with\n"+
	   "moss, grass and bushes and continues to the east. You can\n"+
	   "see a small forest down the hill. Far to the southwest you\n"+
	   "notice a town.\n";

 smell="You feel damp forest air.";

 dest_dir=({ "/players/goldsun/sherwood/room/hill2","east",
   	    "/players/goldsun/nottingham/room/hill","down"});

 items=({  
	   "hill","It is covered with moss, grass and bushes",
	   "trees","Old, huge trees",
	   "bushes","Dense green bushes",
	   "forest","It is small forest",
	   "bush","Dense green bush",
	   "tree","Tall old oak",
	   "town","A town to the southwest. It looks like Nottingham",
	   "moss","Red-green moss. It looks very soft",
	   "grass","The grass is waving in the wind"
        });

 }
 ::reset(arg);
 replace_program("room/room");
}

