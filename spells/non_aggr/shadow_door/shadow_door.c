inherit "/spells/spell";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset(tick);

   if ( tick ) return;

   set_name( "shadow door" );
   set_kind( NON_AGGRESSIVE );
   set_syntax( "cast 'shadow door'" );
   set_save_vs( ILLUSION );
// set_save_vs_info( "" );
   set_duration_info( "10 minutes" );
// set_damage_info( "" );
   set_cost( 50 );
   set_speed( 3 );
   set_guild_allowed( 8, 8 );
   set_player_help(
     "By means of this spell the wizard creates an illusion of a door.\n"+
     "The illusion also permits the wizard to step through this door and\n"+
     "disappear. Behind the door is a chamber where the wizard can rest\n"+
     "and heal from his/her wounds. Other players or monsters can enter\n"+
     "when they detect the door. The chamber will vanish after the spell\n"+
     "has expired, killing everybody who is still in the chamber !"
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object door;
   int    old_lang;

   if ( random(100) < act_skill ) {
      door = clone_object("/spells/non_aggr/shadow_door/shadow_door_door");
      if ( door ) {
         if ( !transfer( door, environment(TP) ) ) {
            door->init_door();
            write( ".....and a shadow door appears.\n" );
            say( ".....and a shadow door appears.\n" );
         }
         else
            write( ".....but nothing happens.\n" );
      }
      else 
         write( ".....but nothing happens.\n" );
   }
   else
      write( ".....but nothing happens.\n" );

   if ( !apply( call, TP, "query_immortal" ) )
      apply( call, TP, "restore_spell_points", -1*cost() );
}
