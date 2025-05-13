#include "/players/sargon/define.h"
#define GM "/guild/master"


help(arg) {
    string skills;
    int gd;
    gd = 3;
    switch(arg) {
    case "guild":
        TP->more ("/players/sargon/guild/help/fhelp.txt");
        break;
    case "levels":
        GM->list_levels(gd);
        break;

    case "spell":
    case "spells":
        write("Fighters can't use spells - ya moron!\n");
        break;
    case "check":
        cat ("/players/sargon/guild/help/check");
        break;
    case "parry":
        cat("/players/sargon/guild/help/parry");
        break;
    case "fix":
        cat("/players/sargon/guild/help/fix");
        break;
    case "but":
        cat ("/players/sargon/guild/help/but");
        break;
    case "munch":
        cat ("/players/sargon/guild/help/munch");
        break;
    case "stronghold":
        cat ("/players/sargon/guild/help/stronghold");
        break;
    case "compare":
        cat ("/players/sargon/guild/help/compare");
        break;
    case "track":
        cat("/players/sargon/guild/help/track");
        break;
    case "berzerk":
        cat ("/players/sargon/guild/help/berzerk");
        break;
    case "fighter":
    case "fighters":
        cat ("/players/sargon/guild/help/fighter");
        break;
    case "legends":
        cat ("/players/sargon/guild/help/legends");
        break;
    case "rescue":
        cat ("/players/sargon/guild/help/rescue");
        break;
    case "bash":
        cat ("/players/sargon/guild/help/bash");
        break;
    case "lower":
        cat ("/players/sargon/guild/help/lower");
        break;
    case "block":
        cat ("/players/sargon/guild/help/block");
        break;
    case "calm":
        cat ("/players/sargon/guild/help/calm");
        break;
    case "smash":
        cat ("/players/sargon/guild/help/smash");
        break;
    case "query":
        cat ("/players/sargon/guild/help/query");
        break;
    case "groin":
        cat ("/players/sargon/guild/help/groin");
        break;
    default:
        notify_fail("Help with what?\n");
        return 0;
    }
    return 1;
}

