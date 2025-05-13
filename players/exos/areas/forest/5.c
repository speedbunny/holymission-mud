inherit "room/room";

void reset(int arg) {
    if (!arg) {
	set_light(1);
	short_desc="In a deep forest";
	long_desc="\
Lost in a deep forest.\n";
	items=({ });
	dest_dir=({
	  "/players/exos/forest/edge4","west",
	  "/players/exos/forest/edge3","north",
	  "/players/exos/forest/1","northeast",
	  "/players/exos/forest/6","east",
	  "/players/exos/forest/19","southeast",
	  "/players/exos/forest/18","south",
	  "/players/exos/forest/17","southwest",
	});
    }
    replace_program("room/room");
    ::reset(arg);
}
