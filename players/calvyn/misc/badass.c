#include "/players/gareth/define.h"
inherit "/obj/npc";
reset(arg) {
    ::reset(arg);
    if(!arg) {
    set_name("drider");
    set_short("A drider");
    set_long("It's yellow eyes make you shiver from fright.\n"+
      "It appears to be a cross between a giant spider and a drow.\n" +
      "The head, torso, and arms of a pale, bloated drow sprout\n"+ 
      "eight spider legs. Due to it's bloated form it's impossible\n"+ 
      "to tell the sex of the drider.\n") ;
    set_level(999);
    set_ac(1);
    set_dex(1);
    set_wc(1);
    set_hp(10);
    set_al(1000);
    
}

}
