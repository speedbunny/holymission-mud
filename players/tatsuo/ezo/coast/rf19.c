#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "southwest and west" );
   set_coast_dirs( "northeast, east and southeast" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "rf16", "north",
                 PPATH + "rf21", "south",
                 PPATH + "rf15", "northwest",
              });
}

init( )
{
   ::init();
}
