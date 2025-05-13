inherit "room/room";

reset(arg){
 if(!arg){

   set_light(0);
   short_desc = "Trog village";
   long_desc = 
"The road through the Trog village leads east-west on this branch. Looking "+
"ahead, you can see a small house and a little park.\n";

   dest_dir = ({"players/airborne/new/town1", "west",
	"players/airborne/new/town3", "east", });

   items = ({"road", "A small dusty path through the Trog Village",
	"house", "The house is small and looks enviting",
	"park", "A small park", });

 replace_program("room/room");
	}
}
 
