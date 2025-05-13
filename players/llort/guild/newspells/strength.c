
/* ################################################################
   #								  #
   #    		  Mage stength                            #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    60

level() { return 7; }
help () { return HDIRO+"strength/strength"; }
cost () { return SPELL_COST; }
speed(lev) { return 2; }

do_spell( arg, skill )
{
    int spnr;
    object sh,target;

    CHK_SKILL();
    CHK_GHOST();
    CHK_LIGHT();
    CHK_ATT();
    CHK_SP(SPELL_COST);

    if( !arg ) { target=TP; }
    else { target=present(arg,environment(TP)); };

    if(!target)
    {
        write("Never around when needed!\n");
        return 1;
    };

    CHK_FAIL(SPELL_COST, "shield");
    ADDSP( -1 * SPELL_COST );

    ME("Ok.\n");
    if(target->strengthed())
    {    ME("Nothing seems to happen.\n"); }
    else
    {
        YOU( target, "You feel stronger now!\n");
        OTHERS( ({ target, TP }),
            capitalize(target->query_name())+ " looks stronger.\n");
        sh=clone_object(SDIR+"strength_shad");
        sh->start_shadow(target, TPL * 30);
    };

    return 1;
}

query_name()
{
   return( "Strength" );
}

query_command()
{
   return( "cast 'strength' [target]" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'tpbwmhpr'" }) +
      ({ 0 })
   );
}
