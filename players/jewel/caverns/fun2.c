inherit "room/room";

status has_dug;
object crystal;

reset(arg){
  if(!arg){
    set_light(1);
    short_desc = "Dim caverns.";
    long_desc = "The caverns open up into a a much wider tunnel.  The cold "+
	"rock face continues interupted only by the warm pink glow of the "+
	"scattered crystal quartz. A deep quartz vein seems to run close to "+
	"the wall surface, shining exceptionally bright.\n";
    items = ({ "caverns", "Cold dark stone caverns speckled with crystals",
	"tunnel", "The tunnel widens to the west and narrows to the east",
	"rock", "Cool dark stone rock",
	"crystals", "The speckled pink crystals nest in the surface of the rocks",
	"crystal", "The endless crystals speckle against the dark stone tunnel",
	"vein", "A deep quartz vein appearing close to the surface. Miners would love to find such a site to dig.",
	"quartz vein", "A deep quartz vein appearing close to the rock surface. Miners would love to find such a good site to dig",
	});
    dest_dir = ({ "players/jewel/caverns/fun3", "west",
		"players/jewel/caverns/fun1", "east", }); 
    smell = "You smell the freshly toiled earth about you.\n";
  }
  has_dug = 0;
}

init(){
 ::init();

  add_action("digging", "dig");
  add_action("digging", "mine");

}

digging(str){
  
object stuff;

  if((str!="vein")||(str!="in vein")) return;
  if(!present("pickaxe", this_player())){
    notify_fail("Digging in the quartz is difficult without the right tools.\n");
    say(this_player()->query_name()+" tried to dig without the proper tools.\n");
    return 1;
  }
  write("You dig with all your might and...\nYou found something!\n");
  say(this_player()->query_name()+" digs for a while, and gasps in astonishment having found something.\n");
  stuff = clone_object("obj/treasure");
  stuff -> set_id("crystal");
  stuff -> set_short("A pink quartz crystal");
  stuff -> set_long("A small rough quartz crystal that picks up all the light\nand sparkles brilliantly.\n");
  stuff -> set_value(random(10)+1);
  stuff -> set_weight(1);
  transfer(stuff, this_object());
  return 1;
}
