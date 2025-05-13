#include "/obj/lw.h"
#include "/obj/adjust.h"
#include "/players/nylakoorub/guild/defines.h"
#include "/sys/levels.h"
#define VAGLINE "/players/nylakoorub/guild/lib/cmds/vags/vagline/"

int nyla_holo;

vag_line(ob) {
    object soul;
    soul = present("vagsoul", ob);
    if(soul) {
	return ladjust(soul->query_vag_line(), maxlinechr);
    }
}



int do_vag(string str){
    int i,j,gd;
    string name;
    object *u;
    object soul;
    soul = present("vagsoul", this_player());
    gd = "guild/master"->query_number("vagabond");
    if(!str){
	write("\n");
	printf("%|' '78s\n",
	  "The Guild of the Vagabonds of Time and Space");
	printf("%|'='78s\n","=");
	write(
	  ladjust("Name",maxnamechr)+
	  ladjust("Level",maxlevelchr)+
	  ladjust("Guild Status",maxstatuschr)+
	  ladjust("Line", maxlinechr)+
	  ladjust("Where in Time and Space",maxwherechr)+
	  "\n");
	write(sprintf("%'='78s\n","="));
	u=sort_array(filter_array(users(),"gd_filter",this_object(),0),
	  "ranksort",this_object());
	if(nyla_holo) {
	    if(find_living("nylakoorub")) {
	    } else {
		write(
		  ladjust("Nylakoorub", maxnamechr)+
		  ladjust("Elder", maxlevelchr)+
		  ladjust("GUILD MASTER", maxstatuschr)+
		  ladjust("ON", maxlinechr)+
		  ladjust("Nylakoorub's Dimension", maxwherechr)+
		  "\n");
	    }
	}
	j = sizeof(u);
	for(i=0;i<j;i++){
	    if((!interactive(u[i]) || !environment(u[i])->short() ) &&
	      !this_player()) {
	    }
	    else {
		write(
		  ladjust(CAP(u[i]->QRN),maxnamechr)+
		  ( (CHECKS+"level")->level(u[i]) )+
		  ( (CHECKS+"guild_status")->guild_status(u[i]) ) +
		  ( vag_line(u[i]) )+
		  ladjust(
		    environment(u[i])->short(),
		    maxwherechr)+
		  "\n");
	    }
	}
	if(j < 2 ) {
	    printf("%|'='78s\n","You are the only vagabond on");
	} else
	    printf("%|'='78s\n","There are "+j+" vagabonds on");
	write("GUILD HEADLINES:\n");
	if(file_size(NEWS+"mainhl.txt") > 0 ) {
	    this_player()->more_string(read_file(NEWS+
		"mainhl.txt"));
	} else {
	    write("No news at this time.\n");
	}
	printf("%|'='78s\n",
	  "=");
	return 1;
    }
    if(str=="on"){
	write("You turn on the guild channel.\n");
	"sys/chatd.c"->set_line(TP,gd,0);
	"sys/chatd.c"->do_chat(gd, lw("-= "+
	    CAP(TP->query_real_name())+
	    " has turned back on his Vag line. =-\n"));
	"sys/chatd.c"->set_line(TP,gd,1);
	soul->set_vag_line("ON");
	return 1;
    }
    if(str=="off"){
	write("You turn off the guild channel.\n");
	"sys/chatd.c"->set_line(TP,gd,0);
	"sys/chatd.c"->do_chat(gd,lw("-= "+
	    CAP(TP->query_real_name())+
	    " has turned off his Vag line. =-\n"));
	soul->set_vag_line("OFF");
	return 1;
    }
    if(query_verb()=="vag/"){
	(VAGLINE+"vagemote")->do_vagemote(str);
	return 1;
    }
    (VAGLINE+"vagchat")->do_vagchat(str);
    return 1;
}

int gd_filter(object ob){
    return (int)ob->query_guild()==10;
}

int ranksort(object a, object b){
    return (int)a->QL+
    (int)a->query_legend_level() <
    b->QL+b->query_legend_level();
}


set_nyla_holo(arg) {
    nyla_holo = arg;
}

