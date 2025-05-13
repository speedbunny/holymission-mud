
inherit "/players/patience/GenObj/storeroom";

#include "/players/apollo/guild/barb.h"

reset( arg ) {
    if (!sizeof(all_inventory(TO) ) ) {
	MO(CO(GWEAPONS+"club"),TO);
	MO(CO(GWEAPONS+"club"),TO);
	MO(CO(GWEAPONS+"club"),TO);
	MO(CO(GWEAPONS+"club"),TO);
	MO(CO(GWEAPONS+"club"),TO);
	MO(CO(GWEAPONS+"hammer"),TO);
	MO(CO(GWEAPONS+"hammer"),TO);
	MO(CO(GWEAPONS+"hammer"),TO);
	MO(CO(GWEAPONS+"jaw"),TO);
	MO(CO(GWEAPONS+"jaw"),TO);
	MO(CO(GWEAPONS+"b_axe"),TO);
	MO(CO(GWEAPONS+"b_axe"),TO);
	MO(CO(GWEAPONS+"bro_sword"),TO);
	MO(CO(GWEAPONS+"bast_sword"),TO);
    }
    ::reset( arg );

    if ( !arg ) {
	set_trader( "Stormlord" );
	set_info( "Weapon" );
    }
}

check_allow( ob ) {
    if ( ob )
	return( ob->query_weapon() );

    return( 0 );
}
