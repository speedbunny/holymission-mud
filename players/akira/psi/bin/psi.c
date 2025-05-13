#include "/obj/lw.h"
#include "/obj/adjust.h"
#include "/players/akira/defs.h"
#include "/players/trout/psi/level.h"
#define GUILDNUMBER 6
#define maxname 20
#define maxline 5
#define maxlevel 20
#define maxstatus 25

string psi_level(object psi){
	switch(psi->QLEVEL()){
	    case LEGEND:
		if(psi->query_legend_level() > 0){
		    return( ladjust("Legend Level "+TPQLL, maxlevel));}
		    break;
	    case APPRENTICE:
		return( ladjust("Apprentice Wizard", maxlevel));
		break;
	    case NEWWIZ:
	  	return( ladjust("New Wizard", maxlevel));
		break;
	    case WIZ:
		return( ladjust("Wizard", maxlevel));
		break;
	    case SAGE:
		return( ladjust("Sage", maxlevel));
		break;
	    case RETIRED:
		return( ladjust("Retired Arch", maxlevel));
		break;
	    case ELDER: 
	   	return( ladjust("Elder", maxlevel));
		break;
	    case ARCH:
		return( ladjust("Arch-Wizard", maxlevel));
		break;
	    case HERP:
		return( ladjust("God", maxlevel));
		break;
	    default:
		     return(ladjust(psi->query_level(), maxlevel));
	}
   }

string guild_status(object psi){
	if(psi->QRN()=="trout" || psi->QRN()=="akira"){
	   return( ladjust("Guild Master", maxstatus));}
	else if(psi-> QLEVEL() >29){
	   return( ladjust("Visiting Immortal", maxstatus));}
	else if(psi->query_testchar()){
	    return( ladjust("Test Character", maxstatus));}
	else if(psi->QLEVEL() < 30){
	   return( ladjust("Guild Member", maxstatus));}
	}

int main(string str){
    int guild, i, j;
    object *ob, amulet;
	guild= "guild/master"->query_number("bard");
   	if(!str){
	    write("\n");
	    printf("%|'*'78s\n", " The Psionicists's Guild ");
	    printf("%|'*'78s\n", "*");
	    write(
		ladjust("Name", maxname)+
		ladjust("Level", maxlevel)+
		ladjust("Status", maxstatus)+
		ladjust("Line", maxline)+
		"\n");
	    printf("%'*'78s\n", "*");
	    ob=sort_array(filter_array(users(),"guild_filter",TO(),0),"level"+
	    "sort",TO());
	    j= sizeof(ob);
	    for(i=0; i<j; i++){
		amulet= present("psi-amulet", ob[i]);
		write(ladjust(CAP(ob[i]->QRN()), maxname)+
		(psi_level(ob[i]))+
		(guild_status(ob[i]))+
		ladjust(amulet->query_psi_line(), maxline)+
		"\n");
	        }
	    if(j==1) {printf("%|'*'78s\n", " There is 1 psionicist on "); }
	    else{ printf("%|'*'78s\n", " There are "+j+" psionicists on "); }
	    return 1;
	    }
    	amulet= present("psi-amulet", TP());
	if(str=="on"){
	    amulet->set_psi_line("on");
	    write("You open your mind, allowing you to now receive telepathic"+
	    " transmissions.\n");
	    "sys/chatd.c"->set_line(TP(),guild, 1);
	    return 1;
	    }
	if(str=="off"){
	    amulet->set_psi_line("off");
	    write("You close your mind to all telepathic transmissions.\n");
	    "sys/chatd.c"->set_line(TP(), guild, 0);
	    return 1;
	    }
	if(query_verb()=="psi/"){
		"sys/chatd.c"->do_chat(guild, lw("** "+CAP(TPRN)+" "+str+" \n"));
		return 1;
    }
	if(query_verb()=="psi#" && (TPRN=="trout" || TPRN=="akira")){
		"sys/chatd.c"->do_chat(guild, lw("GUILD ANNOUNCEMENT:\n"+
		  "** "+str+" \n"));
		return 1;
		}
	"sys/chatd.c"->do_chat(guild, lw("** "+CAP(TPRN)+" says: "+str+" \n"));
	return 1;
	}

int guild_filter(object psi){
	return (int)psi->query_guild()==GUILDNUMBER; }
int levelsort(object ob1, object ob2){
	return (int)ob1->QLEVEL() < ob2->QLEVEL(); }
