#include "../defs.h"

inherit "room/room";

status ghost_released;

void reset( int arg ) {
  ghost_released = 0;
  ::reset( arg );
  if( arg ) return;

  set_light( 1 );
  short_desc = "On the first floor of a black tower.";
  long_desc = "You have arrived at the first floor of the black tower. There "
    + "used to be guest quarters here, but right now everything is covered "
    + "with thick layers of dust. There are six small rooms built against "
    + "the outer wall, none of which have doors. Looking inside you see "
    + "they are now empty. The stairs continue up and down.\n";
  dest_dir = ({
    ROOM_DIR + "vtower04", "up",
    ROOM_DIR + "vtower02", "down",
  });
  items=({
    "tower", "You are inside it",
    "dust", "The dust of disuse, not even disturbed by a rat's tracks",
    "rooms", "All rooms seem empty, although you think you noticed a vague "
      + "shimmer in one of them",
    "shimmer", "When you look from the corner of your eye, without trying "
      + "to focus too hard, you see the shape of an old man using his "
      + "hands to try to warn you not to go upstairs",
    "stairs", "A wide, spiralling flight of stone stairs",
  });
}

int move( string str ) {
  object ghost;

  if( !str ) str = query_verb();
  if( str != "up" ) return ::move( str );
  if( present( "ghost of guest" ) ) {
    printf( "Ghost of guest prevents you from going up.\n" );
    return 1;
  }
  if( ghost_released ) return ::move( str );
  ghost = clone_object( "/obj/monster" );
  ghost->set_name( "ghost of guest" );
  ghost->set_alias( "ghost" );
  ghost->set_short( "Ghost of guest" );
  ghost->set_long( "This is the ghost of one of the guests of the evil "
    + "lord of this tower. Two small pits in its translucent neck indicate "
    + "the tragic faith it has suffered from.\n" );
  ghost->set_level( 18 );
  ghost->set_race( "undead" );
  ghost->set_hp( 700 );
  ghost->set_al( -300 );
  ghost->set_wc( 18 );
  ghost->set_ac( 12 );
  ghost->set_chance( 10 );
  ghost->set_spell_mess1( "Ghost touches its victim" );
  ghost->set_spell_mass( "Ghost touches you. "
    + "A freezing shiver runs along your spine" );
  ghost->set_spell_dam( 25 );
  ghost->load_chat( 20, ({
    "Ghost of guest says: The Count Vampire has killed us.\n",
    "Ghost of guest says: I hate vampires.\n",
    "Ghost of guest says: They will suck your blood, as they did mine.\n",
    "Ghost of guest says: We are the lost souls.\n",
  }) );
  ghost->load_a_chat( 20, ({
    "Ghost of guest says: I hate you, bloody vampire!\n",
    "Ghost of guest says: This is my revenge.\n",
    "Ghost of guest says: Now I kill you!\n",
  }) );
  move_object( ghost, this_object() );
  ghost_released = 1;
  tell_room( this_object(), "From one of the rooms a ghost arrives.\n" );
  return 1;
}

