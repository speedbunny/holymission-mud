#define EYE_COST 60
#define EYE_FAIL 45
#define EYE_FAIL_COST 30

int main( string str ) {
    object room, *all;
    string *direction;
    int i, j;

    /* Are we alive? */
    if( this_player()->query_ghost() ) {
	write( "That just is not possible...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Do we have the Spell Points to cast? */
    if( this_player()->query_spell_points() < EYE_COST ) {
	write( "You are too tired...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Which direction are we looking? */
    if( !str ) {
	write( "Cast Wizard Eye in which direction?\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Do we successfully cast the spell? */
    if( this_player()->query_level() * 2 + this_player()->query_int() * 2 +
      this_player()->query_wis() + random( 40 ) < EYE_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - EYE_FAIL_COST );
	return ( 1 );
    }

    /* Make sure we're in a room WITH exits! */
    direction = environment( this_player() )->query_room( "dest_dir" );
    if( !direction ) {
	write( "You can't see anything in that direction.\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return( 1 );
    }

    /* Rock and Roll Baby! */
    printf( "You send an invisible eye %s.\n", str );
    say( sprintf( "%s's eyes glow briefly!\n", this_player()->query_name() ), this_player() );


    /* Are we a wizard?  If so, keep our SP. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - EYE_COST );

    switch( str ) {
    case "s":  str="south";     break;
    case "n":  str="north";     break;
    case "e":  str="east";      break;
    case "w":  str="west";      break;
    case "sw": str="southwest"; break;
    case "se": str="southeast"; break;
    case "ne": str="northeast"; break;
    case "nw": str="northwest"; break;
    case "u":  str="up";        break;
    case "d":  str="down";      break;
    }
    for( i = 1; i < sizeof( direction ); i += 2 ) {
	if( direction[ i ] == str ) {
	    if( ( !direction[ i - 1 ] ) || ( !( room = find_object( direction[ i - 1 ] ) ) ) ) {
		write( "You seem to be blocked by a magic barrier.\n" );
	    }
	    else {
		j = 1;
		write( "You are overcome by a picture of the following area:\n\n" );
		room->long();
		all = all_inventory( room );
		for( i = 0; i < sizeof( all ); i++ )
		    if( all[ i ]->short() )
			printf( "%s\n", all[i]->short() );
	    }
	}
    }
    if( !j ) 
	write( "You can't see anything in there.\n" );

    /* Spell is done! */
    return ( 1 );
}               
