inherit "room/room";

status has_dug;

reset(arg){
  if(!arg){
  set_light(0);
  short_desc = "Inside the crystal caverns";
  long_desc = "Trails of lichen spread westward into this cavern. Your "+
	"ears pop suddenly from the increased air pressure. Towards the "+
	"east crystals free of lichen shine with the mild reflection "+
	"of the light.\n";
  items = ({ "lichen", "Small green moss that thrives along the rock surfaces",
	"crystals", "The crystals are embedded deep into the rock surface.\n"+
		"You also notice a deep grey vein inside the southern wall",
	"rock", "Cool dark rock",
	"vein", "A deep vein of some metallic ore",
	"ore", "A deep grey ore, perhaps alluminum", });
  dest_dir = ({ "players/jewel/caverns/fun5", "west",
		"players/jewel/caverns/fun3", "east", });
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
    write("You could be here forever without the proper tools.\n");
    say(this_player()->query_name()+" foolishly tries to mine without the proper tools.\n");
    return 1;
  }
  if(!has_dug){
    has_dug += 1;
    stuff = clone_object("obj/treasure");
    stuff -> set_id("ore");
    stuff -> set_name("ore");
    stuff -> set_alt_name("aluminum");
    stuff -> set_alias("aluminum ore");
    stuff -> set_value(random(20)+1);
    stuff -> set_weight(3);
    stuff -> set_short("Aluminum ore");
    stuff -> set_long("A crude deposit of aluminum ore.\n");
    move_object(stuff, this_object());
    write("You dig for a bit... and find something!\n");
    say(this_player()->query_name()+" digs in the rock and finds something!\n");
    return 1;
  }
  write("There doesn't appear to be anything left to dig up.\n");
  say(this_player()->query_name()+" digs to no avail.\n");
  return 1;
}
