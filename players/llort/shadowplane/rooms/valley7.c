inherit "/players/llort/shadowplane/shadowroom";
#include "/players/llort/shadowplane/room_defs.h"

int is_moved;

void reset( int tick )
{
   is_moved = 0;

   ::reset( tick );
   if ( tick ) return;

   short_desc = "Change of direction";
   long_desc =
      "The valley changes directions here. One way leads to the north,\n"+
      "and one leads east. Of course, everything is huddled in shadows\n"+
      "too in here. A strange thing is a nearly rotten tree-trunk at the\n"+
      "ground. You wonder how any living thing can grow here ..@@to@@\n";

   dest_dir = ({ RPATH+"valley8", "north",
                 RPATH+"valley6", "east", });

   items += ({"tree-trunk","Nearly rotten, nothing special",
              "tree", "Nearly rotten, nothing special",
              "tree trunk", "Nearly rotten, nothing special",
              "trunk", "Nearly rotten, nothing special", });
}

void init( )
{
   ::init();

   add_action( "do_move", "move" );
   add_action( "do_move", "lift" );
   add_action( "do_move", "push" );
   add_action( "do_down", "down" );
   add_action( "do_down", "enter" );
}

int do_move( string what )
{
   if ( what != "tree-trunk" && what != "tree" && what != "tree trunk" &&
        what != "trunk" )
      return( 0 );

   if ( is_moved )
      write( "Nothing happens.\n" );
   else {
      write( "As you try to move the trunk, it slighty falls apart,\n"+
             "revealing a secret opening !!!\n" );
      say( TPN+" reveals a secret opening !\n" );
      is_moved = 1;
   }
  
   return( 1 ); 
}

string to( )
{
   if ( is_moved )
      return( ".\nThere is an opening leading down into darkness !" );
   return( "." );
}

int do_down( string arg )
{
   if ( is_moved && !arg || arg == "opening" ) {
      TP->move_player( "down#"+RPATH+"underTrunk1" );
      return( 1 );
   }

   return( 0 );
}

int is_open() { return( is_moved ); }
void open()   { is_moved = 1; }

