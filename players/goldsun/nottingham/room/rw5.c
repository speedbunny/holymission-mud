inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("In a forest");
 long_desc="You are in a big forest. Small path continues to the south.\n"+
           "Huge trees and bushes are everywhere. Green grass is waving\n"+
           "in the wind\n";

 smell="You smell damp forest air.";

 dest_dir=({ "/players/goldsun/nottingham/room/rw6","north",
   	      "/players/goldsun/nottingham/room/rw4","south"});

 items=({  "trees","Old, huge trees",
	   "bushes","Dense green bushes",
	   "bush","Dense green bush",
	   "tree","Tall old oak",
	   "grass","The grass is waving in the wind",
	   "path","A path to the south",
           "green grass","Nice green grass is waving in the wind"
        });

 }
 ::reset(arg);
 replace_program("room/room");
}

