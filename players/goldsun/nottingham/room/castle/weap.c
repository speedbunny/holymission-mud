inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Castle weaponery");
 long_desc="This is the storeroom of weapons. There are many kinds\n"+
	   "of weapons and armours.\n";
 	   
 
 smell="You smell smoke of torches.";

 dest_dir=({ "/players/goldsun/nottingham/room/castle/throne","north"});

 items=({"weapons","They are fixed to the wall",
	 "armours","They looks very nice"

        });

 }
 ::reset(arg);
 replace_program("room/room");
}

