inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("At the bottom of the hill");
 long_desc="You are at the bottom of the hill. The hill is steep.\n"+
	   "It is covered with moss, grass and bushes. The trees and\n"+
	   "bushes are around you.\n";
 smell="You feel damp forest air.";

 dest_dir=({ "/players/goldsun/nottingham/room/r4","west",
         "/players/goldsun/nottingham/room/hill","up"});

 items=({  
	   "hill","It is covered with moss, grass and bushes",
	   "trees","Old, huge trees",
	   "bushes","Dense green bushes",
	   "bush","Dense green bush",
	   "tree","Tall old oak",
	   "moss","Red-green moss. It looks very soft",
	   "grass","The grass is waving in the wind"
        });

 }
 ::reset(arg);
 replace_program("room/room");
}

