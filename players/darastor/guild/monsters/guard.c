
inherit "obj/monster";

#include "/players/darastor/guild/barb.h"

reset(arg) {
    int rnd;
    object wep;
    string wep_name;

    ::reset( arg );

    if ( arg ) return;

    set_name("Barbarian Guard");
    set_level( 13 + random(10) );
    set_size(3);
    set_alias("guard");
    set_hp(1500);
    set_gender(1);
    set_number_of_arms(3);
    set_race("Crom");

    set_short("A Barbarian Guard");

    set_long("The barbarian guard is watching over the lands for signs\n"+
      "of trouble or any orcs trying to raid there camp. Maybe you can ask\n"+
      "the guard some questions.\n");

    add_property("has_answers",([
	"camp": "The camp is around here...",
	"fight": "You want to fight me? I'll take you down...",
	"name": "Why do you want to know...?",
	"guard": "Yea, I'm a top barbarian guard...",
	"guild": "You can join if you can find the sacred iron piece..."]));

    rnd = random( 50 );
    switch( rnd ) {
    case 0..10:
	transfer( wep= CO( GWEAPONS+"jaw" ),TO );
	break;
    case 11..21:
	transfer( wep= CO( GWEAPONS+"club" ),TO );
	break;
    case 22..27:
	transfer( wep= CO( GWEAPONS+"hammer" ),TO );
	break;
    case 28..40:
	transfer( wep= CO( GWEAPONS+"bast_sword" ),TO );
	break;
    case 41..49:
	transfer( wep= CO( GWEAPONS+"b_axe" ),TO );
	break;
    default: 
	break;
    }

    if (objectp(wep)) {
	wep_name = wep->query_name();
	command("powerup");
    }
}

