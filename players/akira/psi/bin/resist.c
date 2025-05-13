#include "/players/akira/psi/psi.h"
#include "/spells/spell.h"
#define FIRE_LVL 5
#define COLD_LVL 8
#define POISON_LVL 11
#define ACID_LVL 18
#define ELECTRICITY_LVL 22
#define ENERGY_LVL 22
#define COST 90

main (string str){
   int time;
   object shad;
	time=120 + ((TPQL/5)*30) + ((TPQLL/2)*30);
	if(!str){
	    write("Resist what?\n");
	    return 1;
	    }
	if(check_block()){ return 1;}
	check_bleed();
	if(str=="fire"){
	     if(check_level(FIRE_LVL)){ return 1;}
	     shad= CO("/obj/shadows/resist_fire_shad");
	      shad->start_shadow(TP(), time, "resist_fire_shad");
	      }
	if(str=="cold"){
	    if(check_level(COLD_LVL)){ return 1;}
	    shad= CO("/obj/shadows/resist_cold_shad");
	    shad->start_shadow(TP(), time, "resist_cold_shad");
	    }
	if(str=="poison"){
	    if(check_level(POISON_LVL)){ return 1;}
	    shad= CO("/obj/shadows/resist_poison_shad");
	    shad->start_shadow(TP(), time, "resist_poison_shad");
	    }
	if(str=="acid"){
	    if(check_level(ACID_LVL)){ return 1;}
	    shad= CO("/obj/shadows/resist_acid_shad");
	    shad->start_shadow(TP(), time, "resist_acid_shad");
	    }
	if(str=="electricity"){
	    if(check_level(ELECTRICITY_LVL)){ return 1;}
	    shad= CO("/obj/shadows/resist_elect_shad");
	    shad->start_shadow(TP(), time, "resist_elect_shad");
	    }
	if(str=="energy"){
	    if(check_level(ENERGY_LVL)){ return 1;}
	    shad= CO(YY+"/psi/shadows/resist_energy_shad");
	    shad->start_shadow(TP(), time, "resist_energy_shad");
	    }
	write("You focus your thoughts on resisting "+str+".\n");
	TPRSP(-COST);
	return 1;
	}
