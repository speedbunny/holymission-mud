inherit "/obj/monster";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
 
    set_name 	
	("child");
    set_alias
        ("boy");
    set_alt_name
	("little boy");
    set_short	
	("a child");
    set_long	
	("You see a little child, playing happily with a toy carriage!\n");
    set_race	
	("human");
    set_aggressive(0);
    set_level(3);
    set_hp(20);
    set_ac(5);
    set_wc(5);
    set_gender(1);
    set_number_of_arms(2);
    set_dead_ob(TO);
}

void tell_objects_of_dead(object attacker, object *inv) {
    int     i, j;
    TOB("The child drops to his knees, the toy carriage slipping from his hand, "+
	"and it is dead.", attacker);
    TOP(CAP(attacker->RNAME)+" murders the sweet sweet child, and a voice "+
	"wells up from within you.", attacker);
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
                                    ({ attacker->RNAME, "kills", "boy" }) );
    return 0;
}
 
int attack() {
    object attacker;
    if (::attack()) {
	attacker = TO->query_attack();
	TOB("The child very bravely tries to hit you with his toy carriage.",
	    attacker); 
        TOP("As "+CAP(attacker->RNAME)+" is butchering the child, it "+
	    "bravely tries to hit his attacker back with his toy carriage.", 
	     attacker);
	return 1;
    }
    return 0;
}
