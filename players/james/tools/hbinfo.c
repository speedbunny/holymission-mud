object *ob,u;
int i;

id(str) { return str=="hbinfo" || str=="util" || str=="hbinfo util"; }
get() { return 1; }
short() { return "Hbinfo util"; }
long() { write(short()+".\nShows some internals of the world.\n" +
		       "Only gods will think it useful.\n" +
		       "Use with 'hbinfo'\n"); }

init() { add_action("hbinfo","hbinfo"); }

hbinfo() {
  if (environment(this_object())!=this_player()) {
     write("You must get it first, butthead.\n");
     return 1;
  }
  write("Active Heart_beat display.\n\n");
  ob=heart_beat_info();
  i=0;
  hbinfo2();
  return 1;
}

hbinfo2(str) {
int j;
  if (str=="q") return 1;
  for(j=i; j<(i+20); j++) {
    if ((sizeof(ob) > j) && ob[j])
    write(file_name(ob[j])+" ["+function_exists("heart_beat",ob[j])+"]");
    write("\n");
  }
  i += 20;
  if (i <= sizeof(ob)) {
    write("More (type 'q' to quit)\n");
    input_to("hbinfo2");
  }
}
