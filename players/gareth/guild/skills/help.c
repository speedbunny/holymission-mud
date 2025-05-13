#include "/players/gareth/define.h"
#define GM "/guild/master"


help(arg) {
    string skills;
    int gd;
    gd = 3;
    switch(arg) {
    case "guild":
	TP->more ("/players/gareth/guild/help/fhelp.txt");
	break;
    case "levels":
	GM->list_levels(gd);
	break;

    case "spell":
    case "spells":
	write("Fighters can't use spells - ya moron!\n");
	break;
    case "check":
	cat ("/players/gareth/guild/help/check");
	break;
    case "parry":
	cat("/players/gareth/guild/help/parry");
	break;
    case "fix":
	cat("/players/gareth/guild/help/fix");
	break;
    case "but":
	cat ("/players/gareth/guild/help/but");
	break;
    case "munch":
	cat ("/players/gareth/guild/help/munch");
	break;
    case "stronghold":
	cat ("/players/gareth/guild/help/stronghold");
	break;
    case "compare":
	cat ("/players/gareth/guild/help/compare");
	break;
    case "track":
	cat("/players/gareth/guild/help/track");
	break;
    case "berzerk":
	cat ("/players/gareth/guild/help/berzerk");
	break;
    case "fighter":
    case "fighters":
	cat ("/players/gareth/guild/help/fighter");
	break;
    case "legends":
	cat ("/players/gareth/guild/help/legends");
	break;
    case "rescue":
	cat ("/players/gareth/guild/help/rescue");
	break;
    case "bash":
	cat ("/players/gareth/guild/help/bash");
	break;
    case "lower":
	cat ("/players/gareth/guild/help/lower");
	break;
    case "block":
	cat ("/players/gareth/guild/help/block");
	break;
    case "calm":
	cat ("/players/gareth/guild/help/calm");
	break;
    case "smash":
        cat ("/players/gareth/guild/help/smash");
        break;
    case "query":
        cat ("/players/gareth/guild/help/query");
        break;
    default:
	notify_fail("Help with what?\n");
	return 0;
    }
    return 1;
}
