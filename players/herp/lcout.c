/* mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

/* List call out */

object *ob,u;
int i;

catch_msg(object *ob) {

    write(ob);

}

id(str) { return str=="lcout" || str=="util" || str=="lcout util"; }
get() { return 1; }
short() { return "Lcout util"; }
long() { write(short()+".\nShows some internals of the world.\n" +
		       "Only gods will think it useful.\n" +
		       "Use with 'lcout'\n"); }
init() { add_action("lcout","lcout"); }

lcout() {
  if (environment(this_object())!=this_player()) {
     write("You must get it first, butthead.\n");
     return 1;
  }
  write("Call out info display.\n\n");
  ob=call_out_info();
  i=0;
  lcout2();
  return 1;
}

lcout2(str) {

  if (str=="q") return 1;
  ob=call_out_info();
  while(i<sizeof(ob)) {
    u=ob[i];
    if (u) {
    write(u[1]);
    write(" ");
    write(u[0]);
    write(" ");
    write(u[2]);
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
  write(sizeof(ob)+" call_out(s) in total.\n");
  return 1;
}
