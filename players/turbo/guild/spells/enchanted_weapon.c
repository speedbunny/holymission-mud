#include "bard.h"
#define ENCHANTED_COST 75
#define ENCHANTED_LEVEL 14

int main( string str ) {
    object weapon, shad;
    int strength, wc, timer;

    if( !str ) {
	write( "Enchant which weapon?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    CHK_LVL( ENCHANTED_LEVEL );
    CHK_SP( ENCHANTED_COST );
    weapon = present( str, this_player() );
    if( !weapon || !weapon->query_weapon() ) {
	write( "Enchant which weapon?\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( weapon->query_wielded() ) {
	write( "You cannot enchant a wielded weapon!\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
	  " performance.\n" );
	return ( 1 );
    }
    wc = weapon->weapon_class();
    if( wc >= 20 || weapon->enchant_shad() ) {
	write( "That weapon is already enchanted!\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
	  " performance.\n" );
	return ( 1 );
    }
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - ENCHANTED_COST );
    strength = this_player()->query_level() / 4;
    timer = ( this_player()->query_level() * 15 ) + ( this_player()->query_legend_level() * 10 ) +
    ( this_player()->query_int() * 10 );
    if( this_player()->query_level() >= 29 && this_player()->query_legend_level() >= 1 ) 
	strength = 10;
    if( wc + strength > 20 ) 
	strength = ( 20 - wc );  // Don't make wc over WC20!!
    shad = clone_object( "/players/turbo/guild/obj/enchant_shad" );
    printf( "You complete your performance, directing the magic energies into %s.\n",
      lower_case( weapon->short() ) );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
      " performance.\n" );
    if( this_player()->query_immortal() ) 
	printf( "WIZ INFO: Class: %d Timer: %d.\n", ( strength + wc ), timer );
    shad->start_shadow( weapon, timer, strength );
    return ( 1 );
}
