
/* ########################################################
   #								  			#
   #    		druid call lightning                   #
   #            similar to lightning bolt but reduced power         #
   ###############################################t######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
   if(lev>20) return 1;
   if(lev>12) return 2;
   return 3;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "call lightning" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'call lightning' [victim]" );
	set_guild_allowed(2,12);
   set_save_vs( ELECTRICITY );
   set_save_vs_info( "for half damage" );
   set_damage_info( "level*d20 up to 20d20" );
   set_cost( 45 );
   set_player_help(
      "This spell shoots a powerful lightning bolt at the victim.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo;
   string oppo_name;
   int    odam, damage, i, lev; 

   oppo = check_target( arg );
   if ( !oppo ) {
      return;
   }
   if ( !valid_living( oppo ) ) {
      return;
   }


   lev = TPL;
   if(lev>20) lev=20;
   odam = damage = roll_dice(lev,20,0);

   if ( check_success( act_skill, max_skill ) ) {
      switch( apply(call,oppo,"do_save",Skind,Ssave,0,0,this_object()) ) {
         case IMMUNE:      damage = 0; break;
         case SAVED:       damage /= 2; break;
         case SAVE_FAILED: break;
         default:          damage = 0;
      }
      oppo_name = apply( call, oppo, "query_name" );

      write("You send a powerful lightning bolt at "+oppo_name);
      if(TP->is_invis_for(oppo))
         tell_object( oppo,
            "Suddenly a powerful lightning bolt strikes YOU!!\n");
      else
         tell_object( oppo,
            TPNT+" shoots a powerful lightning bolt at YOU!!\n");
      say( TPNT+" shoots a powerful lightning bolt at "+oppo_name,
           oppo, TP, 
           "Suddenly a powerful lightning bolt strikes "+oppo_name);


      if ( damage == 0 ) {
         write(",\nbut you couldn't overcome"+TPPOS+" magical defenses.\n" );
         say( "but "+TPPRO+"seems to be unharmed.\n" );
         tell_object( oppo, "Luckily you are not hurt.\n");
      }
      else if ( damage > apply( call, oppo, "query_hp" ) ) {
         write(",\nscattering "+TPOBJ+" across the landscape!!! *grin*\n");
         say(",\nscattering "+TPOBJ+" across the landscape!!!\n");
         tell_object( oppo, "You feel your head EXPLODE!!!!.\n");
      }
      else {
         write( ".\n");
         say( ".\n");
      }         
      WINFO("Damage by call lightning: "+damage);
      apply( call, oppo, "hit_by_spell", damage );
   }
}
