
/* ################################################################
   #								  #
   #    		Mage Fireshield                           #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    200

level() { return 11; }
help () { return HDIRO+"fireshield/fireshield"; }
cost () { return SPELL_COST; }

speed(lev)
{
   if(lev > 20) return 2;
   if(lev > 15) return 3;
   return 4;
}

do_spell( arg, skill )
{
   object sh;
   int    lev; 
   int    type;

   CHK_SKILL();
   CHK_GHOST();
   CHK_LIGHT();
   CHK_ATT();
   CHK_SP(SPELL_COST);

   if(!arg || (arg!="hot" && arg!="cold"))
   {
       write("You have to cast the fireshield hot or cold!\n");
       return 1;
   }
   if(arg == "cold") type=3;
   else type = 1;

   CHK_FAIL(SPELL_COST, "fireshield");

   ADDSP( -1 * SPELL_COST );

   ME("Ok.\n");
   if(TP->shad_id("fireshield"))
   {
      ME("Nothing seems to happen.\n");
   }
   else
   {
      ME("You start glowing "+(type==1 ? "red" : "white")+".\n");
      OTHERS( ({ TP }),
              capitalize(TP->query_name())+
              " is surrounded by a "+(type==1 ? "red" : "white")+" aura!\n");
      sh=clone_object(SDIR+"fireshield_shad");
      sh->start_shadow(TP, 30 + TPL * (this_player()->query_wis()), type);
   };
   return( 1 );
}

query_name()
{
   return( "Fireshield" );
}

query_command()
{
   return( "cast 'fireshield' hot|cold" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'tlwsaclsvb'" }) +
      ({ 0 })
   );
}
