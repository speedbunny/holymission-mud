inherit "obj/monster";
#include "/players/blaarg/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Uykio");
    set_alias("uykio");
    set_short("Uykio");
    set_long("Uykio, the beautiful sister of Akane, is the owner of the local\n"+
	     "shop.  She, however, doesn't like it that you are in her private\n"+
	     "house!  After a few seconds, however, she just ignores your presence.\n"); 
    set_level(25);
    set_al(750);
    set_hp(1000);
    set_gender(2);
    set_race("anime");
    add_money(3000);
    set_wc(17);
    set_ac(10);

}

