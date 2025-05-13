#include "../defs.h"

#ifdef HEAL_INTERVAL
#undef HEAL_INTERVAL
#endif
#define HEAL_INTERVAL 15  /* was 30 seconds in monster.c */
#ifdef HEAL_FACTOR
#undef HEAL_FACTOR
#endif
#define HEAL_FACTOR 4     /* was 2 in monster.c */

inherit "obj/monster";

void reset( int arg ) {
  ::reset(arg);
  if (arg) return;

  set_name( "troul" );
  set_alias( "undead troul" );
  set_short( "An undead troul" );
  set_long( "This evil monster is the rseult of a weird necromantic "
    + "experiment trying to create an undead ghoul out of a troll corpse. "
    + "The result is a grossly misshaped creature resembling neither. It "
    + "is little more than a large, callous covered monster of roughly "
    + "humanoid shape. Big fangs protrude from its lower jaw.\n" );
  set_level( 20 );
  set_race( "undead" );
  set_al( -300 );
  set_ac( 7 );
  set_wc( 15 );
  set_aggressive( 1 );
  set_dead_ob( this_object() );
}

/* DOC:
 * Only if completely destroyed by fire this monster will be dead
 * permanently. Otherwise it will regenerate, and quite fast too *grin*
 * Note that it will display regenerating hp status when looked at!
 */
int monster_died( object monster ) {
  if( (int)monster->query_max_hp() <= 0 ) return 0;
  monster->set_name( "Corpse of troul" );
  monster->set_alt_name( "corpse" );
  monster->set_short( "Corpse of troul" );
  monster->set_long( "This is the corpse of a troul.\n" );
  monster->set_no_fight( 1 );
  call_out( "revive_troul", max_hp/HEAL_INTERVAL, monster );
  return 1;
}

void revive_troul( object monster ) {
  monster->set_hp( monster->query_max_hp() );
  monster->set_name( "troul" );
  monster->set_alt_name( 0 );
  monster->set_short( "An undead troul" );
  monster->set_long( "This evil monster is the rseult of a weird necromantic "
    + "experiment trying to create an undead ghoul out of a troll corpse. "
    + "The result is a grossly misshaped creature resembling neither. It "
    + "is little more than a large, callous covered monster of roughly "
    + "humanoid shape. Big fangs protrude from its lower jaw.\n" );
  monster->set_no_fight( 0 );
  say( "The corpse of the troul comes back to life!!\n" );
  /* add attack routine, if necessary */
}

varargs mixed hit_player( int dmg, int deftype, int dmgtype ) {
  if( dmgtype != 1 ) return ::hit_player( dmg, deftype, dmgtype );
  say( "The heat sears the troul's flesh badly!\n" );
  max_hp -= dmg;
  return ::hit_player( 3*dmg/2, deftype, dmgtype );
}
