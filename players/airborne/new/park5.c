inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Trog village park";
   long_desc =
"As you walk into the center of the park, you realize just how peaceful "+
"the park can be. With the moss glowing faintly and the flowers blossoming "+
"your senses are filled with excitement. The multi-colored tent rests off to "+
"the side and th path continues in all directions from here.\n";

   dest_dir = ({"players/airborne/new/park2", "north",
		"players/airborne/new/park6", "east",
		"players/airborne/new/park8", "south",
		"players/airborne/new/park4", "west", });

   items = ({"moss", "Faintly glowing green moss", 
	"flowers", "Exotic flowers in bloom", 
	"tent", "There is an opening in the multi-colored fabric",
	"path", "A grey cobblestone path", });


   smell = "The flowers excite you scences.";

	}
}

init() {
::init();

  add_action("enter", "enter");
  add_action("pick", "pick");
  add_action("pick", "gather");
	}

enter(str){
  if(str=="tent" || str=="opening"){
	write("You enter the tent.\n");
	this_player()->move_player("into the tent#players/airborne/new/tent");
	return 1; }

   else {
	write("Enter what?\n");
	return 1; }
	}

pick(){
  write("There is nothing worth picking here.\n");
  return 1; }

