/* Coded by Llort */
/* Spruced up by Saffrin */

inherit "obj/monster";
#include "/players/saffrin/area/tower/quest/cellar.h"

reset(arg) {
    ::reset(arg);
    if (arg) return;

    load_chat(20,({
	"The big rat smells your foot.\n",
	"The big rat searches around.\n",
	"The big rat squeeks intently.\n",
      }));

    load_a_chat(80,({
	"The big rat bites you in your arm.\n",
	"The big rat bites you in your knee.\n",
	"Squiieeeekkkk.\n",
      }));

    set_name("a big black rat");

    set_alias("black rat");

    set_race("rat");

    set_short("A big black rat");

set_long("A big black rat that is scurrying around searching\n"+
      "for something to eat.\n");

    set_level(8);

    set_size(1);

    set_wc(12);

    set_hp(150);

    set_whimpy(40);

    set_al(-10);
}
init() {
    if (present("cheese",this_player())) {
	attack_object(this_player());
	tell_room(environment(),"The rat smells your cheese !\n"); }
    ::init();
}




