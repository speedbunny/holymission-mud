inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"
#define PATHLOG "/players/shadowmonk/etc/path.log"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc =
	"Somewhere in this weird valley.";
}

void init() {
    if( member_array( "/"+file_name(TO), 
		explode(read_file(PATHLOG), " ") ) == -1 ) {
	TAL("This is an unsafe room!");
	// return;
    }
    ::init();
    add_action( "show_map", "smap" );
}

string get_desc() {
    return call_other("/players/shadowmonk/inherit/desc_area1",
						"longdesc", file_name(TO)); 
}

status show_map() {
    int	    x, y;
    string *r_path;

    r_path=({});
    r_path+=explode(read_file(PATHLOG), " ");
    for( y=0; y<9; y++ ) {
	for( x=0; x<9; x++ ) 
            switch(y*10+x) {
		case 0 :
		    TALN( " NWT" );
		    break;
		case 8 :
		    TALN( " NET" );
		    break;
		case 44 :
		    TALN( " MMT" );
		    break;
		case 80 :
		    TALN( " SWT" );
		    break;
		case 88 :
		    TALN( " SET" );
		    break;
		default :
    	    	    if(member_array(PATH+"valley/vl"+x+"_"+y,r_path)==-1)
		       TALN( "  u " );
	    	    else TALN( "  S " );
		    break;
	    }
	TALN("\n");
    } 
    return 1;
}
