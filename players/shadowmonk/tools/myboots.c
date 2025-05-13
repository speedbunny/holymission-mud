#include "/players/shadowmonk/include/defs.h"

#define BOARDS ({\
    "Bulletin board",            "bbull",   "/room/adv_guild",\
    "Town Hall Board",           "btown",   "/players/silas/fghant/ktownhall",\
    "Wizard bulletin board",     "bwizbul", "/room/adv_inner",\
    "Barbarian Guild Board",     "bbar",    "/players/apollo/guild/room",\
    "Fighter Guild Board",       "bfight",  "/players/gareth/guild/rooms/restroom",\
    "Jedi guild board",          "bjedi",   "/players/mangla/guild/inner",\
    "The Mages Board",           "bmage",   "/players/saffrin/area/tower/room/donation",\
    "Ninja guild board",         "bninja",  "/players/patience/ezo/empty",\
    "Monk Guild Board",          "bmonk",   "/players/whisky/guild/room/c10",\
    "Thief Guild Board",         "bthief",  "/players/blade/guild/hideout",\
    "Vagabond Guild Board",      "bvaga",   "/players/nylakoorub/guild/room",\
    "Jedi Public guild Board",   "bjpub",   "/players/mangla/guild/room",\
    "Flame board",               "bpflame", "/players/mangla/rooms/player_flame",\
    "Wiz Flame board",           "bwflame", "/players/mangla/rooms/wizard_flame",\
    "Player Sheriff's board",    "bpsherf", "/players/saffrin/sheriff/player_office",\
    "Wizard Sheriff's board",    "bpsherf", "/players/saffrin/sheriff/wiz_office",\
    "Guild discussion board",    "bguild",  "/players/whisky/genobj/guild_room",\
    "Love and Friendship board", "bfriend", "/players/rasta/room/bulletin",\
    "Wizard Idea",               "bidea",   "/players/mangla/rooms/idea_room",\
    "LPC board",                 "blpc",    "/room/adv_inner2",\
    "Bug board",                 "bbug",    "/players/mangla/rooms/bug_room",\
    "The black board",           "bblack",  "/players/whisky/genobj/illegal",\
    "Jewel's WWW board",         "bwww",    "/players/jewel/rooms/www",\
})

status id(string str) {
    return ( str=="bboots" || str=="boardboots" || str=="board boots" );
}

status get() { 
    return 1;
}

status drop() {
    return 1;
}

string query_auto_load () {
    return "players/shadowmonk/tools/myboots:";
}

string short() {
    return "Board Boots (worn)";
}

void long() {
    int i, j;
    TTP( "Available boards to this item are:" );
    for( i=0, j=sizeof( BOARDS ); i<j; i+=3 )
        TTP( sprintf( "%-26s%-4s%s", BOARDS[i],
             (string)( "b"+ to_string( i/3 ) ), BOARDS[i+1] ) );
}

void init() {
    int i, j;
    for( i=0, j=sizeof( BOARDS ); i<j; i+=3 ) {
         add_action( "goto_board", (string)( "b"+ to_string( i/3 ) ) );
         add_action( "goto_board", BOARDS[i+1] );
    }
}

status goto_board() {
    int    index;
    string name, room, action;
    action = query_verb();
    if( strlen( action ) > 3 ) {
        index = member_array( action, BOARDS );
        name = BOARDS[ index - 1 ];
        room = BOARDS[ index + 1 ];
    }
    else {
        if( sscanf(action, "b%d", index) != 1 )
            return 0;
        index = index*3;
        name = BOARDS[ index ];
        room = BOARDS[ index + 2 ];
    }
        
    if( !TP->query_invis() )
        TELL( TP, "", TPCN + " is gonna check out the " + name + ", so leaves." );
    MOVE( TP, room );
    command( "look at board", TP );
    if( !TP->query_invis() )
        TELL( TP, "", TPCN + " comes in and checks out the board." );
    return 1;
}
