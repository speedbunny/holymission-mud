inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(0);
  short_desc = "Deep inside the crystal caverns";
  long_desc = "You trip over a few sharp stones upon continuing through "+
	"the cavern.  As you squeeze past the low hanging rocks you "+
	"notice that the reflection of the crystals are a blueish hue. "+
	"The blue glow nestled over such cramped quarters gives this "+
	"tunnel an eerie feeling, perhaps causing you to reflect again "+
	"on your journey.\n";
  items = ({ "cavern", "A deep cavern surrounded by cold rocks and lichen",
	"rocks", "Cool dark rocks making the surface of the cavern",
	"reflection", "A light blue glow all over",
	"tunnel", "A deep cavern surrounded by cold rocks and lichen",
	"lichen", "A greenish moss plant coverning the rocks", });
  dest_dir = ({ "players/jewel/caverns/fun6", "west",
		"players/jewel/caverns/fun4", "east", });
  clone_list = ({ 1, 2, "crystal", "obj/treasure",
			   ({	"set_name", "crystal",
				"set_id", "blue crystals",
				"set_short", "Blue crystals",
				"set_long", "A thin blue crystal.\n",
				"set_weight", 1,
				"set_value", 10, }),
				});

replace_program("room/room");
}
