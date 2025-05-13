inherit "room/room";

reset(arg){
 if(!arg){

   set_light(0);
   short_desc = "Trog village";
   long_desc =
"The road continues to the north and south through the Trog village. "+
"Off to the south you see the beginings of a tavern and maybe a few houses "+
"past that as well.\n";

   dest_dir = ({"players/airborne/new/town10", "north",
		"players/airborne/new/town12", "south", });

   items = ({"road", "The north-south road through the Trog village",
       "tavern", "It looks all closed up with boards on the windows and doors",
       "houses", "Small trog houses to the south", });

replace_program("room/room");
	}
}
	
