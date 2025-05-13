inherit "/obj/monster";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name 	
	("oleman");
    set_short	
    	("an old man");
    set_long	
	("This is a very old man, with a very good story to tell!\n");
    set_race("human");
    set_aggressive(0);
    set_level(5);
    set_gender(1);
    set_number_of_arms(2);
    set_dead_ob(TO);
}

void tell_objects_of_dead(object attacker, object *inv) {
    int     i, j;
    TOB("The old man feels a sharp pain in his chest as you "+
	"continue to beat him, and he is dead.", attacker);
    TOP(CAP(attacker->RNAME)+" murders the sweet oleman by beating him up, "+
	"and a voice wells up from within you.", attacker);
    for(i=0; i<sizeof(inv); i++)
	if(inv[i] != attacker && inv[i] != TO && living(inv[i])) {
	    TOB("You shout at "+CAP(attacker->RNAME)+" 'Murderer!'.",inv[i]);
	    TOB(CAP(inv[i]->RNAME)+" shouts 'Murderer!' at you!", attacker);
	    for(j=0; j<sizeof(inv); j++)
		if(inv[j] !=attacker && inv[j] != inv[i] && living(inv[j]))
		    TOB(CAP(inv[i]->RNAME)+" shouts 'Murderer!' to "+
			CAP(attacker->RNAME)+".", inv[j]); 
	}
}

status monster_died(object ob) {
    object *inv, attacker;

    inv = all_inventory(environment());
    attacker = TO->query_attack();
    tell_objects_of_dead(attacker, inv);
    call_other( HOME+"inherit/deed_area1", "add_deed", 
                                    ({ attacker->RNAME, "kills", "oleman" }) );
    return 0;
}
 
int attack() {
    object attacker;
    attacker = TO->query_attack();
    TOB("The oleman tries to cover his head with his arms.", attacker); 
    TOP("As "+CAP(attacker->RNAME)+" is butchering the oleman, the "+
	"oleman tries to protect his head with his arms.", attacker);
    return 0;
}
