#pragma strict_types
#define CP(x) capitalize(x)
#define TO(x,y) tell_object(x,y)
#define TP this_player()
#define TPQL TP->query_level()

int id(string str)
{
  return str == (string)"echo_wiz" || str == (string)"wizecho";
}


void init() {
  add_action("wiz_echo", "wize");
}

status get() {
  return 1;
}

status drop() {
  return 1;
}

status wiz_echo(string str) {
  object *u;
  int i;
  if(!str) return 0;
  if(TPQL < 33)
  {
    TO(TP,"Only Retds and above can echo on the wizline.\n");
    return 1;
  }
  str="[wiz] "+CP(str)+"\n";
  u=filter_array(users(), "wizline_filter", this_object());
  for(i=0;i<sizeof(u);i++) tell_object(u[i], str);
  return 1;
}

status wizline_filter(object ob) {
  return (status)ob->query_wizline();
}

string query_auto_load() {
  return "players/muzmuz/obj/burst/werg:";
}
