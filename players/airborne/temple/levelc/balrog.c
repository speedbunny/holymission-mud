#define TP this_player
#define TPN TP->query_name

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "Baal-Rog's Room!";
  long_desc = "As you enter this room the wall closes behind you!\n"
	"It is being lit by some strange light shining from a "
	"magic circle drawn on the floor.\n";
  items = ({"magic circle", "A strange magic circle big enough for you to step in.",
		"circle", "A strange magic circle big enough for you to enter" });
  property = ({"no_tport_out", "no_tport_in", });

if(!present("baalrog", this_object())){
 object baalrog;
 	baalrog = clone_object("players/airborne/monsters/baalrog.c");
	move_object(baalrog, this_object());
	}
}

init(){
   ::init();
	add_action("enter", "enter");
	}

enter(str){
 if(!str) str=query_verb();
   switch(str){
	case "circle":
	case "magic circle":
   write("You enter the mighty circle and begine to feel strange!\n");
   write("Your head begins to spin and you black out momentarily!\n");
   write("You awaken outside the temple.\n");
	this_player()->move_player("enters cirlce#players/airborne/temple/entrance/land4");
	return 1;
		default :
	write("Enter what?\n");
		return 1;
	}
}
