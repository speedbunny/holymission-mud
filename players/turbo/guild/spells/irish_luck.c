#include "bard.h"
#define LUCK_COST 75
#define LUCK_LEVEL 9

int main( string str ) {
    object target, lucky;
    int count;

    CHK_SP( LUCK_COST );
    CHK_LVL( LUCK_LEVEL );
    if( !str )
	target = this_player();
    else
	target = present( str, environment( this_player() ) );
    if( !target || !living( target ) ) {
	write( "Cast Irish Luck at whom?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( target->luck_shad() ) {
	printf( "%s is already lucky.\n", target->query_name() );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - LUCK_LEVEL );
    count = this_player()->query_level() / 3 + this_player()->query_legend_level() / 4;
    if( count > 15 )
	count = 15;
    write( "You finish a lively Irish Jig.\n" );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
      " performance with a lively Irish Jig.\n" );
    lucky = clone_object( "/players/turbo/guild/obj/luck_shad" );
    lucky->start_shadow( target, count );
    return ( 1 );
}
