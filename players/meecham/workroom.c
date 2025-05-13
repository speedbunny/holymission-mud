inherit "room/room";
#include "/players/meecham/def.h"
reset(arg) {
  if(!present("wheel",TO)) MO(CO(PM+"items/wheel"),TO);
    if(!arg) {
     object o1;
        set_light(1);
    if(!o1)
    {
      o1=CO(PM+"monsters/gorgie.c");
      MO(o1,TO);
    }
        short_desc="Meecham" + "' workroom",
        long_desc=
      "This is Meecham's workroom.\n"+
	    "It looks empty ...\n";
    property = ({ "no_teleport" });
        dest_dir=({
            "players/meecham/newbie/n14","down",
            "players/colossus/private/guildroom","gr",
            "players/meecham/workroom2","north",
            "players/meecham/nowimpy","nowimpy",
            "players/colossus/workroom","col",
            "room/post", "post",
	    "room/church", "church",
                 });
    }
}
init()
{
  ::init();
/*
  if(TPR !="meecham" && TPR !="meech" && TPR !="kitty" && !TP->query_npc())
    TP->move_player("church#/room/church");
*/
}
