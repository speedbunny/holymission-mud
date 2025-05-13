/* SIGNPOST.C - Programmed by Colossus */
/* 230993: Ethereal Cashimor: Signposts are no treasure! */

#include "/obj/lw.h"
inherit "obj/thing";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("signpost");
    set_alias("sign");
    set_alt_name("post");
    set_short("Battered signpost");
    set_long(lw("Welcome to the Shire. To those that are unfamiliar with our "
	+ "modest town here are some places you can visit.\n\n"
	+ "East     Sheriff outpost and Thain's office\n"
	+ "West     Harbor/pier of the Shire\n"
	+ "South    Exit of the Shire\n"));
    set_can_get(0);
}
