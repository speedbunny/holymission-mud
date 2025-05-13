inherit "/room/room";

reset(arg){
if (!arg){
 set_light(1);
 short_desc=("On the castle wall");
 long_desc="Top of the castle wall. It is wide and made of rock.\n"+
	   "It protects Rockland castle against enemies. You have\n"+
           "a nice view over sea and island.\n";

 smell="You smell salt fresh air.";

 items=({"castle","A marble castle. It's named Rockland",
	 "sea","Waves are rolling toward the island",
	 "wall",long_desc
         });
 }
 ::reset(arg);
}



