#include "bard.h"
#define BANSHEE_COST 100
#define BANSHEE_LEVEL 19

int main( string str ) {
    string name;
    object *all;
    int i, j, damage;    

    CHK_LVL( BANSHEE_LEVEL );
    CHK_SP( BANSHEE_COST );
    if( !this_player()->query_immortal() ) 
	this_player()->restore_spell_points( - BANSHEE_COST );
    write( "You finish your performance with a wail of death and anguish!\n" );
    say( this_player()->query_name() + " finishes " + this_player()->query_possessive() + 
      " performance.\n\Suddenly, " + this_player()->query_name() + 
      " releases a hideous wail filled with death and anguish!\n" );
    damage = ( this_player()->query_level() * 4 + this_player()->query_legend_level() );
    if( damage > 150 ) 
	damage = 150;  // Wizards could easily nuke a small army!!
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
	    printf( "%s collapses in pain and anguish!\n", name );
	    say( name + " collapses in pain and anguish!\n" );
	    all[i]->hit_player( damage );
	} 
	i++;
    }
    return ( 1 );
}
