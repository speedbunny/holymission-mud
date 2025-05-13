#include "/room/room_defs.h"

inherit "room/room";

object harry;

void start_harry();

void reset( int arg ) {
  ::reset( arg );
  start_harry();
  if( arg ) return;
  
  no_castle_flag = 1;
  set_light( 1 );
  short_desc = "Harry's house";
  long_desc = "This is the house of Harry the Affectionate. "
    + "Harry lives in a very cozy house. A green sofa with yellow flowered "
    + "cushions, a rocking chair and a simple wooden table stand in the "
    + "center of a clean wooden floor. A painting of a setting sun hangs "
    + "on the wall. A blue curtain hangs before the niche where Harry's bed "
    + "stands. A bright red door leads north to Oaks Lane.\n";
  dest_dir = ({ 
/*
    HM_VILLAGE + "lane2", "north", 
*/
    "/players/uglymouth/workroom", "north",
  });
  items = ({
    "house", "You can tell it's Harry's house: you feel at home right away",
    "sofa", "A simple beech wooden frame painted green with thick, "
      + "soft cushions in it",
    "cushions", "The flowers woven into them are somewhat old fashioned, "
      + "but they're the thickest, softest cushions you saw on any sofa",
    "chair", "I simple beech wooden rocking chair painted in the same green "
      + "as the sofa",
    "rocking chair", "I simple beech wooden rocking chair painted in the "
      + "same green as the sofa",
    "table", "A low oak table painted dark green. It has two one drawer",
    "drawer", 
      "It contains eating gear for two. Maybe Harry invites you someday",
    "painting", "It's a nice sunset. The painting is signed 'Harry'",
    "wall", "The walls have been painted in a cheerful yellow",
    "curtain", "A navy blue cotton curtain keeps out the earliest day light",
    "bed", "From what you can see in the narrow gap between the curtain and "
      + "the wall, it's a simple, but soft and warm bed",
    "door", "A sturdy rectangular oak door, painted bright red",
  });
}

void start_harry() {
  string *chat_str,  *a_chat_str;
  string *function, *type, *match;
  
  if( harry ) return;
  
  chat_str = allocate(10);
  a_chat_str = allocate(8);
    
  chat_str[0] = "Harry says: What are you waiting for?\n";
  chat_str[1] = "Harry says: Hello there!\n";
  chat_str[2] = "Harry says: I don't like winter.\n";
  chat_str[3] = "Harry says: I don't like snow.\n";
  chat_str[4] = "Harry says: I don't like rain.\n";
  chat_str[5] = "Harry says: Who are you?\n";
  chat_str[6] = "Harry says: Why do you look like that?\n";
  chat_str[7] = "Harry says: What are you doing here?\n";
  chat_str[8] = "Harry says: Nice weather, isn't it?\n";
  chat_str[9] = "Harry smiles.\n";
    
  a_chat_str[0] = "Harry says: Don't hit me!\n";
  a_chat_str[1] = "Harry says: That hurt!\n";
  a_chat_str[2] = "Harry says: Help, someone!\n";
  a_chat_str[3] = "Harry says: Why can't you go bullying elsewhere?\n";
  a_chat_str[4] = "Harry says: Aooooo\n";
  a_chat_str[5] = "Harry says: I hate bashers!\n";
  a_chat_str[6] = "Harry says: Bastard\n";
  a_chat_str[7] = "Harry says: You big brute!\n";
    
  function = allocate(12);
  type = allocate(12);
  match = allocate(12);

  function[0] = "why_did";
  type[0] = "sells";
  type[1] = "attack";
  type[2] = "left";
  match[2] = "the game";
  type[3] = "takes";
  type[4] = "drops";
  function[5] = "how_does_it_feel";
  type[5] = "is now level";
  function[6] = "smiles";
  type[6] = "smiles";
  match[6] = " happily.";
  function[7] = "say_hello";
  type[7] = "arrives";
  function[8] = "test_say";
  type[8] = "says:";
  type[9] = "tells you:";
  function[10] = "follow";
  type[10] = "leaves";
  function[11] = "gives";
  type[11] = "gives";

  harry = clone_object( "obj/monster" );
  harry->set_name( "harry" );
  harry->set_alias( "harry the affectionate" );
  harry->set_short( "Harry the affectionate" );
  harry->set_long( "Harry is a guy of undeterminable age. He has an "
    + "agreeable look. Harry is one of the well known residents of the "
    + "village and always in for an interesting conversation.\n" );
  harry->set_level( 3 );
  harry->set_race( "human" );
  harry->set_male();
  harry->set_size( 2 );
  harry->set_al( 60 );
  harry->set_ac( 0 );
  harry->set_wc( 5 );
  harry->set_ep( 2283 );
  harry->set_aggressive( 0 );
  harry->load_chat( 2, chat_str );
  harry->load_a_chat( 20, a_chat_str );
  harry->set_match( this_object(), function, type, match );
  harry->set_random_pick( 20 );
  harry->set_move_at_reset();
  tell_room( TO, "Harry has returned home.\n" );
  move_object( harry, this_object() );
}

