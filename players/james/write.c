id(str) { return str=="staff"; }
short() { return "staff"; }
long() { write("staff\n"); }
get() { return 1; }

init() {
  add_action("slocal","slocal");
  add_action("sremote","sremote");
  add_action("stell","stell");
  add_action("plocal","plocal");
  add_action("premote","premote");
  add_action("ptell","ptell");
}

slocal(string str) {
  string str2;
  str2= (string) "players/james/script"->bigword(str);
  tell_room(environment(this_player()),str2);
  return 1;
}

plocal(string str) {
  string str2;

  str2= (string) "players/james/puffy"->bigword(str);
  tell_room(environment(this_player()),str2);
  return 1;
}

sremote(string str) {
  string str2;
  str2 = (string) "players/james/script"->bigword(str);
  shout(str2);
  return 1;
}

premote(string str) {
  string str2;

  str2 = (string) "players/james/puffy"->bigword(str);
  shout(str2);
  return 1;
}

stell(string arg) {
  string str;
  string str2;
  string who;

  sscanf(arg,"%s %s",who,str);
  str2 = (string) "players/james/script"->bigword(str);
  tell_object(find_player(who),str2);
  return 1;
}

ptell(string arg) {
  string str;
  string str2;
  string who;

  sscanf(arg,"%s %s",who,str);
  str2 = (string) "players/james/puffy"->bigword(str);
  tell_object(find_player(who),str2);
  return 1;
}

