inherit "obj/thing";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg)return;
	set_name("rainbow trout");
	set_alias("trout");
	set_can_get(1);
	set_weight(0);
	set_long("It's a rainbow trout, but it's standing on it's back fin!"+
	" It's dressed and a tophat and cane. Wierd.\n");
	set_value(15);
	call_out("_sing", 1);
	}
int _sing(){
	call_out("_sing1", 2);
	write("The rainbow trout clears his throat!\n");

	return 1;
	}
int _sing1(){
	call_out("_sing2", 2);
	write("Happy Birthday to you...\n");

	return 1;
	}
int _sing2(){
	call_out("_sing3", 2);
	write("Happy Birthday to you...\n");
	return 1;
	}
int _sing3(){
	call_out("_sing4", 2);
	write("Happy Birthday dear "+capitalize(TP()->query_real_name())+""+
	"....\n");
	return 1;
	}
int _sing4(){


	write("Happy Birthday to you!\n The rainbow trout returns to the "+
	"gift box!\n");
	return 1;
	}
