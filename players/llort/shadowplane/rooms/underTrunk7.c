inherit "/players/llort/shadowplane/shadowroom";
#include "/players/llort/shadowplane/room_defs.h"

void reset( int tick )
{
   ::reset( tick );
   if ( tick ) return;

   short_desc = "Dead end";
   long_desc =
      "You are in a narrow, dark cave. The walls seem to suppress you, but\n"+
      "at least you can see the walls clearly. The material, the walls are\n"+
      "made of, is soft to the touch, but none you can find on the prime\n"+
      "material plane. A liquid is dropping down from the ceiling right onto\n"+
      "your head .... drop .... drop .... drop ..... annoying !\n"+
      "You have reached the end of the tunnel.\n";

   items += ({ "liquid","You don't know this liquid. It is red",
               "ceiling","It is soft to the touch",
               "walls","They are soft to the touch",
               "wall","It is soft to the touch",
               "material","It is very strange" });
  
   hidden_dir = ({ RPATH+"underTrunk6", "east" });
   dest_dir =   ({ RPATH+"underTrunk8", "north" });
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
      write( "As you try to touch the eastern wall, your hand passes right "+
             "through it !!!\n" );
      return( 1 );
   }
   write( "You touch the "+arg+".\n" );
   say( TPN + " touches the "+arg+".\n" );
   return( 1 );
}
