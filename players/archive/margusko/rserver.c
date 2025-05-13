// Virtual Room Server


// Original development (c) Leslie@CoreDump 1995.7.9pm
// Version 3.0 by Leslie@CoreDump
// 
// PLEASE edit this code ONLY if you know what you are doing
// Thanx

#include "../params.h"
#define FNAME OD+"data"
#define query_cap_name query_name

string query_item(int cord, string str);
int where_to(int cord, int dir);
string short(int cord);
void long(int cord, string str);
varargs int spec_exit(int cord, string dir, string dest, int flag);
object query_room(int cord);
#ifdef ROAD
int road(int cord);
#endif
#ifdef CREEK
int creek(int cord);
#endif
#ifdef BUSH
int bush(int cord);
static int *bushes;
#endif
#ifdef ITEMS
mapping items;
#endif
#ifndef UNIQUE_TERRAIN
#endif
#ifdef INTERACTIVE_CREATE
int security_ok(object ob);
int set_road(int cord);
int set_bush(int cord, int type);
int set_creek(int cord);
int set_height(int cord, int x);
int set_desc(int cord, int desc);
int set_items(int cord, string str);
#endif
#ifdef LABYRINTH
int *lab_data;
#endif
int cord_int(int *x);
int *int_cord(int x);
int use_exit(int dir);

int ceiling;
int *tenser;
int *data;
static object *rooms;
#ifdef HEIGHTS
int *level;
#endif
string dfls;
int *descr;
mapping *items;
mapping specxit;
static int monster_amount, monster_killed;

int load_me() {
    return restore_object(FNAME);
}

void save_me() {
    save_object(FNAME);
}


int query_berries(int cord) {
    return bushes[cord];
}

void dec_berries(int cord) {
    bushes[cord]--;
}


set_specxit(int cord, string str) {
    string dir;
    string dest;

    if(sscanf(str, "%s:%s", dir, dest) != 2) dir = str;
    if(!specxit) specxit = ([]);
    if(!specxit[cord]) specxit[cord] = ([]);
    specxit[cord][dir] = dest;
    return 1;
}


int id(mixed cord, string str) {
    if(cord == "door") return 1; // this is stupid, but needed for follow
    if(!intp(cord)) 
	return 0;
    return !!query_item(cord, str);
}


string query_item(int cord, string str) {
    if((str == "road") && road(cord))
	return "Its a damn dusty road that you are walking on.";
    if(bush(cord))
	if((str == "bush") || (str == "bushes"))
	    return "Lovely bushes full of berries! Maybe you can pick few!";
    if((str == "creek") && creek(cord))
	return "A clear creek with fresh water.";
    return (
      items
      && items[(int)descr[cord]]
      && items[(int)descr[cord]][str]
    )? items[(int)descr[cord]][str] : 0;
}

int set_items(int cord, string str) {
    int dsc;
    string what;
    string how;

    dsc = descr[cord];
    if(!items) items = ({});
    while(sizeof(items)<(dsc+1)) items+= ({ ([]) });
    if(sscanf(str, "%s:%s", what, how) !=2) {
	m_delete(items[dsc], str);
	return 1;
    }
    items[dsc][what] = how;
    return 1;
}

#ifdef HEIGHTS
int set_height(int cord, int x) {
    if((cord < 0) || (cord >= ceiling))
	return 2;
    level[cord] = x;
    return 1;
}

int query_height(int cord) {
    return ((cord>0) && (cord<=ceiling))?level[cord]:0;
}
#endif


#ifdef ROAD
int road(int cord) {
    return data[cord] & 1;
}

int set_road(int cord) {
    if((cord < 0) || (cord >= ceiling))
	return 2;
    data[cord] ^= 1;
    return 1;
}
#endif

#ifdef CREEK
int creek(int cord) {
    return !!(data[cord] & 2);
}

int set_creek(int cord) {
    if((cord < 0) || (cord >= ceiling)) return 2;
    data[cord] ^= 2;
    return 1;
}
#endif

#ifdef BUSH
int bush(int cord) {
    if(data[cord] & 4) return 1;
    if(data[cord] & 8) return 2;
    return 0;
}

int set_bush(int cord, int type) {
    if((cord < 0) || (cord >= ceiling)) return 2;
    data[cord] &= ~12;
    if(type == 1) data[cord] |= 4;
    else if(type == 2) data[cord] |= 8;
    else return 2;
    return 1;
}
#endif

int abs(int i) { 
    return i>0 ? i : (-1*i);
}

#ifdef INTERACTIVE_CREATE
int set_desc(int cord, int value) {
    if((cord < 0) || (cord >= ceiling))
	return 2;
    descr[cord] = value;
    return 1;
}

