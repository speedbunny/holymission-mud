inherit "/players/llort/shadowplane/shadowroom";
#include "/players/llort/shadowplane/room_defs.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   short_desc = "In a dark chamber";
   long_desc =
      "You are in a really dark chamber. The air here is really bad, almost\n"+
      "making you vomit. Otherwise it is like the cave: supressing walls,\n"+
      "the same material and the some liquid dropping from the ceiling onto\n"+
      "your head .... drop .... drop .... drop ..... annoying !\n";

   items += ({ "liquid","You don't know this liquid. It is red",
               "ceiling","It is soft to the touch",
               "walls","They are soft to the touch",
               "wall","It is soft to the touch",
               "material","It is very strange" });
  
   hidden_dir = ({ RPATH+"underTrunk4", "north" });

   set_no_random();
}

void init()
{
   ::init();

   add_action( "do_touch", "touch" );
}

int do_touch( string arg )
{
   if ( arg != "wall" && arg != "ceiling" )
      return( 0 );

   if ( arg == "wall" ) {
      write( "As you try to touch the northern wall, your hand passes right "+
             "through it !!!\n" );
      return( 1 );
   }

   write( "You touch the "+arg+".\n" );
   say( TPN + " touches the "+arg+".\n" );
   return( 1 );
}
