inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Trog village";
   long_desc = 
"You are in the house next to the shambled tavern. The furnishings are "+
"rather simple.\n";

   dest_dir = ({"players/airborne/new/town13", "west", });

if(!present("barney", this_object())){
object bar;

  bar = clone_object("players/airborne/new/monsters/barney");
  move_object(bar, this_object());
	}

	}
}

