#include "/players/waldo/defs.h"
#define CNAME "Waldo"

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
       "/players/waldo/here","M_CONF",
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

    }
  }

init()
{
    ::init();
    }
