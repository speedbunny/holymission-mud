id(str) { return "snon"==str; }
short() { return "a snon"; }
long() { write(short()+".\n"); }
init() { add_action("sn_on","sn_on"); }
sn_on(str) {
  snoop(find_player(str));
  write("Snooping ...");
  return 1;
}
