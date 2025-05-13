
/* ################################################################
   #								  #
   #    		Mage Magic Missile                        #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
   if(lev > 21) return 0;
   return 1;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "magic missile" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'magic missile' [victim]" );
   set_save_vs( NO_SAVE );
   set_damage_info( "level/2*(d20+5) for every 2nd level up to level 20" );
   set_guild_allowed( 5, 1 );
   set_cost( 30 );
   set_player_help(
"For every second level up to level 20 an energy bolt flies from your\n"+
"hands towards your victim, inflicting 1d20+4 points of damage.\n\n"+
"The spell shield will completely negate the effects of this spell.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo;
   string oppo_name;
   int    odam, damage, i, lev; 

   oppo = check_target( arg );
   if( !oppo || !valid_living( oppo ) )
   {   return; }

   lev = TPL;
   lev = (lev+1)/2;
   if(lev>10) lev=10;
   odam=damage = roll_dice(lev, 20, 5*lev);

   if ( check_success( act_skill, max_skill ) ) {
      switch( apply(call,oppo,"do_save",Skind,Ssave,0,0,this_object()) ) {
         case IMMUNE:      damage = 0; break;
         case SAVED:
         case SAVE_FAILED: break;
         default:          damage = 0;
      }
      oppo_name = apply( call, oppo, "query_name" );

      write("   As you raise your hands, pointing at your enemy,\n  "+lev+
            "  bolts of energy shoot out, seeking their target!\n");
      if(TP->is_invis_for(oppo))
         tell_object( oppo,
            "   Suddenly several energy bolts strike you!\n");
      else
         tell_object( oppo,
            "   "+TPNT+" raises "+TPPOS+" hands, pointing at you!!\n"+
            "   Suddenly several energy bolts strike you!\n");
      say("   "+TPNT+" raises "+TPPOS+
               " hands, pointing at "+oppo_name+".\n"+
               "   Suddenly several energy bolts strike "+
               oppo->query_objective()+"!\n", oppo, TP,
               "   Suddenly several energy bolts strike "+
               oppo_name+"!\n");

      if ( damage == 0 ) {
         write("But an invisible force field seems to block the attack.\n");
         say("But an invisible force field seems to block the attack.\n");
      }
      else if ( damage > apply( call, oppo, "query_hp" ) ) {
         write("           >>> Ripping "+TPOBJ+" apart <<<\n");
         say ("           >>> Ripping "+TPOBJ+" apart <<<\n");
         tell_object( oppo, "   You try to avoid the missiles, but NO WAY!\n");
      }

      SHOWDAM(odam, damage);
      apply( call, oppo, "hit_by_spell", damage );
   }
}
