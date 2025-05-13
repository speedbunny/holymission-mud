
inherit "obj/monster";

#include "/players/apollo/guild/barb.h"

object jaw;

reset(arg) {
 ::reset(arg);
 if(arg) return;

    set_name("Stubborn Donkey");
    set_alias("donkey");
    set_short("Stubborn Donkey");
    set_long("A very stubborn donkey that doesn't want to move for anyone.\n");
    set_level( 10 + random(3) );
    set_hp(700);
    set_gender(1);
    set_race("mule");
    set_ac(7);
    set_wc(10);
    set_number_of_arms(3);

    jaw = clone_object("/players/apollo/guild/weapons/jaw");
	    transfer(jaw,this_object());

    init_command("powerup");
}

