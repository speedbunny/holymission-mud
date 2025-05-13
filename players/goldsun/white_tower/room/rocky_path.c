inherit "/room/room";

reset(arg){

if (!arg){

 set_light(1);
 short_desc=("Rocky path");
 long_desc=
   "You are on the rocky path. Moon valley is to the west and \n"+
   "sandy coast to the east.\n";
   
 smell="The air smells dusty here";

 dest_dir=({ "/players/goldsun/white_tower/room/san",   "west",
	     "/room/shore/s47",				"east" });
 
 items=({ "valley","Moon valley to the west",
	  "coast","A sandy coast to the east",
	  "path",long_desc});
  }
 ::reset(arg);

}


