inherit "obj/armour";
inherit "/players/shadowmonk/inherit/feelings";
#include "/players/shadowmonk/include/defs.h"

void reset( int arg ) {    
    ::reset( arg );    
    if(arg) return; 

    set_name
	("ring");    
    set_alias
	("glass ring");
    set_short
	("A glass ring");
    set_long
	("A simple glass ring!\n");
    set_weight(0);
    set_value(0);
    set_ac(0);
    set_type("ring");
}

void init() {
    if( !( TP->query_immortal() ) ) {
        notify_fail("Only immortals can use this item.\n");
        return 0;    
    }
    armour::init();
    get_feelings();
}

void start() {
  wear("glass ring");
  TTP("You worn your cheap glass ring!");
  return;
}

mixed query_auto_load() {    
    return "players/shadowmonk/inherit/feelring:feelring";
}

void init_arg(string str) {
  call_out( "start", 2, TO );
  return;
}

int drop(string arg) {
  if(query_verb()=="sell")
    TTP("Sell this cheap glass ring? Never!\n");
  else if(query_verb()=="give") 
    TTP("Give your cheap glass ring away? Never!\n");
  else TTP("Drop your cheap glass ring? Never!\n");
  return 1;
}
