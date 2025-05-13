/* ################################################################
   #								  #
   #    		Mage light spell                          #
   #                                          		          #
   ###############################################(C) Llort######## */
/* used for druids too */

inherit "/spells/spell";
#include "/spells/spell.h"

void reset( int tick )
{
   ::reset( tick );

   if ( tick ) return;

   set_name( "light" );
   set_kind( NO_COMBAT );
   set_syntax( "cast 'light'" );
   set_save_vs( NO_SAVE );
   set_guild_allowed( 5, 1 );
   set_cost( 20 );
   set_player_help(
"This simple spell will create a weightless globe of light, which will\n"+
"illuminate all but the darkest areas around you.\n"+
"To get rid of the globe just drop it."
   );
}

speed(lev)
{
   if(lev > 20) return -1;
   if(lev > 10) return 0;
   return 1;
}

void release_spell( string arg, int act_skill, int max_skill )
{
   object ob;

   if ( check_success( act_skill, max_skill ) )
   {
      if(present("mage_light_globe",TP))
      {
	 write("There is already such a spell active.\n");
	 return;
      }

      ob=clone_object("/spells/no_combat/light/globe");
      ob->set_name("mage_light_globe");
      ob->set_alias("globe");
      ob->set_short("globe of light");
      ob->set_long("A Globe emitting warm, dim light.\n");
      ob->set_weight(0);
      ob->set_llevel(1);
      if(transfer(ob,TP))
      {
         write("Something has gone wrong!\n");
         destruct(ob);
         return;
      }
      ob->set_time(600);
      say("A globe of light appears in "+TPNT+"'s hand.\n",0,TP,
          "The area lighten up a bit.\n");
      write("A globe of light appears in your hand.\n");
      if(ob->light(1)==1) {
         say("You can see again.\n");
         write("You can see again.\n");
      }
   }
}
