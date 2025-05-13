inherit "room/room";
#include "/players/meecham/def.h"
object m1,m2;
reset(arg)
{
  CLONE("driver","slaver");
  if(!m1) { m1=CO(MON+"slave"); MO(m1,TO); }
  if(!m2) { m2=CO(MON+"slave"); MO(m2,TO); }
  if(!arg)
  {
    set_light(1);
    short_desc="Bridge";
    long_desc=
      "****************************************** \n\
*                                        * \n\
* 'WARE THE IDEAS OF MEECHAM (MUHAHAHA)  * \n\
*                                        * \n\
****************************************** \n\n\
You stand just north of the beginning of the bridge.  The planks sway\n\
dangerously beneath your feet making you unsure of fighting here.  There\n\
is a warning sign here for new adventurers to Coldrik's realm.  You can\n\
continue north or south.\n";
    items=({
      "sign","                                    WARNING\n\n\
     Some of the monsters in Coldrik's realm have the power to follow an\n\
no matter where they run to.  They have been found wandering through Holy\n\
Mission, in guild rooms, and many other places, no one has yet to find a place\n\
where they will not follow.  Meecham has waved his mighty staff over Coldrik's\n\
Realm labeling each of these monsters as a deadly 'blink' (name copyright:\n\
Nic@Realmsmud) so always look at a monster before fighting it and know that\n\
once you attack, you will be fighting to the death!",
    });
    dest_dir=({
      PM+"colrealm/bridge3","north",
      PM+"colrealm/bridge","south",
    });
  }
}
 
 
