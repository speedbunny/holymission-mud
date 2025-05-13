inherit "/room/room";
#include "quest.h"

string *stones, *solution;
int i, j;
status lock, *c;

void make_solution();
status _turn( string str );
status _push( string str );
status _dump();
int get_current();
void reset_lock();

void reset( int arg ) {
    if( !arg ) {
	stones = ( { "diamond", "sapphire", "onyx", "ruby", "emerald" } );
	solution = allocate( 5 );
	c = allocate( 5 );
	make_solution();
	set_light( -4 );
	short_desc = "A strange door";
	long_desc = 
	"The cave ends here at a rather unique door.  \
There is a doorknob in the center of the door.  \
Surrounding the doorknob in a perfect pentagram are \
five gemstones.  One white, one blue, one black, one red, \
and one green.\n";
	dest_dir = ( {
	      ROOM + "1", "west",
	  } );
	items = ( {
	      "cave", "A dark natural cave",
	      "door", "A very strange door with a five gemstone lock",
	      "doorknob", "The doorknob is between five gemstones",
	      "pentagram", "The gemstones are in a pentagram shape",
	      "gemstone", "There are five of them",
	      "gemstones", "There are five of them",
	      "white gemstone", "This is an excellent diamond",
	      "blue gemstone", "This is a large sapphire",
	      "black gemstone", "This is a huge onyx",
	      "red gemstone", "This one is a flaming ruby",
	      "green gemstone", "This one is a bright emerald",
	      "diamond", "The diamond is at the top of the pentagram",
	      "sapphire", "The sapphire is the right point of the pentagram",
	      "onyx", "The onyx is at the lower right point of the pentagram",
	      "ruby", "The ruby is at the lower left point of the pentagram",
	      "emerald", "The emerald is the left point of the pentagram",
	  } );
	smell = "You smell dust and mold.";
    }
    ::reset( arg );
}

void make_solution() {
    i = 0;
    while( i < 5 ) {
	j = random( 5 );
	solution[i] = stones[j];
	c[i] = 0;
	i++;
    }
    lock = 1;
}

void init() {
    ::init();
    add_action( "_turn", "turn" );
    add_action( "_push", "push" );
    add_action( "_push", "press" );
    add_action( "_push", "touch" );
    add_action( "_dump", "dump" );
}

status _dump() {
    i = 0;
    while( i < 5 ) {
	printf( "%d %s\n", i, solution[i] );
	i++;
    }
    return ( 1 );
}

status _turn( string str ) {
    if( str != "doorknob" )
	return ( 0 );
    if( lock ) {
	write( "You try to turn the doorknob, but it will not budge!\n" );
	say( this_player()->query_name() + 
	  " tried to turn the doorknob.\n", this_player() );
	return ( 1 );
    }
    write( "Door opens...DEBUG purposes\n" );
    return ( 1 );
}

int get_current() {
    i = 0;
    j = 0;
    while( i < 5 ) {
	if( c[i] )
	    j++;
	else
	    break;
	i++;
    }
    return ( j );
}

void reset_lock() {
    i = 0;
    while( i < 5 ) {
	c[i] = 0;
	i++;
    }
}

status _push( string str ) {
    string verb;

    verb = query_verb();
    if( !str ) {
	printf( "%s what?\n", capitalize( verb ) );
	return ( 1 );
    }
    i = get_current();
    switch( str ) {
    case "white gemstone":
	str = "diamond";
	break;
    case "blue gemstone":
	str = "sapphire";
	break;
    case "black gemstone":
	str = "onyx";
	break;
    case "red gemstone":
	str = "ruby";
	break;
    case "green gemstone":
	str = "emerald";
	break;
    case "diamond":
    case "sapphire":
    case "onyx":
    case "ruby":
    case "emerald":
	break;
    default:
	printf( "%s what?\n", capitalize( verb ) );
	return ( 1 );
    }
    printf( "You %s the %s.\n", verb, str );
    return ( 1 );
}
