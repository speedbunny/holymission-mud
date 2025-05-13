id(str) { return str=="cmd"; }
short() { return "a cmd"; }
long() { write(short()+".\n"); }
init() { add_action("doit","doit"); }
get() { return 1; }
doit() {
  command("fart",this_player());
  write("Done it.");
  return 1;
}
