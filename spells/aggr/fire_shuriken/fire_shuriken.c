inherit "/spells/spell";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "fire shuriken" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'fire shuriken' [opponent]" );
   set_save_vs( FIRE );
   set_save_vs_info( "for half damage" );
   set_damage_info( "LVLd5" );
   set_cost( 20 );
   set_speed( 1 );
   set_guild_allowed( 8, 5 );
   set_player_help(
      "This spell will cause the air in your hand to form as a shuriken.\n"+
      "This shuriken will heat up magically and can be hurled upon your\n"+
      "opponent." 
   );
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo;
   int    d, dam;
   string oppo_name, tp_name;

   oppo = check_target( arg );
   if ( !oppo )
      return;
   if ( !valid_living( oppo ) )
      return;

   d = apply( call, TP, "query_level" );

   if ( check_success( act_skill, max_skill ) ) {
      switch( apply(call,oppo,"do_save",Skind,Ssave,0,0,this_object()) ) {
         case IMMUNE:      dam = 0; break;
         case SAVED:       dam = roll_dice( d, 5, 0 ) / 2; break;
         case SAVE_FAILED: dam = roll_dice( d, 5, 0 ); break;
         default:          dam = 0;
      }
      oppo_name = apply( call, oppo, "query_name" );
      tp_name = apply( call, TP, "query_name" );

      write( "Your FIRE SHURIKEN hits your opponent with full force,\n" );
      say(tp_name+"'s FIRE SHURIKEN hits "+oppo_name+" with full force, ",oppo);
      tell_object(oppo, tp_name+"'s FIRE SHURIKEN hits you with full force,\n");
      if ( dam == 0 ) {
         write( "but leaving "+oppo_name+" unharmed.\n" );
         say( "but leaving "+oppo_name+" unharmed.\n" );
         tell_object( oppo, "but leaving you unharmed.\n" );
      }
      else if ( dam <= apply( call, oppo, "query_hp" ) ) {
         write( "searing flesh in "+apply(call,oppo,"query_possessive")+
                " face !\n" );
         say( "searing flesh in "+apply(call,oppo,"query_possessive")+
              " face !\n", oppo );
         tell_object( oppo, "searing flesh in your face !\n" );
      }
      else {
         write( "BLOWING AWAY "+apply(call,oppo,"query_possessive")+
                " head !\n" );
         say( "BLOWING AWAY "+apply(call,oppo,"query_possessive")+
              " head !\n", oppo );
        tell_object(oppo,"BLOWING AWAY your head !\n");
      }         

      apply( call, oppo, "hit_by_spell", dam );
   }
}
