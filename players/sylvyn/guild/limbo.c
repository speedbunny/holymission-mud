#include "/players/nylakoorub/guild/defines.h"
#define LIMBO  "/players/nylakoorub/guild/rooms/limbo/limbo.c"


do_limbo(arg) {
    int i,j;
    object obj;
    string type;
    object item;
    object limbo;
    limbo = find_object(LIMBO);

    if(!arg) {
	(LIMBO)->long();
	obj = all_inventory(limbo);
	j = sizeof(obj);
	if(!obj)
	{
	}
	else
	    for(i=0;i<j;i++) {
		if(obj[i]->short() && !obj[i]->query_living()) {
		    write(obj[i]->short());
		    if(i+1 == j ) {
			write(".\n");
		    } else {
			write(", ");
		    }
		}
	    }
	return 1;
    }
    if(arg) {
	sscanf(arg, "%s %s", type, item);
	if(!type || !item) {
	    write("Usage: limbo <store/get> <item>.\n");
	    return 1;
	}



	return 1;






    }

    return 1;
}

