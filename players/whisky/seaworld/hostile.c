inherit "room/room";

int nodanger,damage,timer;
string survivor,envname,saymsg,wrtmsg;

init() {
  ::init();
  if(nodanger) return;
  if(!present(survivor,this_player())) call_out("drown_player",1);
}

drown_player() {
  if(nodanger) return;
  if(!this_player()) return;
  if(!present(this_player(),this_object())) return;
  if(present(survivor,this_player())) return;
  if(this_player()->query_ghost()) return;
  if(this_player()->can_survive()==envname) return;
  say(this_player()->query_name()+" "+saymsg+"\n");
  write(wrtmsg+"\n");
  this_player()->hit_player(damage,3);
  if(this_player()) this_player()->show_hp();
  call_out("drown_player",timer);
}

query_env_name() {
  return envname;
}


query_danger() {
  return !nodanger;
}

