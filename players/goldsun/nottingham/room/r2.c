inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Dusty road");
 long_desc="You are walking on the dusty road. The green grass\n"+
	   "growing on the sides of the road. Far to the west you\n"+
	   "can see town and to the northeast hill.\n";


 smell="The air is dusty.";

 dest_dir=({ "/players/goldsun/nottingham/room/r3","northeast",
   		"/players/goldsun/nottingham/room/r1","southwest"});

 items=({
	   "town" ,"A small town to the west. It looks like Nottingham",
	   "hill","A hill to the northeast",
	   "grass","The grass is waving in the wind"
        });

 }
 ::reset(arg);
 replace_program("room/room");
}

