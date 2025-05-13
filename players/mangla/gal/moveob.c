inherit "/obj/thing";

#include "/players/mangla/defs.h"

int _kataname() {

    if (TP->query_guild() == 8)
        MOVE(clone_object("/players/tatsuo/guild/nweap/katana"), TP);
    else
        write("You are not a ninja.  This would do you no good.\n");
    destruct(TO);
    return 1;
}

int _shutome() {

    if (TP->query_guild() == 8)
        MOVE(clone_object("/players/tatsuo/guild/nweap/ninja_to"),TP);
/*
        MOVE(clone_object("/players/patience/guild/nweap/shuto"),TP);
*/
    else
        write("You are not a ninja.  This would do you no good.\n");
    destruct(TO);
    return 1;
}

int _daime() {

    if (TP->query_guild() == 8)
        MOVE(clone_object("/players/tatsuo/guild/nweap/diato"),TP);
    else
        write("You are not a ninja.  This would do you no good.\n");
    destruct(TO);
    return 1;
}

int _rockme() {

    if (TP->query_level() > 29)
        MOVE(clone_object("/tools/wizrock"),TP);
    else
        write("You are too low level for this simple command.\n");
    destruct(TO);
    return 1;
}

void reset(int arg) {

    if(arg) return;
    ::reset();
    set_alias("temp");
    set_weight(0);
}

void init() {

    ::init();
    add_action("_kataname","katana_please");
    add_action("_shutome","shuto_please");
    add_action("_daime","daito_please");
    add_action("_rockme","wizrock_please");
}

