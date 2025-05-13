inherit "obj/treasure";
#include "bard.h"
#include "/players/exos/levels.h"
#include "/players/exos/guild/bin/sing.h"
//Too much timing in the singing functions to have as seperate object - Exos
int guild;
string bardline;

int get() { return 1; }
int drop(string str) { return 1; }
string query_bard_line() { return bardline; }
int set_bard_line(string str) {
    bardline=str;
}

int id(string str) { return (str=="lute" || str=="bardsoul" || str=="guildsoul"); }

void reset(int arg) {
    ::reset(arg);
    if (!arg) {
	set_name("lute");
	set_alias("guildsoul");
	set_short("A well-crafted Lute");
	set_long("This is your gift from Taliesin.  Your lute is your most\n"+
	  "prized possession.  It also lets you perform your bardic\n"+
	  "magic.  The symbol of The Harpers is on the back.\n");
	set_value(0);
	set_weight(0);
	guild = GM->query_number("bard");
    }
}

void init() {
    ::init();
    set_bard_line("On");
    AA("_cast","cast");
    AA("_filter","",1);
    if(!TPWIZ && !TPINV) CD->do_chat(guild,"<*> "+CAP(TPRN)+
	  ", wanders back into our land. <*>\n");
    if (!TPWIZ) {
	TP->setmin("enters strumming "+TPOSS+" lute");
	TP->setmout("strums "+TPOSS+" lute, as "+TPRO+" strolls");
    }
}

int cast_spell(string str) {
    string *spellname;
    string newstr;
    int i, j;
    
    spellname=explode(str," ");
    i=sizeof(spellname);
    if (i>1)
	for (j=1;j<i;j++)
	    if (j==1) newstr=spellname[j];
    else newstr=newstr+" "+spellname[j];
    if (file_size(SPELL+spellname[0]+".c")>0)
	if ((SPELL+spellname[0])->main(newstr))
	    return 1;
    ME("You do not know that spell!\n");
    return 1;
}

int _cast(string str) {
    if(!str) {
	ME("Cast which spell?\n");
	return 1;
    }
    if(FCO("cast_spell") != -1) {
	ME("You are already casting a spell!\n");
	return 1;
    }
    CO("cast_spell",1,str);
    return 1;
}

int _filter(string str) {
    string theverb;
    
    theverb = query_verb();
    if (theverb[0]==39) return 0;
    if (theverb=="quit" || theverb=="dest") return 0;
    if(theverb=="bard/" || theverb=="bard=") {
	(BIN+"bard")->main(str);
	return 1;
    }
    if (file_size(BIN + theverb + ".c") > 0)
	if ((BIN + theverb)->main(str))
	    return 1;
    else return 0;
    return 0;
}

