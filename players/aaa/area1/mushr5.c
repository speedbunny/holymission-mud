/* Completed 14.01.1995 */
/* Warning: special approvement required! */

#include <std.h>
inherit "/obj/treasure";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("mushroom");
    set_id("mushroom");
    set_short("a mushroom");
    set_long("A strange-looking mushroom. It is yellow with blue spots. "+
             "Looks delicious!\n");
    set_value(5);
    set_weight(0);
}

void init() {
    ::init();
    add_action("eat","eat");
}

int eat(string str) {
    if((!str) || (!id(str))) {
        notify_fail("Eat what?\n");
        return 0;
    }
    this_player()->heal_self(200);
    write("Yum-yum-yum... that was good!\nYou feel better.\n"+
          "Much-much better!\n");
    say(this_player()->query_name()+" devours a mushroom.\n");
    destruct(this_object());
    return 1;
}
