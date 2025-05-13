inherit "obj/thing";
#include "/players/shadowmonk/include/defs_area1.h"

#define PATHLOG "/players/shadowmonk/etc/path.log"

string *savepath;

void reset(int arg) {
    ::reset(arg);
    if (arg) return 0;

    set_name
	("direction ball");
    set_alias
	("ball");
    set_short
	("A Direction Ball"); 
    set_long
	("This is a round direction ball. It is slightly cloudy.\n");
    set_weight(2);
    set_value(900);
    set_can_get(1);
}

void init() {
    int   i;

    savepath=({});
    if(file_size(PATHLOG)>0) 
        savepath+=explode(read_file(PATHLOG), " ");
    ::init();
    add_action( "peer", "peer" );
    add_action( "pr", "pr" );
    add_action( "show_path", "spath" );
}

status query_valid(string room) {
    if(!room || member_array( room, savepath ) == -1 ) 
	return 0;
    return 1;
}

status peer(string dir) {
    string *exits;
    int	    index;
    if(!dir) {
	TTP("Peer to what direction..?");
	return 1;
    }
    exits=({});
    exits = call_other(file_name(ENV(TP)), "query_dest_dirs");
    if(!exits || ( index = member_array(dir, exits) ) == -1) {
	TTP("That is not a valid direction..");
	return 1;
    }
    if( !query_valid(exits[index-1]) ) {
        TTP("That direction is not save at all..");
    }
    else TTP("That direction is save..");
    return 1;
}

status pr() {
    string *exits;
    int	    i;
    exits=({});
    exits = call_other(file_name(ENV(TP)), "query_dest_dirs");
    if(!exits)
	TTP("There are no exits here..");
    for( i=0; i<sizeof(exits); i+=2 ) {
	if( !query_valid(exits[i]) ) {
            TTP("Direction "+exits[i+1]+" is not save at all..");
    	}
	else TTP("Direction "+exits[i+1]+" is save..");
    }
    return 1;
}

status show_path() {
    int    i, x, y;
    string str;
    for( i=0; i<sizeof(savepath); i++ ) 
	TTP( savepath[i] );
    TTP( (string)sizeof(savepath) );
    for( x=0; x<=9; x++ ) {
	for( y=0; y<=9; y++ ) {
	    if( member_array( PATH+"valley/vl"+x+"_"+y, savepath ) == -1)
		write( " u" );
	    else write( " S" );
	}
	write("\n");
    } 
    return 1;
}
