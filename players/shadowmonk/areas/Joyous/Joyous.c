inherit "/room/room";
#include "/players/shadowmonk/areas/Joyous/defs.h"

static string *visible_items;
static string *surrounding_items;
string *query_visible_items();
string *query_surrounding_items();

void reset( int arg ){
  ::reset( arg );
  visible_items = ({});
  surrounding_items = ({});
}

void init() {
int i;
  ::init();
  add_action( "_List", "tt" );
}

string *query_visible_items(){
  return visible_items;
}

string *query_surrounding_items(){
  return surrounding_items;
}

status _List() {
  int i;
  string *s;
  for( i=sizeof( s = query_visible_items() ) -1 ; i>=0; i-- )
    TME( "visible[" + i + "] = '" + s[i] + "'\n");
  for( i=sizeof( s = query_surrounding_items() ) -1 ; i>=0; i-- )
    TME( "surrounding[" + i + "] = '" + s[i] + "'\n");
  return 1;
}
