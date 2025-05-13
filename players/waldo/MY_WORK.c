#include "/players/waldo/defs.h"
#define CNAME "Waldo"

string shield_stat;
inherit "room/room";

reset (arg)
{
  if (!arg)
  {
    set_light(1);
    short_desc=CNAME+"'s workroom",

    long_desc=
       "This is Waldo's workroom. From the many bits and pieces\n"+
       "he has lying around ... you assume that he is trying to\n"+
       "build something. You cannot tell what it is, but it appears\n"+
       "to be about 8 feet tall.\n";

    dest_dir=({
      "/players/waldo/guildroom","GUILDS",
       "/room/post","Post",
       "/room/church","church",
       "/room/statroom","stat",
       "/room/adv_guild","advent",
        "/players/llort/guild/room","mage_g",
        "/players/waldo/area/room/l11","CAVE",
              });

    items=({
           "air","It's very thin up here",
           "floor","The floor is dirty",
            });

    property = ({
      "no_sneak","no_steal","no_backstab","no_teleport",
                 });

    smell = "This place is smells like an open field on the\n"+
            "first day of spring.\n";

    shield_stat="on"; /* Set shield on as default */
    }
  }

init()
{
    ::init();
    if (TPRN=="waldo")
    {
      add_action("_shield","shield");
      add_action("_expel","byebye");
      }

    if (shield_stat=="on" && TPRN!="waldo")
    {
      TELL(FL("waldo"),"WORKROOM> "+CAP(TPRN)+" tried to enter yer workroom.\n");
      TELL(FL("waldo"),"WORKROOM> "+CAP(TPRN)+" has been sent to the church.\n");
      TELL(TP,"You have been denied access.\n");
      transfer(TP,"/room/church");
      }
   if (FL("waldo") && TPRN!="waldo" && shield_stat=="off")
    {
      TELL(FL("waldo"),"WORKROOM> "+CAP(TPRN)+" has entered your workroom.\n");
      }
  }

_shield(str) {
    if (str == "on") {
      ME("Shield activated.\n");
     shield_stat="on";
	return 1;
    }
    if (str == "off") {
      ME("Shield now de-activated.\n");
     shield_stat="off";
	return 1;
    }
   if (!str && shield_stat=="off") {
	write("shield is off\n");
	return 1;
    }
   if (!str && shield_stat=="on") {
	write("shield is on\n");
	return 1;
    }
}

_expel(str)
{
  if (!str)
  {
    ME("Expel who?\n");
    return 1;
    }
  if (!present(str,TO) )
  {
    ME("They are not here\n");
    return 1;
    }
  ME("You expel "+CAP(str)+" from here.\n");
  TELL(FL(str),"Waldo expels you from his workroom.\n");
  TELL(FL(str),"You are moved to the church.\n");
  transfer(FL(str),"room/church");
  return 1;
  }
