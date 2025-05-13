#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
object spliff;
query_qnewbie() { return 1; }

extra_reset() {
	if (!spliff || !present("spliff") ) {
		spliff = clone_object("players/qclxxiv/spliff");
		move_object(spliff, this_object());
	}
    set_nodig(1);
}

TWO_EXIT( "players/qclxxiv/stem/stem2","north",
"players/qclxxiv/waitingroom","south",
"A small green juicy hall",
"You are in a small green juicy hall. You have the impression that you are\n"+
"inside a huge leaf stem. In the walls flows of something are going north.\n"+
"Apparently the something is illuminating, for it is light enough in here.\n"+
"For some weird reason, here, IN the stem, you feel like it goes from south\n"+
"to north, whereas you know the stem rises up out of the ground OUTSIDE!\n"
/*
+"Reggae Dub is coming from all directions. Drum and bass are penetrating\n"+
"your body and soul, you can't keep yourself from dancing while you walk.\n"
*/
, 1)

