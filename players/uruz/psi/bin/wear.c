#include "/players/trout/psi/psi.h"

main( string str){
   object armour;
	armour=present(str, TP());
	if(!str){
	    write("Wear what?\n");
	    return 1;
	    }
	if(armour->query_weight() > 3){
	    write("You can't wear armour that heavy!\n");
	    return 1;
	    }
	}
