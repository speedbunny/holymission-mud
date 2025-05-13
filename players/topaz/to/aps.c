inherit "/obj/treasure";

#include "/players/topaz/defs.h"

drop() {
  write("The All Player Shouter crumbles as it leaves your hands.\n");
  destruct(this_object());
  return 1;
}

reset(arg) {
  ::reset();

  set_id("shouter");
  set_name("All Player Shouter");
  set_alt_name("player shouter");
  set_alias("shouter");
  set_short("An All Player Shouter");
  set_long("This is your All Player Shouter.\n" +
           "With it you can shout messages that put each player's\n" +
           "name in the message.  Each player will see his or her\n" +
           "name in your message.\n" +
           "To use it type:\n" +
           "               allshout <optional premessage> NAME <opt. postmes.>\n" +
           "For example:\n" +
           "            allshout Boy, NAME you are ugly!!!\n" +
           "Have fun with this, but don't abuse it, please.\n" +
           "\n  Topaz\n");
  set_weight(0);
  set_value(0);
}

init() {
  ::init();

    add_action("_allshout","allshout");
}

_allshout(str) {
object pre,post;
  if (!(TP->query_immortal() || TP->query_testplayer())) {
    write("How did you get this?!?\n" +
          "You shouldn't have this!\n" +
          "The All Player Shouter explodes in your face!\n");
    TP->restore_hit_points(-10);
    destruct(this_object());
    return 1;
  }
  if(!str) {
    write("What do you want to allshout?\n");
    return 1;
  }

}
