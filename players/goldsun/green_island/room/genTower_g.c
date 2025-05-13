inherit "/room/room";

reset(arg){
if (!arg){
 set_light(1);
 short_desc=("In a gate-tower");
 long_desc=
    "You are at the staircase of a high gate-tower. The tower is made\n"+
    "of white stone and looks very sturdy. The stairs wind up and down\n"+
    "from here.\n"; 

 smell="You smell rotten air.";

 items=({"stairs","The stairs lead up and down",
	 "tower",long_desc
         });
 }
 ::reset(arg);
}



