
/* ################################################################
   #								  #
   #    		Mage True Sight                           #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    80

level() { return 18; }
help () { return HDIRO+"true_sight/true_sight"; }
cost () { return SPELL_COST; }

speed(lev)
{
   return 2;
}

do_spell( arg, skill )
{
   object target, sh;
   int    i, lev; 

   CHK_SKILL();
   CHK_GHOST();
   if(arg)
   {
      CHK_LIGHT();
   }
   CHK_ATT();
   CHK_SP(SPELL_COST);
   GET_TARGET(arg, "Never around when needed!\n");
   CHK_FAIL(SPELL_COST, "true sight");
   ADDSP( -1 * SPELL_COST );
   ME("Ok.\n");
   YOU( target, "Your eyes glow silver.\n");
   OTHERS( ({ target, TP }),
           capitalize(target->query_name())+
           "'s eyes glow silver.\n");
   sh=clone_object(SDIR+"true_sight_shad");
   sh->start_shadow(target, TPL * 1 * (this_player()->query_wis()));

   return( 1 );
}

query_name()
{
   return( "True sight" );
}

query_command()
{
   return( "cast 'true sight' [target]" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'uope qzdwu'" }) +
      ({ 0 })
   );
}
