#include "../defs.h"

inherit "room/room";

status searched;

void reset( int arg ) {
  clone_list = ({
    1, 1, "karinev the vampire", MON_DIR + "karinev", 0,
  });
  searched = 0;
  ::reset( arg );
  if( arg ) return;

  set_light( 1 );
  short_desc = "On the fourth floor of a black tower.";
  long_desc = "You have ended up at the fourth floor of the black tower. "
    + "This is obviously a rich woman's bedroom. An intricately carved oak "
    + "bed, made with satin sheets and duck feather pillows attracks most "
    + "attention. To one side there is a dresser, while at the other there "
    + "is a small closet. There are no windows but the room is illuminated "
    + "by 13 candles placed evenly around the outer wall. A flight of "
    + "stairs leads down.\n";
  dest_dir = ({
    ROOM_DIR + "vtower05", "down",
  });
  items=({
    "tower", "You are inside it",
    "bedroom", 
      "The luxury suggests this is where the lady of the house resides",
    "bed", "It's carved with pictures of various death rituals",
    "sheets", "The blackest satin you've ever seen",
    "pillows", "Though very soft, the black pillows don't look inviting",
    "dresser", "A nutwood dresser with numerous drawers",
    "drawers", "None of it contains anything of interest",
    "closet", "A small wardrobe containing several black dresses",
    "dresses", "The dresses all have a certain chique style to them",
    "candles", "All thirteen are black wax candles",
    "stairs", "A wide, spiralling flight of stone stairs",
  });
  property = ({ "has_fire" });
}

void init() {
  ::init();
  add_action( "do_search", "search" );
}

int do_search( string str ) {
  object box, candle;
  int i;

  if( str != "dresser" || searched ) {
    notify_fail( "You find nothing of interest.\n" );
    return 0;
  }
  box = clone_object( "/obj/container" );
  box->set_name( "candle box" );
  box->set_alias( "box" );
  box->set_short( "A candle box" );
  box->set_long( "This is a small box carved from cedar wood. Inside it "
    + "has four layers each with five oval depressions, specially made to "
    + "contain expensive candles.\n" );
  box->set_can_close( 1 );
  box->set_closed();
  box->set_only_for( "candle" );
  box->set_weight( 10 );
  box->set_max_internal_weight( 20 );
  box->set_value( 150 );

  for( i = 0; i < 15; i++ ) {
    candle = clone_object( "/obj/torch" );
    candle->set_name( "white candle" );
    candle->set_alias( "candle" );
    candle->set_alt_name( "torch" );
    candle->set_short( "A white candle" );
    candle->set_long( "This is a pure white candle, made of the clearest "
      + "bees' wax you have ever seen. It must be a delight to see them "
      + "burn solemnly.\n" );
    candle->set_weight( 1 );
    candle->set_value( 10 );
    transfer( candle, box );
  }
  if( transfer( box, this_player() ) )
    move_object( box, this_object() );
  searched = 1;
  printf( "In the dark shadows under the dresser you find a candle box.\n" );
  say( sprintf( "%s puts %s nose in the dust that has accumulated under "
    + "the dresser. As %s gets up again, the face hardly recognisable, "
    + "%s holds a small hox in %s hands.\n", this_player()->query_name(),
    this_player()->query_possessive(), this_player()->query_name(),
    this_player()->query_pronoun(), this_player()->query_possessive() ),
    this_player() );
  return 1;
}

