inherit "room/room";

reset(arg){
 if(!arg){

   set_light(0);
   short_desc = "Trog village";
   long_desc = 
"You come to the end of the village road and see houses abound. There is "+
"a house in all directions with the exception of west, where the road "+
"continues to travel east-west.\n";

   dest_dir = ({"players/airborne/new/house2", "north",
		"players/airborne/new/house3", "east",
		"players/airborne/new/town3", "west", 
		"players/airborne/new/house4", "south", });

   items = ({ "road", "East-west road through Trog village",
	"houses", "Many different houses", });


replace_program("room/room");

	}
}

