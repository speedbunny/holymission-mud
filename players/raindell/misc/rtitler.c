inherit "obj/thing";

#include "/players/redsexy/defs.h"
#include "/players/redsexy/dimensions/defs.h"
#include "/players/raindell/titles"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("titler");
  set_alias("titler");
  set_short("Redsexy's magic Titler");
  set_long("This titler gives Redsexy random titles when she logs on");
}

init() {
   title_set();
   add_action("_swap", "swap");
   add_action("_drunk", "drunk");
   add_action("_code", "code");

  ::init();

}

_swap(arg) {
	      title_set();
	      return 1;
}

title_set() {
object x;
int q1;
   q1 = random(TITLE_SIZE);
   x=environment(this_object());
        if(!x) return;
        x->set_title(title_list[q1][1]);
        x->set_pretitle(title_list[q1][0]);
        write("You change your title to:" + title_list[q1][0] + " " + CAP(NAME) + " " + title_list[q1][1] + "\n");
        return 1;
        }

_drunk(arg) {
object x;
   x=environment(this_object());
        if(!x) return;
        x->set_title("Has Been Drinking - approach with caution");
        x->set_pretitle("Drunk");
        write("You change your title to let people know you are drunk.\n");
        return 1;
        }

_code() {
object x;
   x=environment(this_object());
        if(!x) return;
        x->set_title("is doing something important Do NOT Disturb [BUSY]");
        x->set_pretitle("[BUSY]");
        write("You change your title to let people know you are busy\n");
        return 1;
        }

// int drop() {
//     write("No way!\n");
//     return 1;
// }


query_auto_load() {
}

