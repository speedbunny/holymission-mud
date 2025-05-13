
/* ################################################################
   #								  #
   #    		Mage illusion                             #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    50

level() { return 1; }
help () { return HDIR+"illusion"; }
cost () { return SPELL_COST; }
speed(lev) { return 4; }

doit(arg,xx) {
int spnr;
  
  pl=xx;
  if(!arg) {
    ME("What does it look like ?\n");
    return 1;
  }
  
  spnr=MS->spellnr("illusion");
  CHK_LIGHT(); CHK_GHOST();
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));

  ME("Enter a short description of your illusion:\n>>");
  SOUL->start_illusion(arg,ILLU_TIME);
  
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
      sh=clone_object(ODIR+"shield_shad");
      sh->start(vic, TPL * 5 * 30);
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
