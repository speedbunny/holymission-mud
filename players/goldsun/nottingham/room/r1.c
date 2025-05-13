inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Dusty road");
 long_desc="You are walking on the dusty road. To the west you can see\n"+
	   "a town wall. The surroundings looks peacefull.\n";


 smell="The air is dusty.";

 dest_dir=({ "/players/goldsun/nottingham/room/r2","northeast",
	     "/players/goldsun/nottingham/room/outside_gates","west"});

 items=({
	   "wall" ,"A town wall to the west",
	   "town wall","A sturdy town wall"
        });

 }
 ::reset(arg);
 replace_program("room/room");
}

