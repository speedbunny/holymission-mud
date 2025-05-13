
/* ################################################################
   #								  #
   #    		Mage Faerie Fire                          #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    30

level() { return 2; }
help () { return HDIRN+"faerie_fire/faerie_fire"; }
cost () { return SPELL_COST; }

speed(lev)
{
   if(lev > 21) return 0;
   return 1;
}

do_spell( arg, skill )
{
   object vic, sh;
   int    damage, i, lev; 
   string tpn;
   object enemy;

   CHK_SKILL();
   CHK_GHOST();
   CHK_LIGHT();
   CHK_ATT();
   CHK_SP(SPELL_COST);
   GET_ENEMY(arg, "Cast the faerie fire on whom ?\n");
   CHK_FAIL(SPELL_COST, "shield");

   ADDSP( -1 * SPELL_COST );

   ME("Ok.\n");
   if(enemy->shad_id("faerie_fire"))
   {
      ME("Nothing seems to happen.\n");
   }
   else
   {
      YOU( enemy, TPN+" surrounds you with a pink aura!\n");
      OTHERS( ({ enemy, TP }),
              capitalize(enemy->query_name())+
              " is surrounded by a pink aura!\n");
      sh=clone_object(SDIR+"faerie_fire_shad");
      sh->start_shadow(enemy, 600);
   };
   return( 1 );
}

query_name()
{
   return( "Faerie Fire" );
}

query_command()
{
   return( "cast 'faerie fire' <victim>" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'dowtpo fpto'" }) +
      ({ 0 })
   );
}
