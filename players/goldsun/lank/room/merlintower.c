inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("On the rock");
 long_desc=
   "You are standing on the rock over the sea. You notice\n"+
   "forest edge to the east and. The distance between you and\n"+
   "the sea is very high. There is a small tower in front of you\n";


 smell="The air is fresh.";

 no_castle_flag=1;
 dest_dir=({"/players/goldsun/lank/room/forest8","east"});

 items=({"sea","The sea is blue. Huge waves are rolling towards the rock",
	 "tower","Merlin's tower",
	 "forest","The forest looks very dense and mysterious"
	 "rock","You are standing on the huge black rock.\n"+
	        "It is very high over the sea"
	});
 }
 ::reset();
}

init(){
 ::init();
add_action("enter","enter");
}

int enter(string str){
 if (str=="tower"){
  write("The tower is closed.\nMerlin isn't at home.\n");
  return 1;
 }
 notify_fail("Enter what ?\n");
 return 0;
}
