
/* ################################################################
   #								  #
   #    		  Mage gate spell                         #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
    if(lev > 25) return 1;
    return 2;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "gate" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'gate' <target>" );
   set_guild_allowed( 5, 22 );
   set_save_vs( NO_SAVE );
   set_cost( 150 );
   set_player_help(
"This spell causes a magic gate to appear at the given target. One creature\n"+
"can enter this gate to be transported to place where the gate was casted at.\n"+
"However there exist places that can't be reached with that spell.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
   string oppo_name;
   object oppo,gate;

   if(!arg) {
      write("Open a gate to whom ?\n");
      return;
   } 
   oppo=find_living(arg);
   if(!oppo) {
      write("You are not able to find "+arg+".\n");
      return;
   }
   if(!oppo->query_player()) {
      write("You can only open a gate to a player.\n");
      return;
   }
   if(!TP->query_immortal() && oppo->query_immortal()) {
      write("You can not open a gate to a wizard.\n");
      return;
   }
   if(environment(oppo)->query_property("no_teleport") ||
       environment(TP)->query_property("no_teleport")) {
      write("A strange magical force seems to block the spell.\n");
      return;
   }

   if ( check_success( act_skill, max_skill ) )
   {
      move_object(gate=clone_object("spells/no_combat/gate/gate_ob"),
                  environment(oppo));
      gate->set_gate(TP);
      write("You open a gate to "+oppo->query_name_true()+".\n");
   }
}
