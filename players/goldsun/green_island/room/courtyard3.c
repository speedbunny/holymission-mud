inherit "/room/room";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){
 set_light(1);
 short_desc=("In a courtyard");
 long_desc=
   ("You are standing in the courtyard. The ground is covered in\n"+
    "glated rocks. White sturdy castle is rise to the sky. There\n"+
    "is a small passage to the southeast.\n");

 smell="You smell rotten air.";

 dest_dir=({ PATH + "courtyard1", "north",
	     PATH + "courtyard4", "west",
	     PATH + "tower_1",    "southeast",
	     PATH + "courtyard5", "northwest"});

 items=({"castle","White sturdy castle. It is made of stone",
	 "courtyard",long_desc
         });
 }
 ::reset(arg);
 replace_program("/room/room");
}


