#define NAME "uglymouth"
#define DEST "players/uglymouth/workroom"

int reset_time, last_reset;

void reset( int arg ) {
  reset_time = time() - last_reset;
  last_reset = time();
  if( arg ) return;
  reset_time = 0;
  move_object( this_object(), DEST );
}

int query_reset_time() {
  return reset_time;
}

int id( string str ) {
  return str == "castle" || str == "model";
}

string short() {
  return sprintf( "A small scale model of %s's Viking area",
    capitalize( NAME ) );
}

void long() {
  printf( "This is a small scale model of Uglymouth's Viking  area.\n"
    + "It is very detailed. If you 'spy' it carefully, you might\n"
    + "even see miniature players walking around.\n" );
}

void init() {
  add_action( "do_enter", "enter" );
  add_action( "spot_players", "spy" );
}

int do_enter( string str ) {
  if( !id( str ) ) return 0;
  printf( "You project yourself into the viking area. \n" );
  this_player()->move_player( "though the model to the viking area#"
    + "players/uglymouth/vikings/shore1" );
  return 1;
}

void make_quest() {
  object quest;

  quest = clone_object( "/obj/quest_obj" );
  quest->set_name( "viking" );
  quest->set_weight( 35 );
  quest->set_killing( 2 );
  quest->set_short_hint( "Convince the Vikings to leave Symria" );
  quest->set_hint(
    "On a tropical bay, somewhere southeast in this world, a clan of Vikings\n"
    + "has invaded a coastal village, called Symria. The Vikings have proven to be\n"
    + "quite stubborn in negotiations and are now planning to settle in the\n"
    + "village and its surrounding area.\n"
    + "With our diplomats sent back in only their underwear and our armies needed\n"
    + "elsewhere, we need a witty adventurer to get the Vikings to leave the area.\n\n"
    + "Note: this quest can be solved without fighting, but if you get into one\n"
    + "prepare to lose some hit points. Good luck.\n\n"
    + "                                 Viking Lord Uglymouth\n");
  quest->add_quest();
}

int spot_players( string str ) {
  int i, total, so;
  object *u;
  string place;
  
  if( !id( str ) ) return 0;
  u = users();
  for( total = 0, i = 0, so = sizeof( u ); i < so; i++ ) {
    if( environment( u[i] ) ) place = file_name( environment( u[i] ) );
    if( strstr( place, "uglymouth/vikings" ) == -1 ) continue;
    printf( "%-:10s is at %s.\n", u[i]->query_short_name(), 
      place->short() );
    total++;
  }
  printf( "There %s %d player%s in the Viking area.\n", 
    total == 1 ? "is" : "are", total, total == 1 ? "" : "s" );
  return 1;
}
