#include "/players/qclxxiv/myroom.h"
object gem1, gem2, gem3, gem4;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define MINERAL "gnomopaz"
#define MINLOOK "A tranlucent yellow piece of quartz.\n"

extra_reset(arg) {
    if (!gem1) {
    	gem1 = clone_object("players/qclxxiv/leaf7/gem");
		gem1->set_name(MINERAL);
		gem1->set_extra_long(MINLOOK);
    	move_object(gem1, this_object());
    }
    if (!gem2) {
    	gem2 = clone_object("players/qclxxiv/leaf7/gem");
		gem2->set_name(MINERAL);
		gem2->set_extra_long(MINLOOK);
    	move_object(gem2, this_object());
	}
    if (!gem3) {
    	gem3 = clone_object("players/qclxxiv/leaf7/gem");
		gem3->set_name(MINERAL);
		gem3->set_extra_long(MINLOOK);
    	move_object(gem3, this_object());
	}
    if (!gem4) {
    	gem4 = clone_object("players/qclxxiv/leaf7/gem");
		gem4->set_name(MINERAL);
		gem4->set_extra_long(MINLOOK);
    	move_object(gem4, this_object());
	}
	if (arg) return;
}

TWO_EXIT( "players/qclxxiv/leaf7/mine2","up",
"players/qclxxiv/leaf7/mine4","down",
"Inside the dwarf mines",
"Inside the dwarf mines. Many kinds of mineral are to be found here. They\n"
+"are worthless on the human market, but the dwarfs value them highly.\n"
,0)