void why_did( string str ) {
  string who, what, msg;
  
  sscanf( str, "%s %s", who, what );
  if( lower_case( who ) == "harry" ) return;
  if( sscanf( str, "%s sells %s.", who, what ) == 2 )
    msg = sprintf( "Harry says: Why did you sell %s?\n", what );
  else if( sscanf( str, "%s attacks %s.", who, what ) == 2 )
    msg = sprintf( "Harry says: Why does %s attack %s?\n", who, what );
  else if( sscanf( str, "%s left the game.", who ) == 1 )
    msg = sprintf( "Harry says: Why did %s quit the game?\n", who );
  else if( sscanf( str, "%s takes %s.", who, what ) == 2 )
    msg = sprintf( "Harry says: Why did %s take %s?\n", who, what );
  else if( sscanf( str, "%s drops %s.", who, what ) == 2 )
    msg = sprintf( "Harry says: Why did %s drop %s?\n", who, what );
  TELLR( ENV( harry ), msg );
}

void how_does_it_feel( string str ) {
  string who, what;

  if( sscanf( str, "%s is now level %s.\n", who, what ) != 2 ) return;
  if( lower_case( who ) == "harry" ) return;
  TELLR( ENV( harry ),
    sprintf( "Harry says: How does it feel, being of level %s?\n", what ) );
}
    
void smiles( string str ) {
  string who, what;

  if( sscanf( str, "%s smiles happily", who ) != 1 ) return;
  if( lower_case( who ) == "harry" ) return;
  TELLR( ENV( harry ), "Harry smiles happily.\n" );
}
    
void say_hello( string str ) {
  string who;

  if( sscanf( str, "%s arrives.", who ) != 1 ) return;
  if( lower_case( who ) == "harry" ) return;
  TELLR( ENV( harry ), 
    sprintf( "Harry says: Hi %s, nice to see you !\n", who ) );
}
    
void test_say( string str ) {
  string who, what, a, b, msg;

  if( sscanf( str, "%s says: %s\n", who, what ) != 2) return;
  if( lower_case( who ) == "harry" ) return;

  if (what == "hello" || what == "hi" || what == "hello everybody")
    msg = "Harry says: Pleased to meet you!\n";
  else if( what == "shut up" )
    msg = "Harry says: Why do you want me to shut up ?\n";
  else if( sscanf( what, "%sstay here%s", a, b ) == 2 ||
      sscanf( what, "%snot follow%s", a, b ) == 2 ||
      sscanf( what, "%sget lost%s", a, b ) == 2)
    msg = "Harry says: Ok then.\n";
  if( !msg) msg = sprintf( "Harry says: Why do you say '%s'???\n", what );
  TELLR( ENV( harry ), msg );
}

void follow( string str ) {
  string who, where;

  if( sscanf( str, "%s leaves %s.\n", who, where ) != 2 ) return;
  if( lower_case( who ) == "harry" ) return;
  if( member_array( where, ENV( harry )->query_room( "dest_dir" ) ) == -1 )
    return;
  harry->init_command( where );
}

void gives( string str ) {
  string who, what, whom, *exits;
  int i, so;
  object obj;

  if( sscanf( str, "%s gives %s to %s.\n", who, what, whom ) != 3 ) return;
  if( lower_case( who ) == "harry" || lower_case( whom ) != "harry" )  
    return;
  if( what != "firebreather" && what != "special" && what != "beer" &&
      what != "bottle" && what != "corpse" ) {
    TELLR( ENV( harry ), sprintf( "Harry says: Thank you very much, %s.\n",
      TP->query_gender() == 2 ? "madam" : "sir" ) );
    return;
  }
  if( what == "corpse" ) {
      obj = present( "corpse", harry );
      transfer( obj, present( lower_case( who ), ENV( harry ) ) );
    TELLR( ENV( harry ), 
      sprintf( "Harry says: HEY, bury your corpses yourself, asshole.\n"
        + "Harry returned the %s to %s.\n", what, who ) );
    return;
  }
  switch( random( 4 ) ) {
    case 0:
      if( random( 10 ) > 6 ) TELLR( ENV( harry ),
        "Harry sighs and says: I guess you're gonna kill me now.\n" );
      else TELLR( ENV( harry ),
        "Harry pukes and mumbles: I still feel sick from the last ten.\n" );
      harry->transfer_all_to( ENV( harry ) );
      TELLR( ENV( harry ), "Harry drops all his belongings.\n" );
      exits = ENV( harry )->query_room( "dest_dir" );
      for( i = sizeof( exits ) - 2; i >= 0; i -= 2 )
        exits -= ({ exits[i] });
      harry->init_command( exits[random( sizeof( exits) )] );
    break;
    case 1:
      TELLR( ENV( harry ), sprintf( "Harry says: Cheers, %s!\n", who ) );
      harry->init_command( "drink " + what );
    break;
    case 2:
      obj = present( what, harry );
      transfer( obj, ENV( harry ) );
      TELLR( ENV( harry ), sprintf( "Harry says: I don't need this junk!\n"
        + "Harry drops the %s.\n", what ) );
    break;
    case 3:
      obj = present( what, harry );
      transfer( obj, present( lower_case( who ), ENV( harry ) ) );
      TELLR( ENV( harry ), sprintf( "Harry says: I have no need for that.\n"
        + "Harry returns the %s to %s.\n", what, who ) );
    break;
  }
}

int monster_died() {
  object obj, b;
  int num;

  while( obj = present( "bottle", previous_object() ) ) {
    destruct( obj );
    num = 1;
  }
  if( num ) TELLR( ENV( harry ),
    "There is a crushing sound of bottles breaking, as the body falls.\n" );
  return 0;
}

