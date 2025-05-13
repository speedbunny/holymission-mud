
/* ################################################################
   #								  #
   #    		Mage Invisibility                         #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    40

level() { return 4; }
help () { return HDIRO+"invisibility/invisibility"; }
cost () { return SPELL_COST; }

speed(lev)
{
   if(lev > 25) return -1;
   return 0;
}

do_spell( arg, skill )
{
   object target, sh;

   CHK_SKILL();
   CHK_GHOST();
   CHK_LIGHT();
   CHK_ATT();
   CHK_SP(SPELL_COST);
   GET_TARGET(arg,"Never around when needed!\n");

   CHK_FAIL(SPELL_COST, "invisibility");

   ADDSP( -1 * SPELL_COST );

   ME("Ok.\n");
   if(target->query_invis())
   {
      ME("Nothing seems to happen.\n");
   }
   else
   {
      YOU( target, "You vanish!\n");
      OTHERS( ({ target, TP }),
              capitalize(target->query_name())+
              " fades out of sight!\n");
      sh=clone_object(SDIR+"invis_shad");
      sh->start_shadow(target, 600);
   };
   return( 1 );
}

query_name()
{
   return( "Invisibility" );
}

query_command()
{
   return( "cast 'invisibility' [target]" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'pndpspapxprq'" }) +
      ({ 0 })
   );
}