int _set(string str) {
    string what;
    mixed value;
    int ret;
    object env;

    if(lower_case(this_player()->query_real_name()) != "leslie")
	return 0;
    if(sscanf(str, "%s %s", what, value) != 2)
	what = str;
    if(what != "items")
	sscanf(value, "%d", value);
    if(!(env = environment(this_player())))
	return 0;
    ret = (int) call_other(this_object(), "set_"+what, env->query_cord(), value);
    if(!ret) {
	notify_fail("You cannot set that!\n");
	return 0;
    }
    write("Tried to set: "+str+"\n");
    if(ret == 2)
	write("Failure due to bug!\n");
    say(this_player()->query_cap_name()+" sets "+str+".\n");
    save_me();
    return 1;
}
#endif


string short(int cord) {
    string ret;

    ret = SHORT;

#ifdef ROAD
    if(road(cord)) ret += " Road.";
#endif

#ifdef BUSH
    if(bush(cord)) ret += " Bushes.";
#endif

#ifdef CREEK
    if(creek(cord)) ret += " Creek.";
#endif

    return ret;
}

void long(int cord, string str) {
    int i, j;
    string *roaders;

    write(WHT);
    if(str) {
	write(query_item(cord, str)+"\n");
	return;
    }

    if(this_player()->query_immortal()) {
	write("Coord: ");
	write(cord);
	write(", Height:");
	write(level[cord]);
	write("\n");
    }
    write(read_file(RD+dfls+descr[cord])[0..<2]);
#ifdef CREEK
if(creek(cord)) write(" A little creek flows through the area.");
#endif
#ifdef BUSH
    if(bush(cord)) write(" There are some bushes around.");
#endif
#ifdef ROAD
    if(road(cord)) {
	write(" You are walking on a road.");
	write("\n");
	roaders = ({});
	i = sizeof(XITS);
	while(i--)
	    if(((j = where_to(cord, i)) >-1) && road(j))
		roaders += ({ XITS[i] });
	if(sizeof(roaders) == 0)
	    write("There is road here, but it leads nowhere.");
	else if(sizeof(roaders) == 1)
	    write("A road starts here, and leads "+roaders[0]+".");
	else if(sizeof(roaders) == 2)
	    write("The road comes from "+roaders[0]+" and leads "
	      +roaders[1]+".");
	else {
	    write("The road forks in "+(i = sizeof(roaders))
	      +" directions: ");
	    while(i--) {
		write(roaders[i]);
		if(!i) write(".");
		else write(", ");
	    }
	}
    }
#endif
    roaders = ({});
    i = sizeof(XITS);
    while(i--)
	if(((j = where_to(cord, i)) > -1)
#ifdef HEIGHTS
	  && (abs(level[cord] - level[j]) <= MAX_LVL_DIFF)
#endif
#ifdef LABYRINTH
	  && (lab_data[cord] & (1<<i))
#endif
	)
	    roaders += ({ XITS[i] });
    if(specxit && mappingp(specxit) && specxit[cord] &&
      mappingp(specxit[cord]))
	roaders += m_indices(specxit[cord]);
    write("\n\n");
    if(!sizeof(roaders))
	write("There are no exits.\n");
    else {
	write("Exits: ");
	i = sizeof(roaders);
	while(i--) {
	    write(roaders[i]);
	    if(!i) write(".\n");
	    else write(", ");
	}
    }
    write("\n");
}

void init_rooms() {
    int i;
    if(!rooms) {
	rooms = allocate(ceiling);
	return;
    }
    i = sizeof(rooms);
    while(i--)
	if(objectp(rooms[i]))
	    destruct(rooms[i]);
}

int *vect_div(int cord, int *arr) {
    int *ret;
    int i, a;
    ret = ({});
    i = sizeof(arr);
    while(i--) {
	a = (cord / arr[i]);
	ret = ({ a }) + ret;
	cord -= a*arr[i];
    }
    return ret;
}

int vect_skal(int *arr1, int *arr2) {
    int a, ret;
    a = sizeof(arr1);
    ret = 0;
    while(a--) ret += arr1[a]*arr2[a];
    return ret;
}

int *int_cord(int cord) {
    return vect_div(cord, tenser);
}

int cord_int(int *x) {
    return vect_skal(x, tenser);
}

void reset(int arg) {
    int i;
    monster_killed = 0;
    if(!bushes) {
	load_me();
	bushes = allocate(ceiling);
    }
    i = ceiling;
    while(i--)
	bushes[i] = 10+random(10);
    if(arg) return;
    load_me();
    init_rooms();
    monster_amount = 0;
}

void setup() {
    int i;
    ceiling = 1;
    i = DIM;
    while(i--) ceiling *= DMS[i];
    if(ceiling > 10000) return;
    tenser = ({ 1 });
    i = DIM;
    while(i--) tenser += ({ tenser[<1] * DMS[<(i+1)] });
    data = allocate(ceiling);
#ifdef LABYRINTH
    lab_data = allocate(ceiling);
#endif
#ifdef HEIGHTS
    level = allocate(ceiling);
#endif
    dfls = "for";
    descr = allocate(ceiling);
    init_rooms();
    save_me();
}

