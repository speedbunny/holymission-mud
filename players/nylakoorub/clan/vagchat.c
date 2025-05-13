#include "/players/nylakoorub/guild/defines.h"

check_line(ob) {
    object soul;
    soul = present("vagsoul", ob);
    if(soul) {
	if(soul->query_vag_line() == "OFF" )
	    return "off";
	else
	    return "on";
    }
}


do_vagchat(string str) {
    int i,j;
    object *u;
    u= filter_array(users(), "vag_filter", this_object(),0);
    j = sizeof(u);
    for(i=0;i<j;i++) {
	if(check_line(u[i]) == "off") {
	}
	else {
	    if(TP->query_invis() &&
	      u[i] != this_player() ) {
		if(u[i]->QL < TP->QL ) {
		    if(u[i]->QL > TP->query_invis() )
			tell_object(u[i],
			  "-= "+
			  capitalize(TP->QRN)+
			  " (invis "+
			  TP->query_invis()+
			  ") says: =- "+
			  str+"\n");
		    else
			tell_object(u[i],
			  "-= Someone says: =- "+
			  str+"\n");
		} else {
		    tell_object(u[i],
		      "-= "+
		      capitalize(TP->QRN)+
		      " (invis "+
		      TP->query_invis()+
		      ") says: =- "+
		      str+"\n");
		}
	    }
	    else 
		tell_object(u[i],
		  "-= "+
		  capitalize(TP->QRN)+
		  " says: =- "+
		  str+"\n");
	}
    }
    return 1;
}



int vag_filter(object ob) {
    return (int)ob->query_guild()==10;
}


