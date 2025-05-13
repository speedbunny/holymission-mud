inherit "room/room";

reset(arg){
 if(!arg){
   set_light(0);
   short_desc = "Inside the crystal caverns";
   long_desc = "Your footsteps echo as you enter the near empty cavern. "+
	"As the cavern widened from the east, various lichen found root "+
	"along its slippery rock surface, covering the pretty glow of the "+
	"scattered crystals along the walls. The caverns continue to the "+
	"west and east.\n";
   items = ({ "cavern", "A cool dark cavern covered with lichen",
	"lichen", "Small greenish plants that thrive in the damp dark surroundings",
	"rock", "Almost all the rock is covered with a light covering of lichen",
	"crystals", "The warm glow of the crystals is masked by the blanketing lichen",
	"walls", "The walls are made of a cool dark rock and covered with lichen",
	"wall", "The walls are made of a cool dark rock and covered with lichen",
	"caverns", "A cool dark cavern covered with lichen", });
   dest_dir = ({ "players/jewel/caverns/fun2", "east",
		"players/jewel/caverns/fun4", "west", });
   clone_list = ({ 1, 1, "pickaxe", "obj/weapon",
			   ({	"set_name", "pickaxe",
				"set_alias", "pick",
				"set_alt_name", "axe",
				"set_id", "pickaxe",
				"set_class", 3,
				"set_value", 10,
				"set_short", "A miner's pickaxe",
				"set_long", "A miner's old pickaxe.\n",
				"set_weight", 2, }),
				});

 replace_program("room/room");
 }
}
