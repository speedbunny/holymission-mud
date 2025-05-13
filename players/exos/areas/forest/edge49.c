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
	  "/players/exos/forest/edge48","east",
	  "/players/exos/forest/edge50","west",
	  "/players/exos/forest/11","southwest",
	  "/players/exos/forest/12","south",
	  "/players/exos/forest/13","southeast",
	});
    }
    replace_program("room/room");
    ::reset(arg);
}
