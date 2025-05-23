/* SPECIAL.C - Programmed by Ethereal Cashimor */
/* 150793: Started programming */

inherit "room/room";

string envname,special_dir,saymsg,wrtmsg,survivor;

query_env_name() {
  return envname;
}

reset(arg) {
  ::reset(arg);
  if(!special_dir) special_dir="";
}

move(str) {
  if(does_allow()) return ::move(str);
  write(wrtmsg+"\n");
  say(this_player()->query_name()+" "+saymsg+"\n");
  return 1;
}

static does_allow() {
string d1,d2;

  if(sscanf(special_dir,"%s#"+query_verb()+"#%s",d1,d2)==2) {
    return 1;
  }
  if(present(survivor,this_player())) return 1;
  if(this_player()->query_ghost()) return 1;
  if(this_player()->can_survive()==envname) return 1;
  return 0;
}
                                                                                    
