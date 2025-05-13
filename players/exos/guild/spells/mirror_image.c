#define MIRROR_COST 60
#define MIRROR_FAIL 45
#define MIRROR_FAIL_COST 30

int main( string str ) {
    object target, mirrorer;
    int level, images;

    /* Are we alive? */
    if( this_player()->query_ghost() ) {
	write( "That just is not possible...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Do we have the Spell Points to cast? */
    if( this_player()->query_spell_points() < MIRROR_COST ) {
	write( "You are too tired...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Can we see our target? */
    if( this_player()->test_dark() ) {
	write( "It is much too dark!\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return( 1 );
    }

    /* Who is our target? */
    if( !str ) 
	target = this_player();
    else
	target = present( str, environment( this_player() ) );
    if( !target || !living( target ) ) {
	write( "Cast Mirror Image at whom?\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    /* Is our target already effected? */
    if( target->mirror_shad() ) {
	printf( "%s is already mirrored!\n", target->query_name() );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return( 1 );
    }

    /* Do we successfully cast the spell? */
    if( this_player()->query_level() * 2 + this_player()->query_int() * 2 +
      this_player()->query_wis() + random( 40 ) < MIRROR_FAIL ) {
	write( "Your spell fizzles!\n" );
	say( this_player()->query_name() + "'s spell fizzles!\n", this_player() );
	this_player()->restore_spell_points( - MIRROR_FAIL_COST );
	return ( 1 );
    }

    /* Rock and Roll Baby! */
    level = ( this_player()->query_level() );
    if( level > 30 )
	level = 30;
    images = level / 2;
    if( target == this_player() ) {
	write( "You perform delicate hand motions...\n" );
	say( this_player()->query_name() + " performs some delicate hand motions.\n" );
    }
    else {
	printf( "You perform delicate hand motions over %s.\n", target->query_name() );
	say( this_player()->query_name() + " performs some delicate hand motions over " +
	  target->query_name() + ".\n", target );
	tell_object( target, this_player()->query_name() +
	  " performs some delicate hand motions over your head.\n" );
    }
    mirrorer = clone_object( "/players/exos/mage/shadows/mirror_shad" );
    mirrorer->start_shadow( target, images );

    /* Are we a wizard?  If so, keep our SP and tell us the number of images. */
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - MIRROR_COST );
    else
	printf( "WIZINFO:  Images %d.\n", images );

    /* Spell is done! */
    return ( 1 );
}
