inherit "room/room";

reset(arg){
 if(!arg){
object due;

   set_light(0);
   short_desc = "Duegar path";
   long_desc =
"The stone path continues to the north and south, with the later exit "+
"yielding to a large cavern. There is very little greenery present, most "+
"likely the result of the deminished light.\n";

   items = ({"path", "A stone path",
		"stone", "Dark and dismal stones",
		"cavern", "A big deep cavern", });

   dest_dir = ({"players/airborne/new/path1", "north",
		"players/airborne/new/path3", "south", });

     if(!present("duegar", this_object())){
	due = clone_object("players/airborne/new/monsters/duegar");
        move_object(due, this_object());
		}
	}
}
init(){
 ::init();

   add_action("south", "south");
	}
south(){
   if(present("duegar", this_object())){
	write("The duegar blocks your way.\n");
	return 1;
    }
      	return ::move("south");
	}
