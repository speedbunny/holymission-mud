#include "/players/shadowmonk/include/defs_area1.h"
#include "/players/shadowmonk/area1/items/quests.h"

init() { 
    add_action("read", "read"); 
}

id(str) { 
    return (str == "scroll"); 
}

short() { 
    return "A scroll with silver writing."; 
}

long() {
    TTP("The scroll is made out of somekind of parchment. You see some "+
	"text on it and a sheme. Must be the puzzle that the silver "+
	"dragon gave to you.");
}

get(str) { 
    return 1; 
}

query_value() { 
    return 0; 
}

drop() {
    if(query_verb()=="give") {
        TTP("You cannot give a personal quest to someone else!");
        return 1;
    }
  call_out("dest", 1, 0);
  return 0;
}

dest() {
    TAL("You drop the scroll, and it disappears into silver smoke.");
    destruct( TO );
}

read(str) {
    int i, sz;
    mixed *qlist;
    if( str!="scroll" )
	return 0;
    qlist=QUESTS;
    TTP( (string)qlist[0] + "\n" );
    for( i=0, sz=sizeof(qlist[1]); i<sz; i++ )
	TTP( (string)qlist[1][i] + "\n" );
    TTP( " ==============================================" );
    printf("| %-13s | %-13s | %-13s|\n",qlist[2][0],qlist[2][1],qlist[2][2]);
    TTP( " ==============================================" );
    for( i=0; i<3; i++ )
        printf("| %-13s | %-13s | %-13s|\n", qlist[3][i], qlist[4][i], 
  						   	       qlist[5][i]);
    TTP( "|---------------+---------------+--------------|" );
    for( i=0; i<3; i++ )
        printf("| %-13s | %-13s | %-13s|\n", qlist[6][i], qlist[7][i], 
  						   	       qlist[8][i]);
    TTP( "|---------------+---------------+--------------|" );
    for( i=0; i<3; i++ )
        printf("| %-13s | %-13s | %-13s|\n", qlist[9][i], qlist[10][i], 
  						   	      qlist[11][i]);
    TTP( " ==============================================" );
    TOP( TPCN + " reads the puzzle given by Xanchronas.", TP );
    return 1;
}
