inherit "room/room";

reset(arg){
 if(!arg){

object due;
int i;

   set_light(0);
   short_desc = "Duegar path";
   long_desc = 
"The path stretches to the north and south. Directly south is a large open "+
"cavern and to the north, the path continues.\n";

   dest_dir = ({"players/airborne/new/path2", "north",
		"players/airborne/new/cavern", "south", });

   items = ({"path", "A dark and dirty path",
		"cavern", "A deep dark cavern off in the distance", });

i = 0;
 if(!present("duegar", this_object())){
   while (i < 8){
    i += 1;
	due = clone_object("players/airborne/new/monsters/duegar");
	move_object(due, this_object());
	}
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
