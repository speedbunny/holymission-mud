inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Clearing");
 long_desc="A small clearing. The clearing opens to the southwest\n"+
	   "to the grassland. There are trees and bushes around you.\n"+
	   "To the east you can see a steep hill.\n";

 smell="You feel damp forest air.";

 dest_dir=({ "/players/goldsun/nottingham/room/r5","east",
   		"/players/goldsun/nottingham/room/r3","southwest"});

 items=({  "grassland","A green grassland to the southwest",
	   "hill","A hill to the east",
	   "trees","Old, huge trees",
	   "bushes","Dense green bushes",
	   "bush","Dense green bush",
	   "tree","Tall old oak",
	   "grass","The grass is waving in the wind"
        });

 }
 ::reset(arg);
 replace_program("room/room");
}

