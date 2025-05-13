#include "/players/nylakoorub/guild/defines.h"
#include "/sys/levels.h"



guild_status (ob) {
    string name;
    object soul;
    soul = present("vagsoul", ob);
    name = ob->query_real_name();
    if(!soul) {
	return ladjust("ERROR!", maxstatuschr);
    }
    if(soul->query_banish_status()) {
	return ladjust("Guild Outcast", maxstatuschr);
    }

    switch(soul->query_gld_status()) {
    case R_MASTER:
	return ladjust("Retired GM", maxstatuschr);
	break;
    case G_MASTER:
	return
	ladjust("GUILD MASTER", maxstatuschr);
	break;
    case N_MASTER:
	return ladjust("GM-in-Training", maxstatuschr);
	break;
    default:
	switch(ob->query_level()) {
	case 53..99:
	    return 
	    ob->query_pretitle();
	    break;
	case 23..52:
	    return
	    ladjust("Guild Member", maxstatuschr);
	    break;
	case 13..22:
	    return
	    ladjust("New Member", maxstatuschr);
	    break;
	case 12:
	    return
	    ladjust("Guild Ascendant", maxstatuschr);
	    break;
	case 2..11:
	    return
	    ladjust("Vag in Training", maxstatuschr);
	    break;
	case 1:
	    return
	    ladjust("New Recurit", maxstatuschr);
	    break;
	default:
	    return
	    ladjust("-", maxstatuschr);
	    break;
	}
    }
    return 1;
}


