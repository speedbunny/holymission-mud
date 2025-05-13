inherit "/players/patience/GenObj/storeroom";
#include "/players/apollo/guild/barb.h"

reset( arg ) {
    ::reset( arg );

    if(!sizeof(all_inventory(TO))){
	MO( CO( GARMOUR + "bands" ), TO );
	MO( CO( GARMOUR + "bands" ), TO );
	MO( CO( GARMOUR + "helmet" ), TO );
	MO( CO( GARMOUR + "helmet" ), TO );
	MO( CO( GARMOUR + "helmet" ), TO );
	MO( CO( GARMOUR + "mail" ), TO );
	MO( CO( GARMOUR + "mail" ), TO );
	MO( CO( GARMOUR + "ring"), TO );
	MO( CO( GARMOUR + "shield" ), TO );
	MO( CO( GARMOUR + "mix" ), TO );
	MO( CO( GARMOUR + "shield" ), TO );
	MO( CO( GARMOUR + "shield" ), TO );
	MO( CO( GARMOUR + "shield" ), TO );
	MO( CO( GARMOUR + "shield" ), TO );

    }

    if ( !arg ) {
	set_trader("Kilrathi");
	set_info( "Armour" );
    }
}

check_allow( ob )
{
    if ( ob )
	return( ob->query_armour() );

    return( 0 );
}
