#include "/obj/lw.h"
#include "/obj/adjust.h"
#include "/players/nylakoorub/guild/defines.h"
#include "/sys/levels.h"
#define TL_LINE "/players/nylakoorub/guild/lib/cmds/atl/tl_line/"



tl_line(ob) {
    object soul;
    soul = present("vagsoul", ob);
    if(soul) {
	return ladjust(soul->query_tl_line(), maxlinechr);
    }
}



int do_timelord(string str) {
    int i,j,gd;
    string name;
    object *u;
    object soul;
    soul = present("vagsoul", this_player());
    gd = "guild/master"->query_number("vagabond");
    if(!str){
	write("\n");
	printf("%|' '78s\n",
	  "The Order of Timelords of the Vagabonds of Time and Space");
	printf("%|'='78s\n","=");
	write(
	  ladjust("Name",maxnamechr)+
	  ladjust("Level",maxlevelchr)+
	  ladjust("Timelord Status", maxtlstatuschr)+
	  ladjust("Line", maxlinechr)+
	  "\n");
	write(sprintf("%'='78s\n","="));
	u=sort_array(filter_array(users(),"gd_filter",this_object(),0),
	  "ranksort",this_object());
	j = sizeof(u);
	for(i=0;i<j;i++){
	    if(!interactive(u[i]) && !this_player()) {
	    }
	    else {
		write(
		  ladjust(CAP(u[i]->QRN),maxnamechr)+
		  ( (CHECKS+"level")->level(u[i]) )+
		  ( (CHECKS+"timelord_status")->timelord_status(u[i]) )+
		  ( tl_line(u[i]) )+
		  "\n");
	    }
	}
	if(j < 2 ) {
	    printf("%|'='78s\n",
	      "You are the only Timelord on");
	} else
	    printf("%|'='78s\n",
	      "There are "+j+" Timelords on");
	write("TIMELORD HEADLINES:\n");
	if(file_size(HELP+"tlnews.txt") > 0 ) {
	    cat(HELP+"tlnews.txt");
	} else {
	    write("No news at this time.\n");
	}
	printf("%|'='78s\n",
	  "=");
	return 1;
    }
    if(str=="on"){
	(TL_LINE+"tlemote.c")->do_tlemote("has turned on "+
	  TP->query_possessive()+
	  " Timelord line");
	soul->set_tl_line("ON");
	return 1;
    }
    if(str=="off"){
	(TL_LINE+"tlemote.c")->do_tlchat("has turned off "+
	  TP->query_possessive()+
	  " Timelord line");
	soul->set_tl_line("OFF");
	return 1;
    }
    if(query_verb()=="timelord/") {
	(TL_LINE+"tlemote")->do_tlemote(str);
	return 1;
    }
    (TL_LINE+"tlchat")->do_tlchat(str);
    return 1;
}

int gd_filter(object ob){
    return (int)ob->query_guild()==10 &&
    ( file_size(STATUS+ob->QRN+".tl") > 0  ||
      file_size(STATUS+ob->QRN+".atl") > 0  ||
      file_size(STATUS+ob->QRN+".agm") > 0  ||
      ob->QRN == "nylakoorub" );
}


int ranksort(object a, object b){
    return (int)a->QL+
    (int)a->query_legend_level() <
    b->QL+b->query_legend_level();
}
