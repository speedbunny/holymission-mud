inherit "/obj/thing";

#include "/players/mangla/defs.h"

int _spread(string str) {

    int i;

    if (str=="salve") {
        if (TP->query_guild() == 4) {
            write("You spread the salve across you wounds and feel\n" +
                  "as if it is cleansing you to the soul.\n");
            i = TP->MAXHP - TP->HP;
            if (i > 50) i = 40;
            TP->ADDHP(i);
            i = TP->MAXSP - TP->SP;
            if (i > 50) i = 35;
            TP->ADDSP(i);
            destruct(TO);
            return 1;
        }
        else write("Only Jedis may use this salve!\n");
        return 1;
    }
    return 0;
}

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("Healing Salve");
    set_alias("salve");
    set_name("Healing Salve");
    set_long("This is a healing salve specially made for the Jedis.\n" +
             "All you ned to do is 'spread salve' to use it.\n");
    set_weight(1);
    set_value(100);
}


init() {
  add_action("_spread","spread");
  ::init();

}

