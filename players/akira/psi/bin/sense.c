#include "/players/akira/psi/psi.h"
#define SENSE_LVL 3
#define SENSE_COST 35

main (string str){
   object *ob;
   int i, j, k;

	if(!str){
	    write("Useage: sense invisible\n");
	    return 1;
	    }
	if(str!="invisible"){
	    write("Useage: sense invisible\n");
	    return 1;
	    }
	if(check_level(SENSE_LVL)){ return 1;}
	str= TPRN;
	if(check_cost(SENSE_COST)){ return 1;}
	if(check_block(str)){ return 1;}
	check_bleed();
	ob= all_inventory(ENV(TP()));
	j= sizeof(ob);
	k=0;
	for(i=0; i<j; i++){
	    if(ob[i]->query_invis()){
		k= k+1;
		}
	    }
	switch(k){
	    case 0: 
	  	    write("You do not sense any invisible beings.\n");
		    break;
	    case 1:
		    write("You sense the presense of one invisible being.\n");
		    break;
	    case 2..4: write("You sense the presense of a few invisible "+
		       "beings.\n");
	    case 5..100: write("You sense the presense of many invisible "+
			 "beings\n");
	    		 break;
	    }
	TPRSP(-SENSE_COST);
	return 1;
	}
