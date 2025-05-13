
/* ################################################################
   #								  #
   #    		  Mage gate spell                         #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST 150

speed(lev)
{
    if(lev > 25) return 1;
    return 2;
}

level() {   return 22; }
help () {   return HDIRO+"gate/gate"; }
cost () {   return SPELL_COST; }

do_spell(arg,skill) {
object dest,gate;

  CHK_SKILL();
  CHK_GHOST();
  CHK_LIGHT();
  CHK_ATT();
  CHK_SP(SPELL_COST);

  if(!arg) {
    ME("Open a gate to whom ?\n");
    return 1;
  } 

  dest=find_living(arg);
  if(!dest) {
    ME("You are not able to find "+arg+".\n");
    return 1;
  }
  if(!dest->query_player()) {
    ME("You can only open a gate to a player.\n");
    return 1;
  }
  if(!TP->query_immortal() && dest->query_immortal()) {
    ME("You can not open a gate to a wizard.\n");
    return 1;
  }
  if(E(dest)->query_property("no_teleport") ||
     E(TP)->query_property("no_teleport")) {
    write("A strange magical force seems to block the spell.\n");
    return 1;
  }

  CHK_FAIL(SPELL_COST,"gate");
  ADDSP(-SPELL_COST);

  move_object(gate=clone_object("players/llort/guild/obj/gate"),E(dest));
  gate->set_gate(TP);
  OTHERS(({ TP }),TPN+" speaks some magic words.\n");
  ME("You open a gate to "+dest->query_name()+".\n");
  return 1;
}

query_name()
{
   return( "Gate" );
}

query_command()
{
   return( "cast 'gate' <target>" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'pgnw'" }) +
      ({ 0 })
   );
}
