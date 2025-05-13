inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("In a forest");
 long_desc="You are in a big forest. Huge trees and bushes are everywhere.\n"+
           "The grass is waving in the wind\n";

 smell="You smell damp forest air.";

 dest_dir=({ "/room/forest2","north",
          "/players/goldsun/nottingham/room/rw5","south"}); 

 items=({  "trees","Old, huge trees",
	   "bushes","Dense green bushes",
	   "bush","Dense green bush",
	   "tree","Tall old oak",
	   "grass","The grass is waving in the wind"
        });

 }
 ::reset(arg);
 replace_program("room/room");
}

