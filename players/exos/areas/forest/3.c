inherit "room/room";

void reset(int arg) {
    if (!arg) {
	set_light(1);
	short_desc="In a deep forest";
	long_desc="\
Lost in a deep forest.\n";
	items=({ });
	dest_dir=({
	  "/players/exos/forest/2","west",
	  "/players/exos/forest/edge1","northwest",
	  "/players/exos/forest/edge54","north",
	  "/players/exos/forest/edge53","northeast",
	  "/players/exos/forest/4","east",
	  "/players/exos/forest/9","southeast",
	  "/players/exos/forest/8","south",
	  "/players/exos/forest/7","southwest",
	});
    }
    replace_program("room/room");
    ::reset(arg);
}
