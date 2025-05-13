inherit "/obj/armour";
#include "/players/trout/defs.h"

reset(arg) {
   ::reset(arg);
   if (arg) return 1;
   set_type("armour");
   set_name("harness");
  set_ac(3);
  set_short("A Juicer Harness");
   set_long("This is a Juicer Drug Harness. A Juicer wears this elaborate "+
	"system of bio-computers and drug injectors to gain his incredible "+
	"speed and strength! You must first 'inject' a drug into the "+
	"bio-comp before you can use it. The following drugs are available "+
	"to you: speed, steroids, and pcp (painkiller). \n");
 set_value(80000);
   set_weight(5);
   return 1;
}

init(){
	::init();
	AA("_juice", "inject"); }
_juice(str){
	if(str=="speed")
		{MO(CO(YY+"/personal/haste"), TP());
		 write("You inject speed into your bio-comp. Now 'juice' it."+
		" \n");
		return 1; }
	if(str=="steroids")
		{MO(CO(YY+"/personal/strength"), TP()) ;
		  write("You inject steroids into your bio-comp. Now 'juice' "+
		  "it. \n");
		return 1; }
	if(str=="pcp")
		{ MO(CO(YY+"/personal/pain"), TP());
		  write("You inject pcp into your bio-comp. Now 'juice' "+
		"it. \n");
		 return 1; }
	}

