#include "/players/waldo/defs.h"
inherit "room/room";

reset(arg)
{
  if (!arg)
  {
    set_light(1);
    short_desc="Waldo's Guild Room.\n";
    long_desc=
"This is the guild room of Waldo. Here he has installed exits\n"
"to all the guilds.\nHave fun.\n";

    dest_dir=({
      "/room/adv_guild","adventurer",
      "/players/llort/guild/room","MAGE",
      "/players/sourcer/guild/room","druid",
      "/players/patience/guild/room","ninja",
      "/players/mangla/guild/room","jedi",
      "/players/tatsuo/guild/room","barbarian",
      "/players/whisky/guild/room","monk",
      "/players/kryll/guild/room","thief",
      "/players/portil/guild/room","fighter",
      "/players/nylakoorub/guild/room","vagabond",
      "/players/haplo/guild/room","samurai",
    });
    }
  }
