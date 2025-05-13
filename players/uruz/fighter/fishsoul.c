inherit "obj/thing";
#include "/players/exos/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
	set_name("fishsoul");
	set_weight(0);
	set_can_get(1);
	}
init(){
	::init();
	AA("_filter", "", 1);
	AA("cast_spell", "cast");
	}
int _filter(string str){
	string verb;
	verb= query_verb();
	if(verb[0]==39) return 0;
	if(file_size("/players/trout/fighter/skills/" +verb+".c")>0)
	     if(("/players/trout/fighter/skills/" +verb)->main(str))
		return 1;
	else return 0;
	return 0;
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
    if(file_size("/players/trout/bard/spells/"+spellname[0]+".c")>0)
     	if(("/players/trout/bard/spells/"+spellname[0])->main(newstr))
	    return 1;
    ME("You do not know that spell!\n");
    return 1;
}
