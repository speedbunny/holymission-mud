#include "/players/trout/defs.h"

int main(string str){

object pike, here;
string corpname, name, name1;
	
 	if(!str){
	     write("Useage: impale corpse of <name>\n");
	     return 1;
	     }
	sscanf(str, "corpse of %s", corpname);
	here=present(str, ENV(TP()));
	if(TP()->QSP<5){
	     write("You are to tired to impale anything!\n");
	     return 1;
	     }
	if(!present("corpse", ENV(TP()))){
	     write("There is no corpse here to impale!\n");
	     return 1;
	     }
	if(here->query_living()){
	     write("You can only impale a corpse!\n");
	     return 1;
	     }
	MO(CO(YY+"/fighter/obj/pike"), ENV(TP()));
	pike= present("impaled remains", ENV(TP()));
	name= here->query_name();
	name1= TPRN;
	pike->set_name("impaled remains of "+CAP(corpname)+"");
	pike->set_long("A lifeless hulk of a bloody carcass lies impaled "+
	"upon this pike! You can barely distinquish the mass as the "+name+"."+
	" You see the name '"+CAP(name1)+"' etched on the pike's blade!\n");
	destruct(here);
	
	write("You impale the "+name+" on a long pike! You feel as rush as"+
	" the blood oozes through your hands!\n");
	say(CAP(TPRN)+" grabs the bloody remains of the "+name+" and impales"+
	" it upon a rather long pike, leaving it as a symbol a a fighter's "+
	"true savagery!\n", TP());

	return 1;
	}
