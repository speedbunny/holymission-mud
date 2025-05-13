#include "/players/mangla/mentor/ansi.h"
#include "/players/blaarg/defs.h"
string shield;
string nclone;
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
        short_desc="Blaarg's Crypt",

        /* now the long standard room description */
        /* change this to fit your style *grin* */
        long_desc=
            "This is Blaarg's Crypt.\n" +
	    "It is a peaceful sanctuary where Blaarg can code...\n";

        /* we need some exits too ... lets set the destination directions */
        dest_dir=({
            "players/jewel/workroom", "jewel",
            "players/nylakoorub/workroom", "nyla",
	    "players/tuppence/workroom", "tup",
	    "room/post", "post",
	    "room/church", "church",
            "room/adv_guild", "guild", 
                 });

        /* here could follow some item descriptions, like ...*/
        items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
              });
        /* Properties can be set like the following */
        property = ({
                     "no_sneak","no_steal",
                    });
        /* Smell is set like this... */
        smell = "This place is a bit dusty";
	
	clone_list = ({1,1,"board","obj/board",({"set_name","The Vampire Inner Circle","set_file","players/blaarg/stuff/icboard",}),});
	
	::reset(arg);
    }
}

init()
{
  ::init();
  add_action("lock_room","shield");
  add_action("no_clone","nclone");
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

no_clone(str)  {
  if (str == "on") {
	nclone = "on";
	return 1;  }
  if (str == "off")  {
	nclone = !nclone;
	return 1;  }
  if (!str && !nclone)  {
	write("nclone is off.\n");
	return 1;  }
  it (!str && nclone)  {
	write("nclone is on.\n");
	return 1;  }
}

