inherit "/room/room";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){
 set_light(1);
 short_desc=("In a guard tower");
 long_desc=
    "You are at the staircase of a high guard tower. The tower is made\n"+
    "of white stone and looks very sturdy. The stairs wind up from here\n"+
    "and there is a passage to the northwest.\n"; 

 smell="You smell rotten air.";

 dest_dir=({ PATH + "courtyard3", "northwest",
	     PATH + "tower_1_2",  "up"});

 items=({"stairs","The stairs lead up",
	 "tower",long_desc
         });
 }
 ::reset(arg);
 replace_program("/room/room");
}


