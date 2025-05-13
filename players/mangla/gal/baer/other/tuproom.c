#include "/players/mangla/mentor/ansi.h"
#include "/players/tuppence/defs.h"
string shield;
object tree;
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
inherit "room/room";
#define CNAME   capitalize(NAME)

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
    /* do the following block only the first time !! */
    if(!arg) {
	/* first we need some light in here */
	set_light(1);

	/* then lets set a short description in case we are in brief-mode */
	short_desc="Tuppy's workroom",

	/* now the long standard room description */
	/* change this to fit your style *grin* */
	long_desc=
	"It looks very Baer in here.\n";

	/* we need some exits too ... lets set the destination directions */
	dest_dir=({
	  "players/baer/workroom","ANDY",
	  "players/moonchild/newbie/hut","hut",
	  "players/beezlebub/workroom","beezy",
	  "players/sauron/workroom","sauron",
	  "players/morrolan/workroom","marky",
	  "players/silas/workroom","silas",
	  "players/blaarg/workroom","blaargy",
	  "players/silver/workroom","silver",
	  "players/soozie/workroom","soozie",
	  "players/waldo/workroom","wally",
	  "players/arthur/workroom","arthur",
	  "players/darastor/workroom","popeye",
	  "players/tuppence/fortress/entrance","fortress",
	  "players/saffron/workroom","saffy",
	  "players/mork/workroom","morky",
	  "players/linsolent/workroom","linso",
	  "players/matt/newworld/city/rooms/votebooth","vote",
	  "players/airborne/workroom","puppy",
	  "players/portil/workroom","portil",
	  "players/bonzo/workroom","bonzo",
	  "players/baalthasar/workroom","baaly",
	  "players/haplo/workroom","bro",
	  "players/whisky/guild/room/c10","Mguild",
	  "players/tegerl/workroom","tegerl",
	  "players/herp/games/4win","con4",
	  "room/post", "post",
	  "room/church", "church",
	  "room/adv_guild","adv_guild",
	  "players/tatsuo/workroom","tat",
	});

tree = clone_object("players/tuppence/personal/tree.c");
move_object(tree,this_object());
       transfer( clone_object( "/boards/tuppie" ), this_object() );
	/* here could follow some item descriptions, like ...*/
	items=({ 
	  "air","It's very thin up here",
	  "perch","You see a golden perch for Grunge to sit on",
	  "floor","The floor is dirty",
	});
	/* Properties can be set like the following */
	property = ({
	  "no_sneak","no_steal",
	});
	/* Smell is set like this... */
	smell = "Smells like pine needles";

	::reset(arg);
    }
}

init()
{
    ::init();
this_player()->set_smell("They smell like candycanes from Tuppy's workroom.\n");
    add_action("_shield","shield");
    if (shield && TP->RNAME != "tuppence") {
	write("Tuppy is coding go away!\n");
	move_object(TP,"/room/church");
    }
    if (FP("tuppence") && TP->RNAME != "tuppence" && !shield) {
	tell_object(FP("tuppence"),BOLD+RED+TP->RNAME+" has entered your workroom.\n");
	tell_object(FP("tuppence"),RESET);
    }
}

_shield(str) {
    if (str == "on") {
	shield = "on";
	return 1;
    }
    if (str == "off") {
	shield = !shield;
	return 1;
    }
    if (!str && !shield) {
	write("shield is off\n");
	return 1;
    }
    if (!str && shield) {
	write("shield is on\n");
	return 1;
    }
}


_clone(str) {
    if (TP->RNAME != "tuppence") {
	write("DONT THINK SO BUB!\n");
	return 1;
    }
}
