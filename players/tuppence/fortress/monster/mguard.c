inherit "obj/monster";
#include "/players/tuppence/include/defs.h"
string chats;
reset(arg) {
    ::reset(arg);
    if(!arg){
	set_name("mage guard");
	set_race("elf");
	set_short("Mage guard");
	set_long("This mage guard is here so no one gets in.\n");
	set_alias("guard");
	set_level(20);
	set_al(-400);
	set_ac(10);
	set_wc(20);
	set_spell_mess1("Mage guard uses the rod and a lightning bolt flys out.\n");
	set_spell_mess2("Mage guard points his rod at you and hits you with a flying\n"+
	  "lightning bolt!\n");
	set_chance(30);
	set_spell_dam(20);
	if(!chats) {
	    chats=allocate(3);
	    chats[0]= "Guard says: The evil dark Lord is busy tonight.\n";
	    chats[1]= "Guard peers at you with one evil red eye.\n";
	    chats[2]= "Guard says: No one may see the evil dark Lord!\n";
	}
	load_chat(2,chats);
    }
}
void init() {
::init();
    add_action("_east","east");
}
_east() {
write("You try to go east but the mage guards stop you!\n");
return 1;
}
