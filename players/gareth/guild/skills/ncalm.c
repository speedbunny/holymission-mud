#include "/players/gareth/define.h"

calm() {
        if(!TP->berzerk_shad()) {
                write("You are not berzerking at the moment.\n");
                return 1;
                }
        if(TP->query_spell_points()<5) {
                write("You no longer have the mental energy to stop");
                return 1;
                }
        call_out("calm_stop",6);
        TP->restore_spell_points(-5);
        write("You start to calm yourself down.\n");
        return 1;
        }

calm_stop() {
        if(TP->berzerk_shad()) {
                destruct(TP->berzerk_shad());
                write("You feel that your are completely calm once again.\n");
                }
        return;
        }
