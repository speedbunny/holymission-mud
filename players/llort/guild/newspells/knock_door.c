
/* ################################################################
   #								  #
   #    		Mage knock door                           #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#define SPELL_COST 40

speed(lev)
{  return 2; }

level()
{   return 5; }

help ()
{   return HDIRO+"knock_door/knock_door"; }

cost ()
{   return SPELL_COST; }

do_spell(str,skill) {
object door; 
int i,num_doors,spnr;
string dest;

  CHK_SKILL();
  CHK_GHOST();
  CHK_LIGHT();
  CHK_ATT();
  CHK_SP(SPELL_COST);

  if(!str) {
      ME("Knocking on Heavens door ??\n");
      return;
  }

  if (!(door=present(str,E(TP))) || !door->number_of_doors()) {
      ME("There is no such door here!\n");
      return;
  }

  CHK_FAIL(SPELL_COST,"knock door");
  ADDSP(-SPELL_COST);

  if (!door->query_locked()) {
    ME("Your spell fizzles on the unlocked door.\n");
    return 1;
  }

  ME("The lock glows bright for a moment.\n");
  OTHERS(({ TP }),"The lock "+str+" glows bright for a moment.\n");

  door->set_locked(0);
  door->query_partner_door()->set_locked(0);

  return 1;
}

query_name()
{
   return( "Knock Door" );
}

query_command()
{
   return( "cast 'knock door' door|<direction>" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'dowjd uwwe'" }) +
      ({ 0 })
   );
}
