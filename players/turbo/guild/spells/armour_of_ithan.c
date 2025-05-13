#include "bard.h"
#define ARMOUR_LEVEL 12
#define ARMOUR_COST this_player()->query_max_sp() / 2


int main( string str ) {
    object ithan, dummy;
    int ac, time;

    dummy = present( "armour_of_ithan", this_player() );
    if( dummy ) {
	write( "You are already protected!\n" );
	say( this_player()->query_name() + " finishes " + this_player()->query_possessive() +
            " performance.\n" );
	return ( 1 );
    }
    CHK_ATT();
    CHK_SP( ARMOUR_COST );
    CHK_LVL( ARMOUR_LEVEL );
    write( "As you complete your performance, you are encased in the Mythical Armour of Ithan!\n" );
    say( this_player()->query_name() + " concludes " + this_player()->query_possessive() +
       " performance as a Mythical glowing aura encases " + this_player()->query_objective() + 
       "!\n" );
    ithan = clone_object( OBJ + "ithan" );
    move_object( ithan, this_player() );
    ac = ( this_player()->query_level() / 5 ) + ( this_player()->query_int() / 10 );
    time = ( ( ( this_player()->query_int() + this_player()->query_wis()) * 25 ) +
        ( this_player()->query_level() * 50 ) + ( this_player()->query_legend_level() * 25 ) );
    if( this_player() -> query_immortal() ) 
       printf( "TIMER: %d seconds.\n", time );
    else
       this_player()->restore_spell_points( - ARMOUR_COST );
    if( ac > 10 )
        ac = 10;
    ithan->set_ac(ac);
    ithan->set_weight(0);
    ithan->set_timer(time);
    command( "wear armour_of_ithan", this_player() );
    return ( 1 );
}
