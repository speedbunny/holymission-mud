inherit "obj/thing";

#define TR(x) tell_room(environment(), (string)x)
#define USE_PROCESS_STRINGS

string what;

reset(int arg) {
  if (arg) 
    return;
  set_name("chalk marks");
  set_alias("marks");
  set_weight(1);
  set_can_get(0);
  set_long("@@set_what@@");
  call_out("age", 60);
}

string set_what(string str) {
  if (str) 
    what = str;
  return what;
}

void age() {
  TR("The pentagram slowly fades from sight.\n");
  destruct(this_object());
  return;
}
