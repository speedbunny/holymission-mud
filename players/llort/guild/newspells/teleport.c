
/* ################################################################
   #								  #
   #    		Mage teleport                             #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"
#define SPELL_COST 60

speed(lev)
{
    if (lev < 20) return 2;
    if (lev < 25) return 1;
    return 0;
}

level()
{   return 13; }

help ()
{   return HDIRN+"teleport/teleport";}

cost ()
{   return SPELL_COST; }

do_spell(str,skill) {
mapping mem;
string dest;
object destr;
int cost;

  CHK_SKILL();
  CHK_GHOST();
  CHK_LIGHT();
  CHK_ATT();

  if(!str) {
      ME("To what memorized site would you like to teleport to ??\n");
      return;
  };
  if(!(mem=TP->queryenv("MEMORIZE"))) {
      ME("You have nothing memorized at all!\n");
      return;
  };
  if(!(dest=mem[str])) {
      ME("You didn't memorize this site ("+str+") !\n");
      return;
  };
  if(catch(call_other(dest,"???",0))) {
      ME("It seems you are unable to reach that place at the moment.\n");
      return;
  };
  destr = find_object(dest);
  cost = SPELL_COST - destr->recalc_power_level() -
         E(TP)->recalc_power_level();
  if (cost < 10) cost = 10;
  CHK_SP(cost);

  if (E(TP)->query_property("no_teleport") ||
      destr->query_property("no_teleport"))
  {
     ME("Ancient magic bars your way!\n");
     return;
  };

  CHK_FAIL(cost,"teleport");
  ADDSP(-cost);

  TP->move_player("disappears in a puff of smoke", destr, 1,
		  "arrives out of thin air");
  return 1;
}

query_name()
{
   return( "Teleport" );
}

query_command()
{
   return( "cast 'teleport' <destination>" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'pwgwcyep'" }) +
      ({ 0 })
   );
}
