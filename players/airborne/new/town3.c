inherit "room/room";
status searched;

reset(arg){
searched = 0;
 
 if(!arg){

   set_light(0);
   short_desc = "Trog village";
   long_desc = 
"You are on the east-west road running through the Trog village. To the "+
"north there is a small house and to the south is an entrance to a park "+
"with glowing green fields. The road continues to the east and west as "+
"well.\n";

   dest_dir = ({"players/airborne/new/house1", "north", 
	"players/airborne/new/park1", "south",
	"players/airborne/new/town2", "west",
	"players/airborne/new/town4", "east" });

   items = ({"house", "A small green house. The doorway doesn't seem to barr your entrance",
 	"park", "A small park with a green glowing field", 
	"field", "The field seems to be glowing faintly", });

	}
}

init(){
::init();

   add_action("search", "search");
	}

search(){
object coin;

   if(searched){
	write("You find nothing.\n");
	return 1; }
   else {
	write("You find a small coin laying on the road!");
	coin = clone_object("obj/treasure");
	coin -> set_id("quest_coin");
	coin -> set_value("200");
	coin -> set_weight(1);
	coin -> set_short("A worthless old coin");
	coin -> set_long("The coin looks to be old and worthless, but upon closer inspection\nyou realize it just might be an antique.\n");
	coin -> set_name("coin");
	transfer(coin, this_player());
	say(this_player()->query_name() + " finds a coin.\n");
        searched = 1;

	}
}
