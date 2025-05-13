#include "/players/sargon/define.h"

int calm() {
    object soul;

    soul = previous_object();

    if(!soul->query_berzerk()) {
        write("You are not berzerking at the moment.\n");
        return 1;
    }

    else if(TP->query_spell_points() < 5) {
        write("You no longer have the mental energy to stop");
        return 1;
    }

    else {
        soul->set_berzerk(0);
        TP->restore_spell_points(-5);
        write("You start to calm yourself down.\n");
        return 1;
    }
}
