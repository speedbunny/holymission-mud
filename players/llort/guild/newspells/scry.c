
/* ################################################################
   #								  #
   #    		Mage Scry spell                           #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST 100

speed(lev)
{
    if(lev > 25) return 0;
    if(lev > 20) return 1;
    if(lev > 15) return 2;
    return 3;
}

level() {   return 10; }
help () {   return HDIRO+"scry/scry"; }
cost () {   return SPELL_COST; }

do_spell(arg,skill) {
object target,sh;

   CHK_SKILL();
   CHK_GHOST();
   CHK_LIGHT();
   CHK_ATT();
   CHK_SP(SPELL_COST);
   GET_TARGET(arg, "Never around when needed!\n");
   CHK_FAIL(SPELL_COST,"scry");
   ADDSP( -1 * SPELL_COST );
   ME("Ok.\n");
   YOU( target, "Your eyes glow green.\n");
   OTHERS( ({ target, TP }),
           capitalize(target->query_name())+
           "'s eyes glow green.\n");
   sh=clone_object(SDIR+"scry_shad");
   sh->start_shadow(target, TPL * 30);

   return( 1 );
}

query_name()
{
   return( "Scry" );
}

query_command()
{
   return( "cast 'scry' [target]" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'peal'" }) +
      ({ 0 })
   );
}
