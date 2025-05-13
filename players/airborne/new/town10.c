inherit "room/room";

reset(arg){
 if(!arg){

   set_light(0);
   short_desc = "Trog village";
   long_desc =
"You are on the north-south road in the Trog village. There are small houses "+
"to the south and the cliff is to the north.\n";

   dest_dir = ({"players/airborne/new/town1", "north",
		"players/airborne/new/town11", "south" });

   items = ({"road", "A dirt road going north and south", 
	"cliff", "A large cliff to the north", });

replace_program("room/room");
	}
}
