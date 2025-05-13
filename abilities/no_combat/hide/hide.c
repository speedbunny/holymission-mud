// ------------------------------------------------------------------------ 
// hide
// used at the ninjas
// patience
// ------------------------------------------------------------------------ 

inherit  "/abilities/ability";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset(tick);
   if ( tick ) return;

   set_name( "hide" );
   set_syntax( "hide" );
   set_speed( INSTANT );
   set_guild_allowed( 8, 1 );
   set_kind( NO_COMBAT );
   set_cost( 5 );
   set_player_help( 
     "This ability allowes you to hide in the shadows. Nobody will see you\n"+
     "then. Even detect invis cannot reveal you. But you will immediately\n"+
     "snap into visibility again when you move, fight or do other things,\n"+
     "that might draw attention upon you." );
}

void display_prepare( object who )
{
   ;
}

void release( string arg, int act_skill, int max_skill )
{
   if ( check_success( act_skill, max_skill ) )
      TP->hide();

   write( "You hide in the shadows ...\n" );
}
