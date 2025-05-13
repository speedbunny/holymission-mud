inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Trog village park";
   long_desc =
"The park continues to be relaxing and peaceful. The faint glow from the "+
"moss hasn't subsided and the humming of the insects around the flowers "+
"is calming. The path continues to the north and the east.\n";

   dest_dir = ({"players/airborne/new/park4", "north", 
		"players/airborne/new/park8", "east", });

   items = ({"park", "A beatutiful and relaxing park", 
	"moss", "Strange glowing green moss",
	"insects", "Many different types of insects feeding on the flowers",
	"path", "A grey cobblestone path", });

	}
}

init(){
::init();

 add_action("pick", "pick");
 add_action("pick", "gather");
 add_action("listen", "listen");
	}

listen(){
  write("You hear the relaxing sounds of the humming of insects feeding.\n");
  return 1; }

pick(){
  write("There is nothing worth picking here.\n");
  return 1; }
