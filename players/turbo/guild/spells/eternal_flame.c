#include "bard.h"
#define ETERNAL_COST 150
#define ETERNAL_LEVEL 20

int main( string str ) {
    object weapon, shad;
    int level, timer, legend;

    if( !str ) {
	write( "Target which weapon?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    CHK_LVL( ETERNAL_LEVEL );
    CHK_SP( ETERNAL_COST );
    weapon = present( str, this_player() );
    if( !weapon || !weapon->query_weapon() ) {
	write( "Target which weapon?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( weapon->query_wielded() ) {
	write( "You cannot target a wielded weapon!\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    if( weapon->eternal_shad() ) {
	write( "That weapon is already flaming!\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( weapon->query_property( "magic_hit" ) == 1 ) {
	write( "That weapon is already magical!\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - ETERNAL_COST );
    timer = ( this_player()->query_level() * 10 ) + ( this_player()->query_legend_level() * 10 ) +
    ( this_player()->query_int() * 5 );
    level = this_player()->query_level();
    if( level > 29 )
	level = 29;
    legend = this_player()->query_legend_level();
    shad = clone_object( "/players/turbo/guild/obj/eternal_shad" );
    printf( "You complete your performance, directing the magic energies into %s.\n",
      lower_case( weapon->short() ) );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
      " performance.\n" );
    if( this_player()->query_immortal() ) 
	printf( "WIZ INFO: Timer: %d.\n", timer );
    shad->start_shadow( weapon, timer, level, legend );
    return ( 1 );
}
