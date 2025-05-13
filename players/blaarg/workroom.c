#include "/players/mangla/mentor/ansi.h"
#include "/players/blaarg/defs.h"
string shield;
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
inherit "room/room";
#define CNAME   capitalize(NAME)

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
    /* do the following block only the first time !! */
    if(!arg) {

	object board;
        /* first we need some light in here */
        set_light(1);

        /* then lets set a short description in case we are in brief-mode */
        short_desc="Blaarg's Crypt",

        /* now the long standard room description */
        /* change this to fit your style *grin* */
        long_desc=
	    "As you walk into the room, you find that you must\n" +
	    "take a few moments to let your eyes adjust to the\n" +
	    "extremely dim light provided by two small candles\n" +
	    "and a torch. In the center of the room...the only\n" +
	    "decoration...a walnut coffin, open for quick entry.\n" +
	    "\nThis is Blaarg's Crypt.\n\n";

        /* we need some exits too ... lets set the destination directions */
        dest_dir=({
            "players/jewel/workroom", "jewel",
            "players/nylakoorub/workroom", "nyla",
	    "players/tuppence/workroom", "tup",
	"players/tinman/workroom", "tinman",
	"players/blaarg/area/rooms/entry", "ranma",
	    "room/post", "post",
	    "room/church", "church",
            "room/adv_guild", "guild", 
                 });

        /* here could follow some item descriptions, like ...*/
        items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
	    "coffin","The walnut coffin is lined with black silk",
              });
        /* Properties can be set like the following */
        property = ({
                     "no_sneak","no_steal",
                    });
        /* Smell is set like this... */
        smell = "This place is a bit dusty";
	
	board=clone_object("/boards/private_boards/blaarg");
	transfer(board,this_object());
	::reset(arg);
    }
}

init()
{
  ::init();
  if (TP->RNAME == "blaarg") {
  	add_action("lock_room","shield");
	}
  if (shield && TP->RNAME != "blaarg")  {
	write("the Vampire is resting...come back later.\n");
	move_object(TP,"/room/church");  }
  if (FP("blaarg") && TP->RNAME != "blaarg" && !shield) {
	tell_object(FP("blaarg"),TP->RNAME+" has entered your crypt.\n"); }
}

lock_room(str) {
  if (str == "lock") {
	shield = "on";
	return 1;  }
  if (str == "unlock") {
	shield = !shield;
	return 1;  }
  if (!str && !shield) {
	write("shield is off.\n");
	return 1;  }
  if (!str && shield)  {
	write("shield is on.\n");
	return 1;  }
}

