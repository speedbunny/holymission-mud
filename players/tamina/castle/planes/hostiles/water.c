inherit "room/room";

#include "/players/tamina/defs.h"

object survivor;
int nodanger,damage,timer;
string envname,saymsg,wrtmsg;

void init() 
{
  ::init();
  if(nodanger) return;
  if(!present(survivor, TP)) call_out("drown_player", 1);
}

drown_player() 
{
  if(nodanger) return;

  if(!TP) return;

  if(!present(TP, TO)) return;

  if(present(survivor, TP)) return;

  if(TP->query_ghost()) return;

  if(TP->can_survive() == envname) return;

  say(TPN+" "+saymsg+"\n");
  write(wrtmsg+"\n");

  TP->hit_player(damage);

  if(TP) TP->show_hp();

  call_out("drown_player", timer);
}

query_env_name() 
{
  return envname;
}


query_danger() 
{
  return !nodanger;
}

