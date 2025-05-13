#include "/players/sargon/define.h"

int berzerk() {
    object soul;

    soul = previous_object();

    if(TP->query_ghost()) {
        write("You suddenly realize that this was a great mistake.\n\
The whole room is spinning around you.\n\
You decide to run as far as you can to leave this place.\n");
        TP->run_away();
        TP->run_away();
        write("As you feel your mind clearing you decide to rest for a \
moment.\n");
        return 1;
    }
  
    else if(TP->query_level() < 18) {
        write("You are not strong enough to go berzerk.\n");
        return 1;
    }

    else if(!TP->query_attack()) {
        write("You are not fighting anyone.\n");
        return 1;
    }

    else if(soul->query_berzerk()) {
        write("You are as berzerk as anyone can be.\n");  
        return 1;
    }
     
    else if(TP->query_spell_points() < 40) {
        write("You are too tired to go berzerk.\n");
        return 1;
    }

    else {
        write("You turn into a rampaging frenzy.\n");
        TP->restore_spell_points(-40);
// Higher the level the longer the berzerk lasts.
        soul->set_berzerk(40+TP->query_level());
        return 1;
    }
}