int where_to(int cord, int dir) {
    int direc, pol;
    int *temp;
#ifdef ALLEXIT
    if( (cord >= ceiling) || (dir > 8) ) return -1;
    temp = int_cord(cord);
    switch(dir) {
    case 0:
	temp[1]--;
	break;
    case 1:
	temp[1]++;
	break;
    case 2:
	temp[0]--;
	break;
    case 3:
	temp[0]++;
	break;
    case 4:
	temp[0]--;
	temp[1]--;
	break;
    case 7:
	temp[1]--;
	temp[0]++;
	break;
    case 6:
	temp[1]++;
	temp[0]--;
	break;
    case 5:
	temp[1]++;
	temp[0]++;
	break;
    default:
	return -1;
    }
    if((temp[0] < 0) || (temp[0] >= DMS[0]) ||
      (temp[1] < 0) || (temp[1] >=DMS[1]) )
	return -1;
    return cord_int(temp);
#else
    if( (cord > ceiling) || (dir > 2*DIM) )
	return -1;
    direc = dir >>1;
    pol = dir & 1;
    temp = int_cord(cord);
    if(pol) temp[direc]++;
    else temp[direc]--;
    if( (temp[direc] < 0) || (temp[direc] >=DMS[direc]) )
	return -1;
    return cord_int(temp);
#endif
}

object query_room(int cord) {
    object obj;
    object ob;
    if(rooms[cord]) return rooms[cord];
    ob = clone_object(RCL);
    ob ->set_cord(cord);
    if((monster_amount + monster_killed) < random(ceiling))
    {
	obj = clone_object(MD+MONSTERS[random(sizeof(MONSTERS))]);
	obj->set_die(this_object());
	move_object(obj, ob);
	monster_amount++;
    }
    rooms[cord] = ob;
    return ob;
}

int command_line(string str) {
    string verb, arg;
    int n;

    if(sscanf(str, "%s %s", verb, arg) != 2) verb = str;
    if(verb == "home") return 0;
    if(specxit && specxit[n = (int)(environment(this_player())
	  ->query_cord())] &&specxit[n][str])
	return !this_player()->move_player(str, specxit[n][str]);
    if((n = member_array(str, XITS)) != -1)
	return use_exit(n);
    if(file_size(BINDIR+verb+".c") < 0) return 0;
    return call_other(BINDIR+verb, "cmd_"+verb, arg);
}

int use_exit(int dir) {
    int dest;
    object dst;
    int envir;
    int i, j, k;
    object env;

    env = environment(this_player());
    envir = env->query_cord();
    dest = where_to(envir, dir);

    if(dest < 0) {
	write("You cannot go that way!\n");
	return 1;
    }

#ifdef HEIGHTS
    if(abs((i = level[envir] - level[dest])) > MAX_LVL_DIFF) {
	if(i>0) {
	    write("You try to climb down the hill, but you are"
	      " too scared.\n");
	    say(this_player()->query_cap_name()+
	      " tries to climb down the hill, but then fails.");
	    return 1;
	}
	else {
	    write("You try to climb up the hill, but fail.\n");
	    say(this_player()->query_cap_name()+
	      " tries to climb up the hill, but fails.\n");
	    return 1;
	}
    }

    if(i) {
	if(i>0) {
	    write("You climb down the hill.\n");
	    say(capitalize(this_player()->query_name())+
	      " climbs down the hill.\n");
	}
	else {
	    write("You climb up the hill.\n");
	    say(capitalize(this_player()->query_name())+
	      " climbs up the hill.\n");
	}
    }
#endif

    this_player()->move_player(XITS[dir], query_room(dest));
    if(env && !first_inventory(env))
	destruct(env);
    return 1;
}


#ifdef SPECIAL
#endif
string query_exits_info(int cord) {
    string ret;
    int i, j;
    ret = "";
    if(this_player()->query_immortal()){
	ret += "Info on the exits:\n";
	ret += "\n"+identify(rooms[cord])+"\n";
	ret += "Cord: "+cord;
	ret += "  Height: "+level[cord];
	ret += "  Description: "+descr[cord];
	ret += "\n";
    }
    for( i = 0; i < sizeof(XITS); i++ ) {
	ret += XITS[i];
	ret += " : ";
	if((j = where_to(cord, i)) == -1) {
	    ret += "It leads too deep into the forest. You wont be able to get there.\n";
	    continue;
	}
	else {
#ifdef LABYRINTH
	    if(lab_data[cord] & (1 << i)) {
		ret += "You wont be able to get there.\n";
		continue;
	    }
#endif
#ifdef HEIGHTS
	    if((level[cord] - level[j]) > MAX_LVL_DIFF) {
		ret += "You wont climb down that hill.\n";
		continue;
	    }
	    if((level[cord] - level[j]) < -MAX_LVL_DIFF) {
		ret += "You wont climb up that hill.\n";
		continue;
	    }
#endif
	}
	ret += short(j);
	ret += "\n";
    }
    return ret;
}
