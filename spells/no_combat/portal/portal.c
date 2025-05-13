
/* ################################################################
   #								  #
   #    		  Mage Portal spell                       #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
    return 3;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "portal" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'portal' <target>" );
   set_guild_allowed( 5, 30 );
   set_save_vs( NO_SAVE );
   set_cost( 300 );
   set_player_help(
"This spell causes a magic portal to appear to the given target. The creatures\n"+
"entering this portal will be transported to the area where the target located\n"+
"as the portal was casted.\n"+
"However there exist places that can't be reached with that spell.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
   string oppo_name, *hlp;
   object oppo,gate;

   if(!arg)
   {
      write("Open a portal to whom ?\n"); 
      return;
   } 
   oppo=find_living(arg);
   if(oppo && !environment(oppo))
   {
      destruct(oppo);
      oppo=find_living(arg);
   }
   if(!oppo || !environment(oppo)) {
      write("You are not able to find "+arg+".\n");
      return;
   }
   if(!TP->query_immortal() && oppo->query_immortal()) {
      write("You can not open a portal to a wizard.\n");
      return;
   }
   if(environment(TP)->plane_name()!=oppo->plane_name())
   {
      write("Destination on another plane.\n");
      return;
   }
   hlp=explode(file_name(environment(oppo)),"/");
// check for newwiz-area
   if(sizeof(hlp)>2 && hlp[0]=="players")
   {
      if(master_object()->get_wiz_level(hlp[1]) < 33)
      {
          write("The destination is on another plane.\n");
          printf("%O\n",hlp);
          return;
      }
   }

   if ( check_success( act_skill, max_skill ) )
   {
      if(environment(oppo)->query_property("no_teleport") ||
          environment(TP)->query_property("no_teleport")) {
         write("A strange magical force seems to block the spell.\n");
         return;
      }
      write("You open a gate to "+oppo->query_name_true()+".\n");
      move_object(gate=clone_object("spells/no_combat/portal/portal_ob"),
                  environment(TP));
      gate->set_portal(oppo,60);
      write("You open a portal to "+oppo->query_name_true()+".\n");
   }
}
