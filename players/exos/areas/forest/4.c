inherit "room/room";

void reset(int arg) {
    if (!arg) {
	set_light(1);
	short_desc="In a deep forest";
	long_desc="\
Lost in a deep forest.\n";
	items=({ });
	dest_dir=({
	  "/players/exos/forest/3","west",
	  "/players/exos/forest/edge54","northwest",
	  "/players/exos/forest/edge53","north",
	  "/players/exos/forest/edge52","east",
	  "/players/exos/forest/10","southeast",
	  "/players/exos/forest/9","south",
	  "/players/exos/forest/8","southwest",
	});
    }
    replace_program("room/room");
    ::reset(arg);
}
