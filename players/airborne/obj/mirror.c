/* Mirror modified by Ethereal Cashimor, 270493
   'show' build in, 280493 */

inherit "obj/thing";
#include "/obj/lw.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("mirror");
    set_value(100);
    set_short("A silver mirror");
    set_long("In the mirror you see:\n");
  }
}

long(str) {
  ::long(str);
  command("look at "+this_player()->query_real_name(),this_player());
  write("The person in the mirror looks very frightening.\n");
}

init() {
  ::init();
  add_action("show_it","show");
}

show_it(str) {
string name;
object who;

  if(sscanf(str,"mirror to %s",name)!=1) {
    notify_fail("Show mirror to who?\n");
    return 0;
  }
  if(!who=present(name,environment(this_player()))) {
    notify_fail("That person isn't here.\n");
    return 0;
  }
  if(!living(who)) {
    write("The "+name+" doesn't look interested.\n");
    say(lw(this_player()->query_name()+" shows a mirror to "
      + lower_case(who->short())+" and looks silly doing so.\n"));
    return 1;
  }
  write("You show "+who->query_name()+" your mirror.\n");
  tell_object(who,lw(this_player()->query_name()+" shows you "
            + this_player()->query_possessive()
            + " mirror. You see someone in it:\n"));
  command("look at "+who->query_real_name(),who);
  tell_object(who,"The person in the mirror looks terrifying!\n");
  say(this_player()->query_name()+" shows a mirror to "
    + who->query_name()+".\n",who);
  return 1;
}






