#define PPATH "/players/tatsuo/ezo/forest/"

inherit "/players/tatsuo/ezo/forest/genTree";

reset( arg )
{
   set_down_dir( PPATH + "f20" );

   ::reset( arg );

   items = ({"leaves","There is a hole hidden behind all these leaves",
             "hole","It leads right into the fountain", }) + items;
}

init( )
{
   ::init();

   add_action( "do_enter", "enter" );
   add_action( "do_search", "search" );
}

do_enter( arg )
{
   if ( arg != "hole" ) return;

   this_player()->move_player("out of sight#players/tatsuo/ezo/conn7a.c");
   return( 1 );
}

do_search( arg )
{
   if ( arg == "leaves" )
      write( "You found a hole !\n" );
   else
      write( "You search and search, but find nothing special.\n" );

   return( 1 );
}
