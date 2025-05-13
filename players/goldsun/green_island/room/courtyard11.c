inherit "/room/room";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){
 set_light(1);
 short_desc=("In a courtyard");
 long_desc=
   ("You are standing in the courtyard. The ground is covered in\n"+
    "glated rocks. White sturdy castle is rise to the sky. There\n"+
    "is a small passage to the northeast and a castle entrance to west.\n");

 smell="You smell rotten air.";

 dest_dir=({ PATH + "residence1", "west",
  	     PATH + "courtyard7", "south",
	     PATH + "tower_4",    "northeast"});

 items=({"castle","White sturdy castle. It is made of stone",
	 "courtyard",long_desc,
         "entrance","A entrance to the Rockland Castle"
         });
 }
 ::reset(arg);
 replace_program("/room/room");
}


