inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Trog village park";
   long_desc = 
"The path through the park continues to the east, west, and south. The "+
"strange green moss continues to light the area faintly. To the south you "+
"can see the top of a small hut.\n";

   dest_dir = ({"players/airborne/new/park1", "west", 
		"players/airborne/new/park3", "east",
		"players/airborne/new/park5", "south", });

   items = ({"moss", "Strange green glowing moss",
		"path", "A cobblestone path leading through the park", 
		"hut", "A small multi-colored hut to the south", });

if(!present("tusker", this_object())){
object tusk;
  
   tusk = clone_object("obj/monster");
   tusk-> set_name("tusker");
   tusk-> set_alt_name("tusk");
   tusk-> set_alias("pet");
   tusk-> set_level(7);
   tusk-> set_wc(10);
   tusk-> set_ac(3);
   tusk-> set_str(10);
   tusk-> set_short("A tusker");
   tusk-> set_long
("A tusker is a small rodent like animal with large bone tusks protruding\n"+
"from its skull and a thin leathery tail.\n");
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
   write("The moss isn't mature enough to pick here.\n");
   return 1; }
