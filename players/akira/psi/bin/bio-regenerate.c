#include "/players/akira/psi/psi.h"
#define REGEN_LVL 10

main(){
    int REGEN_COST, HEAL;
    REGEN_COST= (TPQL+TP()->query_int());
    HEAL= REGEN_COST * 2;
    if(check_level(REGEN_LVL)){ return 1;}
    if(check_cost(REGEN_COST)){ return 1;}
    if(check_armour()){ return 1;}
    check_bleed();
    if(check_block(target)){ return 1;}
    write("You concentrate your energies on healing your wounds.\n");
    TP()->heal_self(HEAL);
    TPRSP(-HEAL);
    TPRSP(-REGEN_COST);
    return 1;
}
