
/* ################################################################
   #								  #
   #    		Mage Shield                               #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    30

level() { return 1; }
help () { return HDIRO+"shield/shield"; }
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

   CHK_SKILL();
   CHK_GHOST();
   CHK_LIGHT();
   CHK_ATT();
   CHK_SP(SPELL_COST);
 
   vic = 0;
   if( !arg )
      vic=TP;
   else
      vic=present(arg,environment(TP));

   if(!vic)
   {
      write("Never around when needed!\n");
      return 1;
   };

   CHK_FAIL(SPELL_COST, "shield");

   ADDSP( -1 * SPELL_COST );

   ME("Ok.\n");
   if(vic->shielded())
   {
      ME("Nothing seems to happen.\n");
   }
   else
   {
      YOU( vic, TPN+" surrounds you with a strong forcefield!\n");
      OTHERS( ({ vic, TP }),
              capitalize(vic->query_name())+
              " is surrounded by a strong forcefield!\n");
      sh=clone_object(SDIR+"shield_shad");
      sh->start_shadow(vic,  60 + TPL * 3 * (this_player()->query_wis()/3) );
   };
   return( 1 );
}

query_name()
{
   return( "Shield" );
}

query_command()
{
   return( "cast 'shield' [target]" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'riolwa'" }) +
      ({ 0 })
   );
}
