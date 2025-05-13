
/* ################################################################
   #								  #
   #    	  	   Mage colorspray                        #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
   return 0;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "colorspray" );
   set_kind( AGGRESSIVE );
   set_syntax( "cast 'colorspray' [victim]" );
   set_save_vs( ILLUSION );
   set_damage_info( "d40+2*level" );
   set_save_vs_info( "for negation" );
   set_guild_allowed( 5, 3 );
   set_cost( 40 );
   set_player_help(
"By use of this spell you shoot a cone of sparkling colors at the face of\n"+
"your victim. This causes a piercing pain in the victim's brain.\n"+
"There is a chance that the victim will be blinded for a round.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo;
   string oppo_name;
   int    odam, damage, i, lev; 

   oppo = check_target( arg );
   if( !oppo || !valid_living( oppo ) )
   {   return; }

   lev = TPL+TP->query_legend_level();
   odam=damage = roll_dice(1, 40, 2*lev);

   if ( check_success( act_skill, max_skill ) ) {
      switch( apply(call,oppo,"do_save",Skind,Ssave,0,0,this_object()) ) {
         case IMMUNE:      damage = 0; break;
         case SAVED:       damage = 0; break;
         case SAVE_FAILED: break;
         default:          damage = 0;
      }
      oppo_name = apply( call, oppo, "query_name" );

      write("You wave your hands in "+oppo_name+"'s direction.\n");
      
      if(TP->is_invis_for(oppo))
         tell_object( oppo,
            "Suddenly a blast of colors hits your face!\n");
      else
         tell_object( oppo,
            TPNT+" waves "+TPPOS+" hands at you,\n"+
            "Suddenly a blast of colors hits your face!\n");
      say("   "+TPNT+" waves "+TPPOS+
               " hands at "+oppo_name+".\n"+
               "Suddenly a blast of colors hits "+
               oppo->query_possessive()+" face!\n", oppo, TP,
               "Suddenly a blast of colors hits "+oppo_name+"'s face!\n");

      if ( damage == 0 ) {
         write("But "+oppo->query_pronoun()+" simply ignores it.\n");
         say("But "+oppo->query_pronoun()+" simply ignores it.\n");
      }
      else {
         tell_object( oppo, "You feel a piercing pain in your head!\n");
         if(random(2))
         {
             write(capitalize(oppo->query_pronoun())+
                   " seems to be blinded!\n");
             tell_object( oppo, "You are blinded by the flash!\n");
             oppo->hold(this_object(),2);
         }
      }

      SHOWDAM(odam, damage);
      apply( call, oppo, "hit_by_spell", damage );
   }
}
