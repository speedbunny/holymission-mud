inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Trog caves";
   long_desc = 
"The tunnel cuts through the cold stone as if it were not natural. The stone "+
"walls run smooth without a nick or scratch. The tunnel continues north and "+
"south where it looks like it is declining and darkening.\n";

   dest_dir = ({"players/airborne/new/cave1", "north", 
	"players/airborne/new/cave3", "south", });

   items = ({"tunnel", "The tunnel runs north and south, grey stone all around",
	"stone", "Cold, wet, grey stone", });

   smell = "The place still smells very musty";
	
  replace_program("room/room");
	}
}
