inherit "/obj/monster";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
 
    set_name 	
	("child");
    set_alias
        ("girl");
    set_alt_name
	("little girl");
    set_short	
	("a child");
    set_long	
	("You see a little child, playing happily with a doll!\n");
    set_race	
	("human");
    set_aggressive(0);
    set_level(3);
    set_hp(20);
    set_ac(5);
    set_wc(5);
    set_gender(2);
    set_number_of_arms(2);
    set_dead_ob(TO);
}

void tell_objects_of_dead(object attacker, object *inv) {
    int     i, j;
    TOB("The child drops to her knees, the doll slipping from her hand, "+
	"and she is dead.", attacker);
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
                                    ({ attacker->RNAME, "kills", "girl" }) );
    return 0;
}
 
int attack() {
    object attacker;
    attacker = TO->query_attack();
    TOB("The child tries to hide herself behind her doll.",attacker); 
    TOP("As "+CAP(attacker->RNAME)+" is butchering the child, it "+
	"tries to hide behind her doll.", attacker);
    return 0;
}
