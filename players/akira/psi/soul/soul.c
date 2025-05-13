inherit "obj/treasure";
#include "/players/akira/defs.h"
#include "/obj/lw.h"

int guild;
string psi_line, mindblock;
int get(){ return 1;}
int drop(string arg){ return 1;}

string query_psi_line(){ return psi_line; }
set_psi_line(string arg){ psi_line= arg; }
string query_mindblock(){ return mindblock; }
set_mindblock(string str){ mindblock= str; }
int id(string str){ 
	return (str=="psi-amulet" || str=="guildsoul"); }
void reset(int arg){
	::reset(arg);
	if(!arg){
	set_short("A Triangular Psi-Amulet");
	set_long("This is the amulet of the great Psionicist's School of "+
	"Mental Aptitude. This is also a focus point for your psionic "+
	"abilities.\n");
	set_weight(0);
	set_value(0);
	set_alias("amulet");
	guild= "guild/master"->query_number("bard");
	         }
	}

init(){
	::init();
	set_psi_line("on");
	set_mindblock("off");
	AA("_filter", "", 1);
	"sys/chatd.c"->do_chat(guild, "** You feel "+CAP(TPRN)+"'s mind "+
	"present among the telepaths now.\n");
	}

int _filter(string str){
    string verb;

    	verb= query_verb();
	if(verb[0]==39){ return 0; }
	if(verb=="quit" || verb=="dest"){ return 0; }
	if(verb=="psi" || verb=="psi/" || verb=="psi#"){
	    (BIN + "psi.c")->main(str);
	    return 1;
	    }
	if(file_size(BIN + verb + ".c") > 0)
	    if((BIN + verb)->main(str))
		return 1;
	else return 0;
	return 0;
	}
