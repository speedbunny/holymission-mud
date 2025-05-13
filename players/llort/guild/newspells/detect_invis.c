
/* ################################################################
   #								  #
   #    		Mage Detect Invisibility                  #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    30

level() { return 3; }
help () { return HDIRO+"detect_invis/detect_invis"; }
cost () { return SPELL_COST; }

speed(lev)
{
   return 1;
}

do_spell( arg, skill )
{
   object target, sh;
   int    i, lev; 

   CHK_SKILL();
   CHK_GHOST();
   CHK_LIGHT();
   CHK_ATT();
   CHK_SP(SPELL_COST);
   GET_TARGET(arg, "Never around when needed!\n");
   CHK_FAIL(SPELL_COST, "detect invisibility");
   ADDSP( -1 * SPELL_COST );
   ME("Ok.\n");
   YOU( target, "Your eyes glow yellow.\n");
   OTHERS( ({ target, TP }),
           capitalize(target->query_name())+
           "'s eyes glow yellow.\n");
   sh=clone_object(SDIR+"detect_invis_shad");
   sh->start_shadow(target, 60 + TPL * 2 * (this_player()->query_wis()));

   return( 1 );
}

query_name()
{
   return( "Detect invisibility" );
}

query_command()
{
   return( "cast 'detect invisibility' [target]" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'ruzudz pwspxpmxoxzq'" }) +
      ({ 0 })
   );
}
