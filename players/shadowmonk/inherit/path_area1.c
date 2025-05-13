inherit "/room/room";
inherit "/players/shadowmonk/inherit/path_daemon";
#include "/players/shadowmonk/include/defs_area1.h"

#define PATHLOG "/players/shadowmonk/etc/valleypath.log"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_light(1);
    short_desc= 
	"Path object.";
    long_desc= 
	"Path object.\n"+
	"command: 'spath', 'smap'.\n";
    add_path( PATHLOG );
    add_pathvars( ({
	PATH+"valley/vl4_8", PATH+"valley/mmT", 7, 7, ({}), ({}),
	PATH+"valley/nwT", PATH+"valley/mmT", 9, 9, ({}), ({}),
	PATH+"valley/neT", PATH+"valley/mmT", 9, 9, ({}), ({}),
	PATH+"valley/seT", PATH+"valley/mmT", 9, 9, ({}), ({}),
	PATH+"valley/swT", PATH+"valley/mmT", 9, 9, ({}), ({}),
    }) );
}

void init() {
    if (!TP->query_immortal()) {
	move_object( TP, "/room/church" );
	return;
    }
    ::init();
    add_action( "show_path",  "spath"  );
    add_action( "show_map",   "smap"  );
}

status show_path() {
    int     i, sz;
    if(!check())
	return 1;
    path=({});
    path+=explode(read_file(pathlog), " ");
    for( i=0, sz=sizeof(path); i<sz; i++ ) 
	TAL( path[i] );
    TAL( (string)sizeof(path) );
    return 1;
}

status show_map() {
    int	    x, y;
    string *r_path;

    if(!check())
	return 1;
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
