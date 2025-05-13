inherit "/spells/spell";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "acid rain" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'acid rain'" );
   set_save_vs( ACID );
   set_save_vs_info( "for half damage" );
   set_damage_info( "LVLd25 with a maximum of 20d25" );
   set_cost( 60 );
   set_speed( 2 );
   set_guild_allowed( 8, 16 );
   set_player_help(
      "This spell is very similar to the \"acid blast\" spell, but\n"+
      "it will inflict damage upon every monster in the same room as\n"+
      "the wizard except members of the group the wizard belongs to."
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   int    d, dam, i, max_oppo;
   string oppo_name, tp_name;
   object *ai, oppo;

   if ( check_success( act_skill, max_skill ) ) {
      write( "Your ACID RAIN washes over the area ...\n" );
      say( tp_name+"'s ACID RAIN washes over the area,\n" );

      d = apply( call, TP, "query_level" );
      ai = all_inventory(environment(TP)) - TP->grmems_in_room();
      max_oppo = sizeof(ai)-1 > d/2 ? d/2 : sizeof(ai)-1;
      if ( d > 20 ) d = 20;

      for ( i = max_oppo; i >= 0; i-- ) {
         if ( living( ai[i] ) ) {
            oppo = ai[i];
            oppo_name = apply( call, ai[i], "query_name" );
            switch( apply(call,oppo,"do_save",Skind,Ssave,0,0,this_object()) ) {
               case IMMUNE:      dam = 0; break;
               case SAVED:       dam = roll_dice( d, 25, 0 ) / 2; break;
               case SAVE_FAILED: dam = roll_dice( d, 25, 0 ); break;
               default:          dam = 0;
            }
            if ( dam == 0 ) {
               write( "leaving "+oppo_name+" unharmed\n" );
               say( "leaving "+oppo_name+" unharmed\n", oppo );
               tell_object( oppo, "leaving you unharmed !!!\n" );
            }
            else if ( apply( call, ai[i], "query_hp" ) <= dam ) {
               tell_object( oppo, "KILLING you !!!\n" );
            }
            else {
               write( "oozing away flesh from "+oppo_name+"\n" );
               say( "oozing away flesh from "+oppo_name+"\n", oppo );
               tell_object( oppo,"oozing away flesh from you !!!\n" );
            }
            apply( call, oppo, "hit_by_spell", dam );
         }
      }
   }
}
