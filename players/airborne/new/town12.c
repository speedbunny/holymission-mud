inherit "room/room";

reset(arg){
 if(!arg){

   set_light(0);
   short_desc = "Trog village";
   long_desc = 
"You are on the north-south road in the Trog village. There is a boarded up "+
"tavern to the east and houses to the south.\n";

   dest_dir = ({"players/airborne/new/town11", "north",
		"players/airborne/new/town13", "south", });

   items = ({"road", "Road through Trog village. It runs north and south",
	"tavern", "It looks as if it were just in a fire. It is closed",
	"houses", "Simple looking houses to the south" });

   smell = "You smell the scent of faint fire.";

	}
}

init(){
::init();

  add_action("enter", "east");
  add_action("enter", "enter");
	}

enter(){

  write("The tavern is all boarded up. There is no way for you to enter.\n");
  return 1; }

