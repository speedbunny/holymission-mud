inherit "/room/room";

reset(arg){
 if (!arg){
 clone_list=({1,1,"vilan","/players/goldsun/nottingham/monster/vilan",0});
 set_light(1);
 short_desc=("Kitchen");
 long_desc="You are in the palace kitchen. It looks very dirty.\n"+
	   "You can see a large stove in the middle of the kitchen\n"+
	   "and a table with chairs by the wall.\n";
 
 smell="Hm. It smells very well, but what is it ?";

 dest_dir=({ "/players/goldsun/nottingham/room/castle/hall1","north" });

 items=({  
           "residence","It is the residence of nottingham sheriff",
	   "stove","Large stove with many pots on it",
	   "table","Oak table with chairs around it",
	   "chair","Oak chair",
	   "chairs","Oak chairs"
        });

 }
 ::reset(arg);
 replace_program("room/room");
}

