inherit "room/room";

void reset(int arg) {
    if (!arg) {
	set_light(1);
	short_desc="At the edge of a great forest";
	long_desc="\
To the south is a large forest that spreads out as far as you can see.\n\
The trees are very old, and the undergrowth is quite dense.  You do not see a\n\
way into the forest from here.\n";
	items=({ });
	dest_dir=({
	  "/players/exos/forest/edge50","northeast",
	  "/players/exos/forest/edge52","northwest",
	  "/players/exos/forest/10","west",
	  "/players/exos/forest/23","southwest",
	  "/players/exos/forest/24","south",
	  "/players/exos/forets/25","southeast",
	  "/players/exos/forest/11","east",
	});
    }
    replace_program("room/room");
    ::reset(arg);
}
