inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"
#define VALLEY	"T 1 2 2 2 2 2 1 T "+ \
		"1 1 2 2 2 2 2 1 1 "+ \
		"2 2 2 2 2 2 2 2 2 "+ \
		"2 2 2 3 4 3 2 2 2 "+ \
		"2 2 2 4 4 4 3 2 2 "+ \
		"2 2 2 3 4 3 2 2 2 "+ \
		"2 2 2 2 2 2 2 2 2 "+ \
		"1 1 2 2 2 2 2 1 1 "+ \
		"T 1 2 2 2 2 2 1 T"
#define N "north"
#define E "east"
#define S "south"
#define W "west"
#define NE N+E
#define SE S+E
#define SW S+W
#define NW N+W
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc =
	".";
    long_desc  = 	
	".\n";
}

void init() {
    ::init();
    add_action("longdesc", "test");
}

string *tdirs(int x, int y) {
    switch(y) {
	case 0 : 
	    switch(x) {
		case 0..5:	return ({ W, E, SW, SE }); break;
		case 6..8:	return ({ E, W, SE, SW }); break;
	    }
	case 1 : 
	    switch(x) {
		case 0   :	return ({ N, S, NE, SE }); break;
		case 1   :	return ({ NW, SW, NE, SE }); break;
		case 2..4:	return ({ NW, NE, SW, SE }); break;
		case 5..6:	return ({ NE, NW, SE, SW }); break;
		case 7   :	return ({ NE, SE, NW, SW }); break;
		case 8   :	return ({ N, S, SW, NW }); break;
	    }
	case 2 : 
	    switch(x) {
		case 0   :	return ({ N, S, NE, SE }); break;
		case 1..2:	return ({ NW, SW, NE, SE }); break;
		case 3..4:	return ({ NW, NE, SW, SE }); break;
		case 5   :	return ({ NE, NW, SE, SW }); break;
		case 6..7:	return ({ NE, SE, NW, SW }); break;
		case 8   :	return ({ N, S, SW, NW }); break;
	    }
	case 3 : 
	    switch(x) {
		case 0   :	return ({ N, S, NE, SE }); break;
		case 1..3:	return ({ NW, SW, NE, SE }); break;
		case 4   :	return ({ NW, NE, SW, SE }); break;
		case 5..7:	return ({ NE, SE, NW, SW }); break;
		case 8   :	return ({ N, S, SW, NW }); break;
	    }
	case 4 : 
	    switch(x) {
		case 0   :	return ({ N, S, NE, SE }); break;
		case 1..4:	return ({ NW, SW, NE, SE }); break;
		case 5..7:	return ({ NE, SE, NW, SW }); break;
		case 8   :	return ({ N, S, SW, NW }); break;
	    }
	case 5 : 
	    switch(x) {
		case 0   :	return ({ S, N, SE, NE }); break;
		case 1..3:	return ({ SW, NW, SE, NE }); break;
		case 4   :	return ({ SW, SE, NW, NE }); break;
		case 5..7:	return ({ SE, NE, SW, NW }); break;
		case 8   :	return ({ S, N, SW, NW }); break;
	    }
	case 6 : 
	    switch(x) {
		case 0   :	return ({ S, N, SE, NE }); break;
		case 1..2:	return ({ SW, NW, SE, NE }); break;
		case 3..4:	return ({ SW, SE, NW, NE }); break;
		case 5   :	return ({ SE, SW, NE, NW }); break;
		case 6..7:	return ({ SE, NE, SW, NW }); break;
		case 8   :	return ({ S, N, SW, NW }); break;
	    }
	case 7 : 
	    switch(x) {
		case 0   :	return ({ S, N, SE, NE }); break;
		case 1   :	return ({ SW, NW, SE, NE }); break;
		case 2..4:	return ({ SW, SE, NW, NE }); break;
		case 5..6:	return ({ SE, SW, NE, NW }); break;
		case 7   :	return ({ SE, NE, SW, NW }); break;
		case 8   :	return ({ S, N, SW, NW }); break;
	    }
	case 8 : 
	    switch(x) {
		case 0..4:	return ({ W, E, NW, NE }); break;
		case 5..8:	return ({ E, W, NE, NW }); break;
	    }
    }
    return 0;
}

string longdesc(string filename) {
    int     x, y, towers;
    string  buildstr, *dirs;
    sscanf(filename, "%svl%d_%d", buildstr, x, y);
    switch(to_int(explode(VALLEY, " ")[y*9+x])) {
	case 1 :  
	    buildstr=	"You are very close to a tower which is to the "+ 
			tdirs(x,y)[0] +" of here. You now notice that the "+
			"front of the tower has been carved in the wall of "+
			"the cliffside. The entrance is a small arch at "+
			"the base of the tower. The ground is less cracked "+
			"here, and less light comes through now.\n";
	    break;
	case 2 :  
	    buildstr=	"There is a tower to the "+ tdirs(x,y)[0] +" of "+
			"here, and another one to the "+ tdirs(x,y)[1] +
			". The ground is very cracked, and red light light "+
			"poors through the cracks. Your view is blurred "+
			"in every direction, because of the heat that the "+
			"lava beneat you is sending up.\n";
 	    break;
	case 3 :  
	    buildstr=	"You are pretty much in the center of this weird "+
			"valley. It is terribly hot, as the magma under "+
			"you is heating the floor. The heat streams blur "+
			"your view but you see towers to the "+tdirs(x,y)[0]+
			", "+ tdirs(x,y)[0] +" and "+ tdirs(x,y)[0] +".\n";
	    break;
	default :
	    buildstr=	"You see towers to every direction, but the "+ 
			tdirs(x,y)[0] +	"ern and "+ tdirs(x,y)[0] +"ern "+
			"towers you can see best. You are at the center "+
			"of this valley, and the heat is almost unbareable."+
			" Your view is blurred by the heatflows, coming "+
			"through the cracks in the floor.\n";
	    break;
    }
    if( x==0 || x==8 || y==0 || y==8 )
        buildstr = "The valleys cliffside is very close to you. " + buildstr;
    return buildstr;
}
