
/* ################################################################
   #								  #
   #    		Mage Infravision                          #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    40

level() { return 10; }
help () { return HDIRO+"infravision/infravision"; }
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
   CHK_FAIL(SPELL_COST, "infravision");
   ADDSP( -1 * SPELL_COST );
   ME("Ok.\n");
   YOU( target, "Your eyes glow blue.\n");
   OTHERS( ({ target, TP }),
           capitalize(target->query_name())+
           "'s eyes glow blue.\n");
   sh=clone_object(SDIR+"infravision_shad");
   sh->start_shadow(target, TPL * 2 * 60);

   return( 1 );
}

query_name()
{
   return( "Infravision" );
}

query_command()
{
   return( "cast 'infravision' [target]" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'jhtemojqjkh'" }) +
      ({ 0 })
   );
}
