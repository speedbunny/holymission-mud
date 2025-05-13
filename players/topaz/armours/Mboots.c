inherit "obj/armour";

#include "/players/topaz/defs.h"

int busy;


int _rest() {

    busy=0;
    return 1;
}

int _kick() {

    int ouch;
    object jerk;

    if(!TP->query_attack()) return 0;  //  Have to change this in hopes
                                       //      of not interfering with the
                                       //      soul command too much.

    if (worn) {
        if (!TP->query_attack()) {
            return 0;  // that is, if not in a fight, then go to soul command.
        }
        else {
            if(busy) {
                write("Your feet need a rest.\n");
                return 1;
            }
            else {
                jerk = TP->query_attack(); 
                if (environment(jerk) != environment(TP)) {
                    write("You do not see you oppenent in this room.\n");
                    // make the wording better ^
                    // that was in case they are not in the sme room as the attacker
                    return 1;
                }
                ouch = 5+(random(6));
                write("You kick " + jerk->query_name() + " in the leg.\n");
                jerk->restore_hit_points(-ouch);
                busy = 1;
                call_out("_rest",5);
                return 1;
            }
        }
    }
    else {
        write("You must be wearing the boots to use them.\n");
    }
    return 1;
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Kickboots");
    short_desc="Kickboots";
    long_desc="These are heavy boots with pointed toes.\n" +
              "To use them, type 'kick <opponent>' or\n" +
              "just 'kick' when in a fight.\n";
    set_alias("boots");
    set_type("boot");
    set_ac(1);
    set_weight(3);
    set_value(200);
  }
}

init() {
  ::init();

    add_action("_kick","kick");
}


