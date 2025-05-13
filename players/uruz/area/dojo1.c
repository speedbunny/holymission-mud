
inherit "room/room";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;

	set_light(1);
	short_desc="Foyer";
	long_desc="You are now in the foyer of the great Hwarang-Do Karate "+
	"Dojo. The walls are decorated with several banners, in assorted "+
	"colors. The foyer slightly curves, wrapping around to doorways at "+
	"the north and south ends. A large double door stand directly in "+
	"front of you. \n";
	DD= ({
		ZZ+"/mroad2", "west",
		ZZ+"/dojo3", "south",
		ZZ+"/dojo4", "east" });
	items= ({ "banners", "There are three banners here, with writings on "+
	"them. There is a black one, a red one, and a purple one " ,
	"black banner", "It has the word 'Nae Gong' on it. On the bottom "+
	"it reads 'Internal Power' ",
	"red banner", "It has the word 'Wae Gong' on it. On the bottom it "+
	"reads 'External Power' ",
	"purple banner", "It has the word 'Shing Gong' on it. On the bottom "+
	"it reads 'Mental Power'",
		"door", "A tall, thick double door with a brass ring" });
	::reset(arg);
	replace_program("room/room");
	}
