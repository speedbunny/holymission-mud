
/* ################################################################
   #								  #
   #    		Mage light spell                          #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    20

level() { return 1; }
help () { return HDIRO+"light/light"; }
cost () { return SPELL_COST; }

speed(lev)
{
   if(lev > 20) return -1;
   if(lev > 10) return 0;
   return 1;
}

do_spell( arg, skill )
{
   object ob;

   CHK_SKILL();
   CHK_GHOST();
   CHK_ATT();
   CHK_SP(SPELL_COST);
 
   if(present("mage_light_globe",TP))
   {
      write("There is already such a spell active.\n");
      return 1;
   }

   CHK_FAIL(SPELL_COST, "light");

   ADDSP( -1 * SPELL_COST );

   ob=clone_object("/players/llort/guild/obj/globe");
   ob->set_name("mage_light_globe");
   ob->set_alias("globe");
   ob->set_short("globe of light");
   ob->set_long("A Globe emitting warm, dim light.\n");
   ob->set_weight(0);
   ob->set_llevel(1);
   move_object(ob,TP);
   ob->set_time(600);
   if(ob->light(1)==1) {
      SAY("You can see again.\n");
   }

   OTHERS(({ TP }),"A globe of light appears in "+TPN+"'s hand.\n");
   ME("A globe of light appears in your hand.\n");

   return( 1 );
}

query_name()
{
   return( "Light" );
}

query_command()
{
   return( "cast 'light'" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'tyrah'" }) +
      ({ 0 })
   );
}

