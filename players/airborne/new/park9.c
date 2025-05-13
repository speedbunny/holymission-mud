inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Trog village park";
   long_desc =
"The park is so peaceful and quiet. The light from the moss is faintly "+
"illuminationg the area. The path leads to the north and west in the park.\n";

   dest_dir = ({"players/airborne/new/park6", "north",
		"players/airborne/new/park8", "west", });

   items = ({"moss", "Strange green glowing moss",
	"path", "A grey cobblestone path", });

	}
}

init(){
::init();

  add_action("pick", "pick");
  add_action("pick", "gather");

	}

pick(){
  write("You find nothing worth picking.\n");
  return 1; }

