#include "../defs.h"

#define HUMAN_FORM    0
#define WOLF_FORM     1
#define BAT_FORM      2
#define GAS_FORM      3
#define HUMAN_CHANGE  9 * query_max_hp() / 10
#define WOLF_CHANGE   query_max_hp() / 2
#define BAT_CHANGE    query_max_hp() / 10

inherit "obj/monster";

private int current_form, to_form;
private mapping human_data;
private status busy_transforming;
private string grave;
private string killed_by;

void check_transform();
void transform();
void restore_vampire();
void move_to_coffin();

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;

  set_alt_name( "vampire" ); // Set this value for alt_name in ALL vampires!
  set_race( "undead" );
  set_dead_ob( this_object() );
  human_data = ([ ]);
  current_form = HUMAN_FORM;
  to_form = -1;
}

varargs int attack( object theWeapon, int nrOfHand ) {
  int res;

  if( !( res = ::attack( theWeapon, nrOfHand ) ) ) return 0;
  check_transform();
  return res;
}

void check_transform() {
  if( query_hp() >= HUMAN_CHANGE && current_form != HUMAN_FORM ) {
    to_form = HUMAN_FORM;
    transform();
    return;
  }
  if( query_hp() <= BAT_CHANGE && current_form != BAT_FORM ) {
    to_form = BAT_FORM;
    transform();
    return;
  }
  if( query_hp() <= WOLF_CHANGE && current_form != WOLF_FORM ) {
    to_form = WOLF_FORM;
    transform();
    return;
  }
}

void set_name( string str ) {
  ::set_name( str );
  if( !human_data[ "name" ] ) human_data[ "name" ] = str;
}

void set_alias( string str ) {
  ::set_alias( str );
  if( !human_data[ "alias" ] ) human_data[ "alias" ] = str;
}

void set_short( string str ) {
  ::set_short( str );
  if( !human_data[ "short" ] ) human_data[ "short" ] = str;
}

void set_long( string str ) {
  ::set_long( str );
  if( !human_data[ "long" ] ) human_data[ "long" ] = str;
}

void set_al( int i ) {
  ::set_ac( i );
  if( !human_data[ "align" ] ) human_data[ "align" ] = i;
}

void set_ac( int i ) {
  ::set_ac( i );
  if( !human_data[ "ac" ] ) human_data[ "ac" ] = i;
}

void set_wc( int i ) {
  ::set_wc( i );
  if( !human_data[ "wc" ] ) human_data[ "wc" ] = i;
}

void set_grave( string str ) {
  grave = str;
}

string query_current_form( int form ) {
  switch( form ) {
    case HUMAN_FORM:   return "human";
    case WOLF_FORM:    return "wolf";
    case BAT_FORM:     return "bat";
    case GAS_FORM:     return "cloud of gas";
    default:           return "ERROR: Bad vampire shape: " + current_form;
  }
}

void transform() {
  if( to_form < 0 ) return;

  switch( to_form ) {
    object grave_room;

    case HUMAN_FORM:
      restore_vampire();
    break;
    case WOLF_FORM:
      set_name( "wolf" );
      set_alias( human_data[ "alias" ] );
      set_short( "A vampiric wolf" );
      set_long( "A vampiric wolf.\n" );
      set_race( "undead" );
      set_al( human_data[ "align" ] );
      set_ac( ( human_data[ "ac" ] + human_data[ "wc" ] ) / 2 );
      set_wc( ( human_data[ "ac" ] + human_data[ "wc" ] ) / 2 );
    break;
    case BAT_FORM:
      set_name( "bat" );
      set_alias( human_data[ "alias" ] );
      set_short( "A vampiric bat" );
      set_long( "A vampiric bat.\n" );
      set_race( "undead" );
      set_al( human_data[ "align" ] );
      set_ac( human_data[ "wc" ] );
      set_wc( human_data[ "ac" ] );
    break;
    case GAS_FORM:
      set_no_fight( 1 );
      set_name( "cloud of gas" );
      set_alias( "cloud" );
      set_short( "A vampiric cloud of gas" );
      set_long( "A vampiric cloud of gas.\n" );
      set_race( "undead" );
      set_al( human_data[ "align" ] );
      move_to_coffin();
    break;
  }
  current_form = to_form;
  to_form = -1;
}

int monster_died() {
  printf( "As you deliver the fatal blow, the vampire starts to dissolve "
    + "into a gaseous form. You realise now that vampires cannot be "
    + "killed in the normal way.\n" );
  say( sprintf( "As %s delivers the fatal blow to the vampire, it "
    + "transforms into gaseous form.\n", TPSHORTN ), TP );
  killed_by = TP->query_real_name();
  to_form = GAS_FORM;
  transform();
  return 1;
}

void restore_vampire() {
  set_name( human_data[ "name" ] );
  set_alias( human_data[ "alias" ] );
  set_short( human_data[ "short" ] );
  set_long( human_data[ "long" ] );
  set_race( "undead" );
  set_al( human_data[ "align" ] );
  set_ac( human_data[ "ac" ] );
  set_wc( human_data[ "wc" ] );
  to_form = -1;
}

void move_to_coffin() {
  object grave_room, coffin;

  if( !( grave_room = find_object( grave ) ) ) {
    call_other( grave, "???" );
    grave_room = find_object( grave );
  }
  if( grave_room->query_coffin_destroyed() ) {
    tell_room( environment(), "As the vampire realises that its coffin "
      + "has been destroyed, it screams in mortal fear while the cloud of "
      + "gas slowly dissolves into nothing!\n" );
    destruct( this_object() );
    return;
  }
  if( !( coffin = grave_room->query_coffin() ) ) {
    coffin = clone_object( ITEM_DIR + "coffin" );
    grave_room->set_coffin( coffin );
  }
  transfer( this_object(), coffin );
  restore_vampire();
  tell_room( environment(),
    "A cloud of gas slowly drifts away on the air.\n" );
}

