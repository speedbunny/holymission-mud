
inherit "obj/monster";

#include "/players/apollo/guild/barb.h"

reset(arg) {
    int rnd;
    object arm;
    string arm_name;

    ::reset( arg );

    if ( arg )
	return;

    set_name("Barbarian Guard");
    set_level( 13 + random(5) );
    set_size(3);
    set_alias("guard");
    set_hp(1500);
    set_gender(1);
    set_number_of_arms(3);
    set_race("Crom");

    set_short("A barbarian guard");

    set_long("The barbarian guard is on duty and doesnt like strangers\n"+
      "walking around in the camp, so don't give him any trouble.\n");

    rnd = random( 70 );
    switch( rnd ) {
    case 0..10:
	transfer( arm= CO( GARMOUR+"shield"),TO );
	break;
    case 11..21:
	transfer( arm= CO( GARMOUR+"bands" ), TO);
	break;
    case 22..27:
	transfer( arm= CO( GARMOUR+"mail" ),TO );
	break;
    case 28..40:
	transfer( arm= CO( GARMOUR+"helmet" ),TO );
	break;
    case 41..49:
	transfer( arm= CO( GARMOUR+"link" ),TO );
	break;
    case 50..60:
	transfer( arm= CO( GARMOUR+"mix" ),TO );
	break;
    case 61..63:
	transfer( arm= CO( GARMOUR+"ring" ),TO );
	break;
    case 64..67:
	transfer( arm= CO( GARMOUR+"lion_fur" ),TO );
	break;
    case 68..70:
	transfer( arm= CO( GARMOUR+"bear_fur" ),TO );
	break;
    default: 
	break;
    }

    if (objectp(arm)) {
	arm_name = arm->query_name();
	command("powerup");
    }
}

