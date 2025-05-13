inherit "/room/room";

reset(arg){
if (!arg){
 set_light(1);
 short_desc=("On the top of guard tower");
 long_desc="Top of the tall guard tower. It is made of rock and looks very.\n"+
	   "sturdy. You have a nice view over sea and island.\n";

 smell="You smell salt fresh air.";

 items=({"castle","A marble castle. It's named Rockland",
	 "sea","Waves are rolling toward the island",
	 "island","Green island",
	 "tower",long_desc
         });
 }
 ::reset(arg);
}



