inherit "obj/armour";
#include "/players/turbo/defs.h"
object c;
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("jade necklace");
    set_alias("necklace");
    set_size("any");
    set_short(" A beautiful jade necklace");
      set_long("This neckale was formed by a spell cast by a Jade Statue"+
               " upon its death. Its magic is weak though, and isn't usual"+
               "ly permanent.\n");
    set_ac(2);
    set_weight(2);
    set_value(500);
    drop();
    return 1;
}

drop() 
{
 write("You cannot get rid of the necklace. You must wait 10 min or quit.\n");
return 1; }
init(){
    ::init();
    add_action("_nope","junk");
AA("_nope","give");
AA("_nope","sell");
}

_nope(str) {
    if(!str){
	notify_fail("What do you want to do ?\n");
	return 0;
    }
    if(str =="necklace"){
write("The magic of the necklace stops you.\n");
	return 1;
    }
}

