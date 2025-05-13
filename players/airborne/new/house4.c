inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Trog village";
   long_desc = 
"The house is rather small yet finely ornate. The furnishings are rather "+
"similar to the rest of the houses the Trogs live in.\n";

   dest_dir = ({"players/airborne/new/town4", "north"});

if(!present("milly", this_object())){
object milly;

   milly = clone_object("players/airborne/new/monsters/mildred");
   move_object(milly, this_object());
	}
	}
}
