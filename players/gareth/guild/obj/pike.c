inherit "obj/thing";
#include "/players/gareth/define.h"



int x;
string corpget;
set_corpget(object ob){
	corpget= ob->query_name();
	}
string query_corpget(){

	if(corpget==  TPN){
		x=1;
		}
	else{
		x=0;
	    }
	}
reset(arg){

	::reset(arg);
	if(arg) return;
	set_short("impaled remains");
	set_alias("remains");
	set_alt_name("impaled remains");
	set_long("A bloody pike!");
	}


get(){
	     query_corpget();
	     if(x=1){
		MO(TO, TP);
		write("You pick up your impaled prize.\n");
		return 1;
		}
	     if(x=0){
	     	write("You cannot get the impaled remains! They are not yours"+
		"!\n");
		return 0;
		}
	      }
