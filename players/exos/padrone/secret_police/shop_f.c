/* SHOP_F.C - Programmed by Padrone */
/* 230291: Latest update */
/* 280993: Galadriel: Moved short_desc to /room/giant_conf */
/* 181094: Ethereal Cashimor: Added prevention against clean up */

#include "../config.h"
#include "location.h"

no_clean_up() {
  return 1;
}

id(arg) {
    return arg == "shop" || arg == "facade";
}

/* 28-SEP-93 Galadriel: It showed as 'To.. shop. is here.' */
/* The short desc is now in /room/giant_conf itself */
/*
short() {
    return "To the north, there is a shop. It is just an ordinary shop";
}
*/

long() {
    write("This is a small shop, It looks just like an ordinary shop\n" +
	  "where you can buy and sell things. It looks just like an ordinary shop.\n" +
	  "Absolutely ordinary. Nothing strange with this shop.\n");
}

init() {
    add_action("north", "north");
    add_action("enter", "enter");
}

north(str) {
    this_player()->move_player("north#players/padrone/secret_police/shop");
    return 1;
}

enter(str) {
    if (!str || !id(str))
	return 0;
    enter_dir();
    return 1;
}

get() {
	    return 0;
	}

reset(arg) {
	    if (arg)
		return;
	    move_object(this_object(), SHOP_PLACE);
	}
