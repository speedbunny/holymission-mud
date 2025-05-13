inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Small path");
 long_desc="You are walking on the grassy road. There are still some bushes\n"+
	   "and trees here. Path continues to the south and north.\n";

 smell="You smell damp forest air.";

 dest_dir=({ "/players/goldsun/nottingham/room/rw5","north",
   	      "/players/goldsun/nottingham/room/rw3","south"});

 items=({  "trees","Old, huge trees",
	   "bushes","Dense green bushes",
	   "bush","Dense green bush",
	   "tree","Tall old oak",
           "road","The grassy road. It looks very nice",
	   "grass","The grass is waving in the wind",
	   "path","A path to the south and north",
           "green grass","Nice green grass is waving in the wind"

        });

 }
 ::reset(arg);
 replace_program("room/room");
}

