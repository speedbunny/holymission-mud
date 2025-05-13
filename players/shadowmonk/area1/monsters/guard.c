inherit "/obj/monster";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name 	
	("guard");
    set_short	
	("a guard");
    set_gender(random(2)+1);
    set_long	
	("A well trained guard from Joyous. "+CAP(TO->QPRO)+" will protect the "+
	 "city at any cost.. even if that means "+TO->QPOS+" own life!\n");
    set_race("human");
    set_aggressive(0);
    set_level(20);
    set_dead_ob(TO);
    set_number_of_arms(2);
}
 
status monster_died(object ob) {
    object attacker;
    attacker = TO->query_attack();
    TOB("The guard drops dead on the floor, and you get a really "+
	"bad feeling over yourself..", attacker); 
    TOP(CAP(attacker->RNAME)+" murdered the guard.", attacker);
    call_other( HOME+"inherit/deed_area1", "add_deed", 
                                    ({ attacker->RNAME, "kills", "guard" }) );
    return 0;
}
 
int attack() {
    object attacker;
    if (::attack()) {
	attacker = TO->query_attack();
/*    	TOB("The guard says: 'You better stop or you will "+
	    "be thrown into jail!.", attacker); 
    	TOP("The guard is telling to "+CAP(attacker->RNAME)+" to get away "+
	    "from here or be thrown in jail!", attacker);
*/
        if( !present( "takeover", attacker ) )
            MOVE( CLONE( HOME+"inherit/takeover" ), attacker );
        return 1;
    }
    return 0;
}
