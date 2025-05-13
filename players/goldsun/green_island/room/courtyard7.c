inherit "/room/room";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){
 set_light(1);
 short_desc=("In a courtyard");
 long_desc=
   ("You are standing in the courtyard. The ground is covered in\n"+
    "glated rocks. White sturdy castle is rise to the sky.\n");

 smell="You smell rotten air.";

 dest_dir=({ PATH + "courtyard11", "north",
	     PATH + "courtyard10", "west",
	     PATH + "courtyard9",  "southwest",
	     PATH + "courtyard8",  "south",
	     PATH + "courtyard5",   "southeast",
   	     PATH + "courtyard6",  "east"});

 items=({"castle","White sturdy castle. It is made of stone",
	 "courtyard",long_desc
         });
 }
 ::reset(arg);
 replace_program("/room/room");
}


