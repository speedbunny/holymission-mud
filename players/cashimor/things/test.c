inherit "obj/thing";
#include "/players/cashimor/include/secretxp.h"

int gd;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("test");
    set_short("A test object");
    set_long("This is a test object.\n");
    set_weight(1);
    set_value(10);
  }
}

init() {
  ::init();
  add_action("test_it","test");
  add_action("secret_it","secret");
}

test_it() {
  write(lw("This is a test of the line-wrap include file. I hope it "
         + "works. I'm going to make three lines of text in this ed-"
         + "file, this will probably exceed the needed 80 lines..."));
  return 1;
}
secret_it() {
  write("Executing secret_xp!\n");
  secret_xp();
  write("Done!\n");
  return 1;
}

