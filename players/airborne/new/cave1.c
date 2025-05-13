inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Entrance to Trog village";
   long_desc =
"This is the entrance to the Trog village. The stone walls look wet and "+
"cold adding to the musty smell. The cave leads to a tunnel to the south "+
"which declines slowly. You get the feeling you may end up deep in a tunnel "+
"so lighting might be needed. \n";

   dest_dir = ({"players/airborne/new/station", "north", 
	"players/airborne/new/cave2", "south", });
   items = ({"stone", "Cold damp stone",
 	"walls", "Walls are just cold damp stone",
	"water", "Water running from somwhere inside the walls", });

  smell = "The smell is rather damp and musty.";

  this_player()->set_smell("Damp and musty. Might have been in a cave.");

	}
}
