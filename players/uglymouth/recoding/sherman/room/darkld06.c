#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  ::reset( arg );

  if( arg ) return;
  set_light( 1 );
  short_desc = "A valley between the first two dark hills in a dark land.";
  long_desc = "You walk in the valley between the first two hills of this "
    + "dark and cursed land. The sombre colours around you are depressing. "
    + "Once a small stream ran through here, but now all that's left is "
    + "a narrow patch of swamp. A couple of stepping stones allow you "
    + "to cross it. The road runs to the northeast and to the west.\n";
  dest_dir = ({
    ROOM_DIR + "darkld07", "northeast",
    ROOM_DIR + "darkld04", "west",
  });
  items=({ 
    "valley", "The darkness of the hills surrounding it feels threatening",
    "hills", "Hills covered with dark grey sand and dark brown heather "
      + "shrubs border this valley to the east and west",
    "coulours", "Dark grey sand, dark brown plants and a lighter grey sky",
    "road", 
      "It looks like a normal dirt road. To the east it crosses a swamp",
    "swamp", "It's only a narrow patch of land, but the sight of decay "
      + "and quicksand doesn't make you feel any better",
    "stepping stones", "Big flat rocks that lie in the swamp. You can use "
      + "them as a bridge to get across. They are covered with green algae",
  });
  smell = "The rotting smell of decay makes you feel sick.\n";
}

void init() {
  ::init();
  add_action( "go_east", "east" );
}

int go_east() {
  object *all, lost;

  if( random( ( this_player()->query_dex() / 3) + 2 ) ) return 0;
  all = ({ });
  all = filter_array( all_inventory( TP ), "loose_items", this_object() );
  if( !sizeof( all ) ) return 0;
  lost = all[ random( sizeof( all ) ) ];
  transfer( lost, environment( TP ) );  // To prevent weight bugs...
  destruct( lost );
  printf( "Suddenly you loose grip as you slip on the algae!!\n"
    + "With wild swinging of your hands you manage to regain balance. "
    + "When you hear 'Splutffj', you realize you have lost something.\n" );
  say( sprintf( "%s almost loses %s balance on the slippery algae covered "
    + "stepping stones.\n", TPSHORTN, TPPOS ), TP );
  return 0;  // To allow the player to be moved east...
}

int loose_items( object ob ) {
  if( ob->drop() ) return 0;
  if( ob->query_worn() && ob->query_wielded() ) return 0;
  if( ob->query_quest_item() ) return 0;
  if( ob->is_bag() ) return 0;
  return 1;
}

