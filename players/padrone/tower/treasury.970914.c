/* File changed to use room/room by Ethereal Cashimor, 230293. Also changed
   to have our way of preventing teleport */
inherit "room/room";
#include "../../../obj/door.h"

object obj_1, obj_2;	/* Used by the MAKE_DOORS macro */

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

reset(arg) {
  ::reset(arg);
  if (!arg) {
    dest_dir=({"players/padrone/tower/rambo_room", "south"});
    short_desc="Treasury";
    long_desc="You are standing just outside the great door leading to the\n"
            + "vault where the treasure is stored. You notice that the floor\n"
            + "has been engraved with anti-teleport runes.\n";
    smell="The smell of gold is even stronger here!";
    items=({"vault","Probably behind the door",
            "floor","It looks smooth, except for the runes",
            "runes","They probably are very effective"});
    set_light(1);
    property = "no_teleport";

    MAKE_DOORS("players/padrone/tower/treasury", "north",
  	       "players/padrone/tower/vault", "south",
  	       "maximum-security", "vaultdoor",
  	       "This is a door made of steel and mithril, several inches thick.\n",
	     1, 1, 1);
    return;
  }
  obj_1->set_closed(1);
  obj_1->set_locked(1);
  obj_1->set_both_status();
} /* extra_reset */

/* This room is teleport-safe */
realm() { return "NT"; }

