inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Trog village park";
   long_desc = 
"The path through the park continues to the north, east, and south. The "+
"strange green moss lights the area faintly and from over a few bushes "+
"you can see the top of a colorful tent.\n";

   dest_dir = ({"players/airborne/new/park1", "north",
		"players/airborne/new/park5", "east", 
		"players/airborne/new/park7", "south", });

   items = ({"path", "A grey cobblestone path", 
	"moss", "Strange green moss glowing faintly",
	"green moss", "Strange green moss glowing faintly",
	"bushes", "Small bushes that must be getting light from the moss",
	"tent", "A colorful tent seen over the bushes to the east", });

if(!present("tusker", this_object())){
 object tusk;

	tusk = clone_object("obj/monster");
	tusk-> set_name("tusker");
	tusk-> set_short("A tusker");
	tusk-> set_long
("A small rodent like animal with a large tusk protruding from his head. "+
 "it doesn't look happy.\n");
        tusk-> set_level(7);
	tusk-> set_wc(15);
	tusk-> set_ac(4);
	tusk-> set_aggressive(1);
	tusk-> set_hp(70);
	tusk-> set_str(15);
	 move_object(tusk, this_object());
		}
	}
}

init(){
::init();

   add_action("pick", "pick");
   add_action("pick", "gather");
	}

pick(){

   write("There doesn't seem to be anything you can pick in this spot.\n");
   return 1; }
