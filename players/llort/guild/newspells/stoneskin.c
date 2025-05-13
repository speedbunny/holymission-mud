
/* ################################################################
   #								  #
   #    		Mage Stoneskin                            #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    150

level() { return 10; }
help () { return HDIRO+"stoneskin/stoneskin"; }
cost () { return SPELL_COST; }

speed(lev)
{
   if(lev > 21) return 2;
   return 3;
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

   CHK_FAIL(SPELL_COST, "stoneskin");

   ADDSP( -1 * SPELL_COST );

   ME("Ok.\n");
   if(vic->stoneskin())
   {
      ME("Nothing seems to happen.\n");
   }
   else
   {
      YOU( vic, TPN+" touchs you, and your skin seems to harden!\n");
      OTHERS( ({ vic, TP }),
              capitalize(vic->query_name())+
              " is going pale!\n");
      sh=clone_object(SDIR+"stoneskin_shad");
      sh->start_shadow(vic,  300 + TPL * 30);
   };
   return( 1 );
}

query_name()
{
   return( "Stoneskin" );
}

query_command()
{
   return( "cast 'stoneskin' [self]" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'yaczlyrjl'" }) +
      ({ 0 })
   );
}
