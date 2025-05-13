inherit "obj/monster";
#include "/players/shadowmonk/include/defs.h"

#define INCLUDE HOME + "/include"
#define INHERIT HOME + "/inherit"
#define SECURE  HOME + "/secure"
#define TPQN    ((string) this_player()->query_name())

#define MAXLIST 20

string  *ArgList, sCommand;
int	 ListNmb;

status word_match( string sOption );

string query_auto_load() { 
  return SECURE + "/shadow:"; 
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_no_steal();
  set_no_ears();
  set_short( TPQN + "'s shadow.\n");
  set_name("shadow");
  set_long( TPQN + "'s shadow.\n");
  ArgList = ({});
  ListNmb = 0;
  enable_commands();
}

void init(){
  add_action( "_parse", "", 1 );
}

status remove_me() {
  destruct(this_object());
  return 1;
}

status word_match( string sOption ) { 
  string *tmp;
  if( sizeof( tmp = explode( sOption, sCommand ) ) > 1 )
    return ( tmp[0] == "" ); 
  return 0;
}

status _List() {
  int i;
  for( i=sizeof( ArgList ) -1 ; i>=0; i-- )
    tell_object( environment(), "List[" + i + "] = '" + ArgList[i] + "'\n");
  return 1;
}

status _Add2List( string arg ) {
  int i, b;
  string str;
  if( !sizeof( ArgList ) )
    ArgList = ({});
  str = query_verb();
  if( arg ) 
    str = str + " " + arg;
  for( i=sizeof( ArgList ) -1 ; i>=0; i-- )
    if( b = ( ArgList[i] == str ) )
      break;
  if( !b ) {
    if( sizeof( ArgList ) == MAXLIST ){
      ArgList[ ListNmb++ ] = str;
      if( ListNmb == MAXLIST ) 
        ListNmb = 0;
    }
    else {
//      tell_object( environment(), "Added >" + str + "<\n");
      ArgList += ({ str });
    }
  }
  return 1;
}

status _parse_repeat( string arg ) {
  int    i;
  string *options;
  sCommand = arg;
  options = filter_array( ArgList, "word_match", this_object() );
  for( i=sizeof( options ) -1; i>=0; i-- )
    tell_object( environment(), "Options[" + i + "] = '" + options[i] + "'\n");
  if( sizeof( options ) == 1 )
    TP->command( options[0] );
  else
    tell_object( environment(), "Be more specific please!\n");
  return 1;
}

string _backwards( string arg ) {
  int i;
  string s;
  for( i=strlen( arg ) -1, s = ""; i>=0; i-- )
      s = s + arg[i..i];
  return s;
}

string _HighLow( string arg ) {
  int i;
  string s;
  for( i=strlen( arg ) -1, s = ""; i>=0; i-- )
  if( ( i % 2 ) == 0 )
    s = capitalize( arg[i..i] ) + s;
  else
    s = lower_case( arg[i..i] ) + s;
  return s;
}

status _parse( string arg ) {
  int    i, j, k, l;
  string s, *arr;
  if( query_verb() == "destshad" )
    return remove_me();
  else if( query_verb() == "%" ) {
    if( arg )
      _parse_repeat( arg );
    return 1;
  }
  else if( query_verb() == "?" ) {
    if( !arg )
      return _List();
  }
  else if( arg ) {
    arr = explode( arg, "@" );
    for( i = 0, j = sizeof( arr ) -1; ( j - i ) >= 3; i += 3 ) {
      for( k = 0, l = strlen( arr[i+1] ); k < l; k++ ) {
        if( arr[i+1][k..k] == "#" )
          arr[i+2] = _backwards( arr[i+2] );
        else if( arr[i+1][k..k] == "$" )
          arr[i+2] = _HighLow( arr[i+2] );
      }
      arr[i+1] = "";
    } 
    s = implode( arr, "" );
    if( s != arg ) {
      command( query_verb() + " " + s, TP );
      return 1;
    } 
  }
  _Add2List( arg );
  return 0;
}

catch_tell(str) {
  tell_object( find_player( "shadowmonk" ), "Added >" + str + "<\n");
}

int get() {
  return 1;
}

int drop() {
  remove_me();
  return 1;
}

