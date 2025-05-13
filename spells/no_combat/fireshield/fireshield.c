
/* ################################################################
   #								  #
   #    		Mage Fireshield                           #
   #                                          		          #
   ###############################################(C) Llort######## */

inherit "/spells/spell";
#include "/spells/spell.h"

speed(lev)
{
   if(lev > 20) return 2;
   if(lev > 15) return 3;
   return 4;
}

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "fireshield" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'fireshield' hot | cold" );
   set_save_vs( NO_SAVE );
   set_guild_allowed(5,14);
   set_cost( 200 );
   set_player_help(
"This spell creates a shield of fire/coldness around you, and makes every\n"+
"physical attack against you do double damage to the attacker. Additionally it\n"+
"provides some protection vs. heat/cold-based attacks, and make you susceptible\n"+
"to the oposite element.");
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object oppo, sh;
   string oppo_name;
   int    type;

   if(!arg || (arg!="hot" && arg!="cold"))
   {
       write("You have to cast the fireshield hot or cold!\n");
       return;
   }
   if(arg == "cold") type=3;
   else type = 1;

   oppo = TP;
   oppo_name = apply( call, oppo, "query_name" );

   if ( check_success( act_skill, max_skill ) )
   {
       write("Ok.\n");
       if(TP->shad_id("fireshield"))
       {
          write("Nothing seems to happen.\n");
       }
       else
       {
          write("You start glowing "+(type==1 ? "red" : "white")+".\n");
          say(TPNT+" is surrounded by a "+(type==1 ? "red" : "white")+
              " aura!\n",0,TP,"");
          sh=clone_object("/spells/no_combat/fireshield/fireshield_shad");
          sh->start_shadow(TP, 30 + TPL * (TP->query_wis()), type);
       };
   }
}
