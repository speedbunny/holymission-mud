
/* ################################################################
   #								  #
   #    		Mage Faerie Fire                          #
   #                                          		          #
   ###############################################(C) Llort######## */
/* and druid too */


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

   set_name( "faerie fire" );
   set_kind( NON_AGGRESSIVE );
   set_guild_allowed(5,2);
   set_syntax( "cast 'faerie fire' <victim>" );
   set_save_vs( NO_SAVE );
   set_cost( 30 );
   set_player_help(
"When this spell is cast the caster outlines the victim in a pale\n"+
"glowing light.  While the faerie fire does not itself inflict harm\n"+
"upon the victim it increases the victim's armor class, making the\n"+
"victim easier to hit.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, sh;
   string oppo_name;

   oppo = check_target( arg );
   if ( !oppo ) {
      return;
   }
   if ( !valid_living( oppo ) ) {
      return;
   }
/*
   if(!allow_cast)
   {
      write("You don't belong to this guild.\n");
      return;
   }
*/


   oppo_name = apply( call, oppo, "query_name" );

   if ( check_success( act_skill, max_skill ) )
   {
        write("Ok.\n");
        if(oppo->shad_id("faerie_fire"))
        {
            write("Nothing seems to happen.\n");
        }
        else
        {
           if(TP->is_invis_for(oppo))
               tell_object(oppo,
                   "Suddenly you are surrounded by a pink aura!\n");
           else
               tell_object( oppo, TPNT+" surrounds you with a pink aura!\n");
           say( oppo_name + " is surrounded by a pink aura!\n", oppo);
           sh=clone_object("/spells/non_aggr/faerie_fire/faerie_fire_shad");
           sh->start_shadow(oppo, 600);
        };
     
   }
}
