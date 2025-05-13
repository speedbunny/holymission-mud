#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "east and southeast" );
   set_coast_dirs( "northwest" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "rf10", "north",
                 PPATH + "rf11", "northeast",
                 PPATH + "rf18", "south",
                 PPATH + "rf17", "southwest",
                 PPATH + "c13",  "west",
              });
}

init( )
{
   ::init();
}
