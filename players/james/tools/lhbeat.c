/* mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */
/* hacked apart by James */

/* List Heart Beat  (active heartbeats) */

object *ob,u;
int i;

id(str) { return str=="lhbeat" || str=="util" || str=="lhbeat util"; }
get() { return 1; }
short() { return "Lhbeat util"; }
long() { write(short()+".\nShows some internals of the world.\n" +
		       "Only gods will think it useful.\n" +
		       "Use with 'lhbeat'\n"); }
init() { add_action("lhbeat","lhbeat"); }

lhbeat() {
  if (environment(this_object())!=this_player()) {
     write("You must get it first, butthead.\n");
     return 1;
  }
  write("Heart beat info display.\n\n");
  ob=heart_beat_info();
  i=0;
  lcout2();
  return 1;
}

lcout2(str) {

  if (str=="q") return 1;
  while(i<sizeof(ob)) {
    u=ob[i];
    if (u) {
      write(file_name(u));
    } else {
    write("N/A ?");
    }
    write("\n");
    i++;
    if (i%18==0) {
      write("<q> to quit, <enter> for more.");
      input_to("lcout2");
      return 1;
    }
  }
  write(sizeof(ob)+" heart_beat(s) in total.\n");
  return 1;
}
