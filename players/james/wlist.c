short() { return "kludge"; }
long() {write("a kludge\n"); }
id(str) { return str=="kludge"; }
get() { return 1; }

init() {
  add_action("null","null");
  add_action("start_beat","startbeat");
  add_action("stop_beat","stopbeat");
}

reset() {
  set_heart_beat(0);
}

null() { return 1; }

start_beat() { set_heart_beat(1); return 1; }

stop_beat() { set_heart_beat(0); return 1; }

heart_beat() {
  command("null",find_player("james"));
  command("null",find_player("james"));
  command("null",find_player("james"));
  command("null",find_player("james"));
  command("null",find_player("james"));
}
