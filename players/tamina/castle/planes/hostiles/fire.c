#include "/players/tamina/defs.h"

inherit "room/room";

int nodanger,damage,timer;
string envname,saymsg,wrtmsg;
object survivor;

init() 
{
  ::init();
  if (nodanger) return;
  if (!present(survivor, TP)) 
    call_out("burn_player", 1);
}

burn_player() 
{
  if (nodanger) return;

  if (!TP) return;

  if (!present(TP, TO)) return;

  if (present(survivor,TP)) return;

  if(TP->query_ghost()) return;

  if(TP->can_survive()==envname) return;

  say(TPN+" "+saymsg+"\n");
  write(wrtmsg+"\n");

  TP->hit_player(damage, 15);

  if (TP) TP->show_hp();
  call_out("burn_player", timer);
}

query_env_name() 
{
  return envname;
}


query_danger() 
{
  return !nodanger;
}

