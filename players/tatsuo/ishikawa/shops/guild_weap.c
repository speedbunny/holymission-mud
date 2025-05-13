#define TO (this_object())

inherit "/players/patience/GenObj/storeroom";

reset( arg )
{
    if (!sizeof(all_inventory(TO) ) )
    {
	transfer( clone_object( "/players/patience/guild/nweap/yari"), TO );
	transfer( clone_object( "/players/patience/guild/nweap/yari"), TO );
	transfer( clone_object( "/players/patience/guild/nweap/sa-tja-koen"), TO );
	transfer( clone_object( "/players/patience/guild/nweap/sa-tja-koen"), TO );
	transfer( clone_object( "/players/patience/guild/nweap/nstick"), TO );
	transfer( clone_object( "/players/patience/guild/nweap/nstick"), TO );
	transfer( clone_object( "/players/patience/guild/nweap/nstick"), TO );
	transfer( clone_object( "/players/patience/guild/nweap/nstick"), TO );
    }
    if (!present("/players/patience/guild/nweap/dart", TO)) {
        transfer(clone_object("/players/patience/guild/nweap/dart"),TO);
        transfer(clone_object("/players/patience/guild/nweap/dart"),TO);
        transfer(clone_object("/players/patience/guild/nweap/dart"),TO);
        transfer(clone_object("/players/patience/guild/nweap/dart"),TO);
    }
    ::reset( arg );

    if ( !arg ) {
        set_trader( "Higuchi Sunami" );
	set_info( "Weapon" );
    }
}

check_allow( ob )
{
    if ( ob )
	return( ob->query_weapon() );

    return( 0 );
}
