
/* ################################################################
   #								  #
   #    		  Mage Portal spell                       #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST 300

speed(lev)
{
    return 3;
}

level() {   return 29; }
help () {   return HDIRO+"portal/portal"; }
cost () {   return SPELL_COST; }

do_spell(arg,skill) {
object dest,gate;
string hlp;

  CHK_SKILL();
  CHK_GHOST();
  CHK_LIGHT();
  CHK_ATT();
  CHK_SP(SPELL_COST);
  if(!arg)
  {
    ME("Open a portal to whom ?\n"); 
    return 1;
  } 

  dest=find_living(arg);
  if(dest && !E(dest))
  {
      destruct(dest);
      dest=find_living(arg);
  }
  if(!dest || !E(dest)) {
    ME("You are not able to find "+arg+".\n");
    return 1;
  }

  if(!TP->query_immortal() && dest->query_immortal()) {
    ME("You can not open a portal to a wizard.\n");
    return 1;
  }
  if(E(TP)->plane_name()!=dest->plane_name())
  {
     ME("Destination on another plane.\n");
     return 1;
  }

  hlp=explode(file_name(E(dest)),"/");
// check for newwiz-area
  if(sizeof(hlp)>2 && hlp[0]=="players")
  {
    if(master_object()->get_wiz_level(hlp[1]) < 33)
    {
       ME("Destination on another plane.\n");
       return 1;
    }
  }
  CHK_FAIL(SPELL_COST,"portal");
  ADDSP(-SPELL_COST);

  if(E(dest)->query_property("no_teleport") ||
     E(TP)->query_property("no_teleport")) {
    write("A strange magical force seems to block the spell.\n");
    return 1;
  }

  move_object(gate=clone_object("players/llort/guild/obj/portal"),E(TP));
  gate->set_portal(dest,60);
  OTHERS(({ TP }),TPN+" speaks some magic words.\n");
  ME("You open a portal to "+dest->query_name()+".\n");
  return 1;
}

query_name()
{
   return( "Portal" );
}

query_command()
{
   return( "cast 'portal' <target>" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'irlwyq'" }) +
      ({ 0 })
   );
}
