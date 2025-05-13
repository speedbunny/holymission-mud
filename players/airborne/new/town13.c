inherit "room/room";

reset(arg){
 if(!arg){

   set_light(0);
   short_desc = "Trog village";
   long_desc =
"You are on the road running north-south through the Trog village. There are "+
"houses to the south and east.\n";

   dest_dir = ({"players/airborne/new/house5", "east",
		"players/airborne/new/town12", "north",
 		"players/airborne/new/house6", "south", });

   items = ({"road", "A dirt road leading throught Trog village",
	"houses", "Run down houses" , });

replace_program("room/room");
	}
}
