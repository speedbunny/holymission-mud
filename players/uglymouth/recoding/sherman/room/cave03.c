#include "../defs.h"

inherit "room/room";

int searched;

void reset( int arg ) {
  clone_list = ({ 
    1, 8, "skeleton", "/obj/monster", ({
      "set_name", "skeleton",
      "set_alias", "undead skeleton",
      "set_short", "An undead skeleton",
      "set_long", "This is the undead skeleton of an adventurer who has "
        + "fallen prey to the vampires. It's under their control now and "
        + "it looks like it's after your blood!\n",
      "set_level", 10,
      "set_ac", 7,
      "set_race", "undead",
      "set_aggressive", 1,
      "set_al", -150,
      "set_dead_ob", this_object(),
    }),
  });
  searched = 0;
  ::reset( arg );
  if( arg ) return;

  set_light( -1 );
  short_desc = "In a very dark cave under a dark hill";
  long_desc = "You are walking down a very dark cave in a dark hill. "
    + "It looks like this is a natural cave, eroded into the hard rock "
    + "a long time ago. There are some bones lying scattered along the "
    + "cave walls. The cave continues in more or less northeast. With some " 
    + "effort, you could climb spiralling hole up.\n";
  dest_dir = ({
    ROOM_DIR + "cave04", "northeast",
    ROOM_DIR + "cave02", "up",
  });
  items=({ 
    "cave", "Just a natural cave. It's fairly dry",
    "hill", "It's oppressing presence is all around you",
    "rock", "Dark grey, hard rock",
    "bones", "You notice bones of humans and various animal species",
    "hole", "It leads to a higher level of this cave system",
  });
}

int _search( string str ) {
  object ob;

  if( str != "bones" ) return 0;
  if( present( "undead skeleton" ) ) {
    printf( "The undead skeleton will not let you touch what it may "
      + "conceive of as its dead brothers.\n" );
    return 1;
  }
  if( searched == 2 ) return 0;
  if( !searched ) {
    ob = clone_object( "/obj/thing" );
    ob->set_name( "diary" );
    ob->set_short( "A diary" );
    ob->set_long( "A small diary, dirty and fragile now.\n" );
    ob->set_weight( 1 );
    ob->set_read( "...d now I have been bitten by a vampire I already feel "
      + "its evil spirit slowly conquering my body. I have no chance. My "
      + "only wish is to kill myself in the hope that my body will die "
      + "before it is completely taken over by the vampiric essence. "
      + "Farewell, cruel world!\n" );
    if( transfer( ob, TP ) ) move_object( ob, this_object() );
    searched++;
    printf( "You find a small booklet between the bones. At second glance "
      + "it proves to be a diary from an unfortunate adventurer.\n" );
    return 1;
  }
  ob = clone_object( "/obj/thing" );
  ob->set_name( "rib" );
  ob->set_alias( "vampire rib" );
  ob->set_short( "A human rib" );
  ob->set_long( "This is a rib from the left side of a human body. For "
    + "some unknown reason several tiny wooden splinters are stuck on its "
    + "lower side, which looks grazed in that area.\n" );
  ob->set_weight( 5 );
  if( transfer( ob, TP ) ) move_object( ob, this_object() );
  printf( "You find an odd rib bone in the pile.\n" );
  say( sprintf( "%s rummages through the pile of bones and finds one to "
    + "%s liking.\n", TPSHORTN, TPPOS ), TP );
  return 1;
}

/* Let's not leave something paradoxal like 'corpse of skeleton'... */
int monster_died( object monster ) {
  printf( "As you deal the skeleton the final blow, it falls apart into "
    + "thousands of tiny splinters.\n" );
  say( sprintf( "%s's final blow shatters the skeleton completely.\n",
    TPSHORTN ), TP );
  destruct( monster );
  return 1;
}

