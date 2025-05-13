inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Trog village park";
   long_desc = 
"The path extends to the north, south, and west leading to a small colorful "+
"hut. The green moss conitinues to illuminate the area with its light glow. "+
"The flowers allong the ground remind you how beautiful a park is.\n";

   dest_dir = ({"players/airborne/new/park3", "north", 
		"players/airborne/new/park9", "south",
		"players/airborne/new/park5", "west", });

   items = ({"path", "A grey cobblestone path",
		"hut", "A small multi-colored hut", 
		"moss", "Glowing green moss",
		"green moss", "Glowing green moss",
		"flowers", "Beautiful blossoming flowers", });

if(!present("trog", this_object())){
object trog;

     trog = clone_object("obj/monster");
     trog-> set_name("fred");
     trog-> set_alt_name("mean trog");
     trog-> set_alias("trog");
     trog-> set_race("trog");
     trog-> set_aggressive(1);
     trog-> set_level(6);
     trog-> set_ac(5);
     trog-> set_hp(100);
     trog-> set_short("A mean trog");
     trog-> set_long
("Fred look a little meaner than most Trogs, but other than that, \n"+
 "he looks the same as the rest.\n");
     	move_object(trog, this_object());

		}

	}
}

init(){
::init();

 add_action("pick", "pick");
 add_action("pick", "gather");
	}

pick(){
  write("You are not able to find anything worth picking here.\n");
  return 1; }
