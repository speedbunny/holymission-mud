#include "bard.h"
#define PYROTECHNICS_COST 50
#define PYROTECHNICS_LEVEL 10

int main( string str ) {
    object *all;
    int i, j, damage;
    string name;

    CHK_SP( PYROTECHNICS_COST );
    CHK_LVL( PYROTECHNICS_LEVEL );
    if( !this_player()->query_immortal() ) 
       this_player()->restore_spell_points( - PYROTECHNICS_COST );
    write( "You finish your performance, causing small fireworks to explode around the room.\n" );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
       " performance.\nSuddenly, you are caught in a shower of fireworks!\n" );
    damage = ( this_player()->query_level() * 2 + random( 10 ) + 1 + 
       this_player()->query_legend_level() / 10 );
    if( damage > 75 ) 
       damage = 75;  // Wizards could easily nuke a small army!!
    if( this_player()->query_immortal() )
	printf( "WIZ INFO: Damage %d.\n", damage );
    all = all_inventory( environment( this_player() ) );
    j = sizeof( all );
    if( j > 20 ) 
       j = 20;
    this_player()->add_xp( j * 5 );
    while( i < j ) {
	if( living( all[i] ) && all[i]->query_npc() ) {
	    all[i]->attacked_by( this_player() );
	    name = all[i]->query_name();
	    printf( "%s is burned by fireworks!\n", name );
	    say( name + " is burned by fireworks!\n" );
	    all[i]->hit_player( damage );
	}
	i++;
    }
    return ( 1 );
}
