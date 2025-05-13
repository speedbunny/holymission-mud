
/* ################################################################
   #								  #
   #    		Mage Haste                                #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    100

level() { return 17; }
help () { return HDIRO+"haste/haste"; }
cost () { return SPELL_COST; }

speed(lev)
{
   if(lev > 25) return 2;
   return 3;
}

do_spell( arg, skill )
{
   object target, sh;
   int    damage, i, lev; 
   string tpn;

   CHK_SKILL();
   CHK_GHOST();
   CHK_LIGHT();
   CHK_ATT();
   CHK_SP(SPELL_COST);
   GET_TARGET(arg,"Haste whom?\n");
 
   CHK_FAIL(SPELL_COST, "haste");
   ADDSP( -1 * SPELL_COST );

   ME("Ok.\n");
   if(target->shad_id("haste"))
   {
      ME("Nothing seems to happen.\n");
   }
   else
   {
      YOU( target, "You start moving faster!\n");
      OTHERS( ({ target, TP }),
              capitalize(target->query_name())+
              " starts moving faster.\n");
      sh=clone_object(SDIR+"haste_shad");
      sh->start_shadow(target, 60 + 6*TPL);
   };
   return( 1 );
}

query_name()
{
   return( "Haste" );
}

query_command()
{
   return( "cast 'haste' [target]" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'osfw'" }) +
      ({ 0 })
   );
}
