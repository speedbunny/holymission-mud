#define TP this_player()
#define TPN TP->query_name()
 
inherit "room/room";

reset(arg){
  set_light(0);
  dest_dir = ({"players/airborne/temple/levelc/secret", "hole",
		"players/airborne/temple/levelc/balrog", "north" });
  short_desc = "Dark room";
  long_desc = "This is a small room.\n"
	        "There is a hole in the wall to the west and it appears\n"
	        "that there is a room to the north.\n"
		"There are some strange symbols above the northern doorway.\n";
  items = ({"hole", "A small hole, looks like you might fit",
	"doorway", "A very intricately carved doorway. Be careful what is on the other side",
	"symbols", "Although you don't know what language it is, you seem to understand.\n"
        "You get the notion that only a good prayer will save you now", });

}

init(){
  ::init();
	add_action("read", "read");
	add_action("pray", "pray");
       }

read(str){
  if(!str) str=query_verb();
switch(str){
   case "symbols" :
   case "symbol" :
	write("You cannot read the symbols, however, you still get a\n");
	write("strange feeling... like something very evil!\n");
   return 1;
	default :
		write("Read what?");
	return 1;
	}
	
}
pray(){
	write("You raise your hands in prayer.\n");
	write("Seems today is your lucky day! The Gods have taken pity on you!\n");
	write("You are lifted from this evil place.\n");
	this_player()->move_player("leaves#players/airborne/temple/levelc/room14");
	return 1;
}
