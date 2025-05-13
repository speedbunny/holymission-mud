inherit "/spells/spell";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "acid blast" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'acid blast' [opponent]" );
   set_save_vs( ACID );
   set_save_vs_info( "for half damage" );
   set_damage_info( "LVLd25 with a maximum of 20d25" );
   set_cost( 45 );
   set_speed( 1 );
   set_guild_allowed( 8, 13 );
   set_player_help(
      "By means of this spell, the wizards hurls a blast of acid onto\n"+
      "his/her opponent, causing flesh ooze away!"
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo;
   int    d, dam;
   string oppo_name, tp_name;

/* no change from there to.... */

   oppo = check_target( arg );
   if ( !oppo )
      return;
   if ( !valid_living( oppo ) )
      return;

/* .. here  */

   d = apply( call, TP, "query_level" );
   if ( d > 20 ) d = 20;

/* don't change te funcition below */
   if ( check_success( act_skill, max_skill ) ) {
      switch( apply(call,oppo,"do_save",Skind,Ssave,0,0,this_object()) ) {
         case IMMUNE:      dam = 0; break;
         case SAVED:       dam = roll_dice( d, 25, 0 ) / 2; break;
         case SAVE_FAILED: dam = roll_dice( d, 25, 0 ); break;
         default:          dam = 0;
      }
/* ....    */
      oppo_name = apply( call, oppo, "query_name" );
      tp_name = apply( call, TP, "query_name" );

      write( "Your ACID BLAST hits your opponent with full force,\n" );
      say( tp_name+"'s ACID BLAST hits "+oppo_name+"with full force,\n", oppo );
      tell_object( oppo, tp_name+"'s ACID BLAST hits you with full force,\n" );
      if ( dam == 0 ) {
         write( "but leaving "+oppo_name+" unharmed.\n" );
         say( "but leaving "+oppo_name+" unharmed.\n" );
         tell_object( oppo, "but leaving you unharmed.\n" );
      }
      else if ( dam <= apply( call, oppo, "query_hp" ) ) {
         write( "oozing away junks of flesh !\n" );
         say( "oozing away junks of flesh !\n", oppo );
         tell_object( oppo, "oozing away junks of flesh !\n" );
      }
      else {
         write( "leaving smoking ooze !!!!      YOU BIG BRUTE !\n" );
         say( "leaving smoking ooze !!!!\n", oppo );
        tell_object(oppo,"leaving smoking ooze where you have been before !\n");
      }         

/* that you need too */

      apply( call, oppo, "hit_by_spell", dam );
   }
}
