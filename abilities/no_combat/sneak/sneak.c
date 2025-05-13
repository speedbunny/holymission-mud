// ------------------------------------------------------------------------ 
// sneak
// used at the ninjas
// patience
// ------------------------------------------------------------------------ 

inherit  "/abilities/ability";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset(tick);
   if ( tick ) return;

   set_name( "sneak" );
   set_syntax( "sneak" );
   set_speed( INSTANT );
   set_guild_allowed( 8, 1 );
   set_kind( NO_COMBAT );
   set_cost( 10 );
   set_player_help( 
     "This ability allowes you to move silently. When you sneak into a room,\n"+
     "nobody will know that you have arrived. However, when somebody looks\n"+
     "around you will be detected. Combined with the hide this ability is\n"+
     "very powerful." );
}

void display_prepare( object who )
{
   ;
}

void release( string arg, int act_skill, int max_skill )
{
   if ( TP->query_sneaking() ) {
      write( "You no longer try to move silently ...\n" );
      TP->stop_sneak();
      return;
   }

   if ( check_success( act_skill, max_skill ) )
      TP->sneak();

   write( "You try to move silently from now on ...\n" );
}
