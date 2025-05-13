#include "bard.h"
#include "legend_lore.h"
#define LEGEND_COST 25
#define LEGEND_LEVEL 2

int main( string str ) {    string maker;
    int getal;
    object obj;
    if( !str ) {
	write( "You need a target to do this!\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
           " performance.\n" );
	return ( 1 );
    }
    obj = present( str, this_player() );
    if( !obj ) {	printf( "You cannot seem to find the %s.\n", str );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
           " performance.\n" );
	return ( 1 );
    }
    CHK_ATT();
    CHK_SP( LEGEND_COST );
    CHK_LVL( LEGEND_LEVEL );
    printf("You complete your performance.\n\
Magical energies swirl around %s.\nRunes appear in the magic aura that read:\n", 
    lower_case( obj->short() ) );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + " performance.\n" +
      "Magical energies swirl around " + lower_case( obj->short() ) + ".\n" );
    if( !this_player()->query_immortal() ) 
       this_player()->restore_spell_points( - LEGEND_COST );
    obj->long();    write( "\n" );    if( obj->query_name() ) 
       printf( "It's name is: %s.\n", obj->query_name() );     if( obj->query_info() ) 
       printf( "You seem to remember:\n%s\n", obj->query_info() );
    if( obj->prevent_insert() ) 
       write( "It will not fit into a container.\n" );    else 
       write( "It should fit a standard container.\n" );    getal = obj->query_value();    if( getal <= 0 )
       write( "It appears to be worth nothing.\n" );     else {	if( getal == 1 )
           write( "It has a value of one gold coin.\n" );	else 
           printf("It has a value of %d gold coins.\n", getal);     }     printf( "%s\n", parse_weight( obj->query_weight() ) );
    if( obj->query_armour() ) 
        printf( "%s\n", parse_armour( obj ) );
    if( obj->can_put_and_get() ) 
        printf( "%s\n", parse_container( obj ) );
    if( obj->query_drink() ) 
        printf( "%s\n", parse_drink( obj ) );
    if( obj->query_food() ) 
        printf( "%s\n", parse_food( obj ) );
    if( obj->id( "remains" ) ) 
        write( "Yes, it is definitely dead.\n" );    if( obj->query_auto_load() ) 
        write( "It will stick with you forever.\n" );    if( obj->query_weapon() ) 
        printf( "%s\n", parse_weapon( obj ) );
    maker = obj->query_creator();    if( !maker ) maker = creator( obj );    if( maker ) 
       printf("It was created by: %s.\n", capitalize( maker ) );    if( obj->extra_look() ) 
       printf( "It causes: %s.\n", obj->extra_look() );    return ( 1 );}