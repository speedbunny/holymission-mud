#include "/players/shadowmonk/include/defs.h"
#include "/obj/setlight.h"

string items;  
string beer_type; 
string short_desc; 
string long_desc; 
string base_dir; 
string empty_desc; 
string empty_short; 
string drink_msg; 
status empty;

id(str) {
    int i, sz;
    if( !inside( TP ) ) 
	return str=="beer" || str=="bottle";
    if( !items ) 
	return 0;
    i=0;
    sz=sizeof(items);
    while( i<sz ) {
        if( items[i]==str ) 
	    return 1;
        i+=2;
    }
    return 0;
}

long(str) {
    int i, sz;
    if( !inside( TP ) ) {
    	if(!empty) {
       	    TTP("A bottle of "+beer_type+" beer.");
       	    if( first_inventory( TO ) )
         	TTP("There's is somebody or something floating in it.");
            return;
        }
        else {
       	    TTP("An empty Heineken bottle.");
            if( first_inventory( TO ) )
         	TTP("There's is somebody or something in it.");
            return;
        }
    }
    if( TP->test_darkness() ) {
        TTP("It is too dark.");
        return;
    }
    if( !str ) {
        if(empty) 
	    TTP(empty_desc);
        else
	    TTP(long_desc);
        return;
    }
    if( !items ) 
	return;
    i=0;
    sz=sizeof( items );
    while( i<sz ) {
        if( items[i]==str ) {
       	    TTP(items[i+1]+".");
            return;
        }
        i+=2;
    }
}

short() {
    if( !inside( TP ) ) {
        if( !empty ) 
	    return "A bottle of Heineken beer";
        else       
	    return "An empty Heineken bottle";
    }
    if( !TP->test_darkness() ) {
        if( !empty ) 
	    return short_desc;
        else 
	    return empty_short;
    }
    return "Dark room";
}

inside(what) {
    if( present( what, TO ) ) 
	return 1;
    return 0;
}

query_long() { 
    return long_desc; 
}
query_value() { 
    if( !empty ) 
	return 12; 
    else 
	return 10; 
}
query_weight() { 
    return 1; 
}
query_drop_castle() { 
    return 0; 
}

reset(arg) {
    if(arg) return;

    set_light(1);
    empty=0;
    beer_type = 
	"dutch Heineken";
    drink_msg = 
	"You always liked the taste of "+beer_type+" beer";
    short_desc = 
	"A bottle of Heineken";
    empty_short = 
	"An empty Heineken bottle";
    long_desc = 
	"You're floating in a bottle full of "+beer_type+" beer.\n"+
        "The glass breaks the view from the outside.\n"+
        "You think it is possible to climb out.\n";
    empty_desc = 
	"You're standing on the bottom of an empty bottle.\n"+
        "You'd better refill it somewhere.\n";
    items = ({
	"bottle",
	    "a bottle of beer",
	"glass",
	    "the glass of the bottle",
        "view",
	    "the glass blurrs the view",
    });
    base_dir="/players/shadowmonk/secure/workroom2";
// if(!base_dir) base_dir="/players/shadowmonk/secure/workroom2";
    move_object( TO, base_dir );
}

can_put_and_get() {
    if( !inside( TP ) ) 
	return 1;
    return 0;
}

get() { 
    return 1; 
}

drop() { 
    return 0; 
}

init() {
    add_action("climb","climb");
    add_action("enter","enter");
    add_action("drink_me","drink");
}

climb(arg) {
    object obt;
    if( !inside( TP ) ) 
	return 0;
    if( arg!="out" ) {
        notify_fail("Climb where?\n");
        return 0;
    }
    if( (obt=ENV( TO ) )!=0) 
	move_object( TO, ENV( obt ) );
    TOP( TPCN+" climbs out of the bottle.", TP );
    tell_room( ENV( TO ), TPCN +" comes climbing out of the bottle.");
    move_object( TP, ENV( TO ) );
    TP->look();
    return 1;
}

enter(arg) {
    if( present( TO, TP ) ) 
	return 0;
    if( arg=="bottle" ) {
//      if( !TP->query_immortal() ) {
//          notify_fail( "Sorry... but u are just too young to climb in "+
//			 "beer bottles!\n");
//          return 0;
//      }
        TOP( TPCN+" leaves climbing into the bottle.", TP );
        tell_room( TO, TPCN +" comes falling in.");
        move_object( TP, TO );
        this_player()->look();
        return 1;
    }
}

drink_me(arg) {
    if( arg && arg!="beer" && arg!="from bottle" ) 
	return 0;
    if(empty) 
	return 0;
    if( !inside( TP ) ) {
        if( !TP->drink_alcohol(2) ) 
	    return 1;
        TTP(drink_msg+".");
        TOP( TPCN+" drinks a bottle of beer.", TP );
        tell_room( TO, "Suddenly "+ TPCN +" drinks the bottle, and you "+
			"are almost swallowed.\nLuckily you got stuck in "+
			"the bottle!\n");
        empty=!empty;
        return 1;
    }
    TTP("You take a deep dive in the beer and swallow a mouthfull of beer "+
	"You don't think you will empty it this way before the reboot.");
    TOP( TPCN+" swallows a mouthfull of beer.", TP );
    tell_room( ENV( TO ), "You think you hear a faint SSlllurp from the "+
			  "bottle, but you could be imagining.\n");
    TP->add_intoxination(2);
    return 1;
}

int test_darkness() {
    if( TP && TP->infravision() ) 
	return 1;
    return set_light(0);
}

int test_dark() {
    return set_light(0);
}
