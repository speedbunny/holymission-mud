#define STAFF_COST this_player()->query_max_sp()
#define STAFF_LEVEL 1
#define STAFF_WC this_player()->query_level() / 3

int main( string str ) {
    object staff;

    if( present( "mage_guild_staff", this_player() ) ) {
	write( "You already have a staff.\n" );
	return( 1 );
    }
    staff = clone_object( "/players/exos/guild/obj/staff" );
    if( transfer( staff, this_player() ) ) {
	write( "You are carrying too much, and drop the staff.  It begins to fade.\n" );
	destruct( staff );
	return( 1 );
    }
    staff->set_class( STAFF_WC );
    say( sprintf( "%s summons a staff out of thin air.\n", this_player()->query_name() ),
      this_player() );
    write( "You summon a staff out of thin air.\n" );
    return( 1 );
}
