inherit "/room/room";
#define PATH "players/goldsun/7-islands/creta/room/"

reset(arg){
if (!arg){
 set_light(1);
 short_desc=("Large plain");
 long_desc=
  ("Large green plain spreads from north coast to west coast. The grass\n"+
   "is high but fresh. There are some trees and bushes on the plain that\n"+
   "make it more nice. To the southeast you can see Madaros - high mountain.\n" 
  );

 smell="A smell of herbs.";

 dest_dir=({ PATH+"creta5", "north",
	     PATH+"creta7", "south",
	     PATH+"creta3", "west"
	   });

 items=({"plain",long_desc,
	 "island",long_desc,
         "madaros","It is very high mountain",
	 "mountain","Madaros to the east. It is very high",
         });
 }
 ::reset(arg);
 replace_program("room/room");
}


  
  
