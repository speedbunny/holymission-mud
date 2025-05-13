/* Edited by Colossus 022294 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (!arg) {
	set_light(1);
	short_desc = "Entrance to the darklands";
	long_desc=
	"You stand before the entrance of the dark lands. Everything looks\n"+
	"gloomy and foreboding. To the north the path you're on continues\n"+
	"and leads to a large black building in the south distance. To the\n"+
	"you see a a gaping hole that hangs in midair and sucks in all\n"+
	"light.\n";
	items=({ 
	  "building","This building looks like a large black castle",
	  "hole","It's pure darkness. It seems to suck in all light",
	});
	dest_dir=({
	  "/players/sherman/darkl2","north",
	  "/players/sherman/church2","south"
	});
    }
}
