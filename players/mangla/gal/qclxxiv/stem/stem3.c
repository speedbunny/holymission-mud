#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
    set_nodig(1);
}

query_qnewbie() { return 1; }

TWO_EXIT( "players/qclxxiv/circular/circ0","north",
"players/qclxxiv/stem/stem2","south",
"A small green juicy hall",
"You are in a small green juicy hall. You have the impression that you are\n"+
"inside a huge leaf stem. In the walls flows of something are going north.\n"+
/*"Apparently the something is illuminating, for it is light enough in here.\n"+
*/
"Reggae Dub is coming from all directions. Perfect blazing horns drill their\n"+
"way through your head, you just can't keep away a smile, and feel good.\n", 1)
