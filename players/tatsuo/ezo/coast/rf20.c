#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "east and southeast" );
   set_coast_dirs( "southwest, west and northwest" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "rf17", "north",
                 PPATH + "rf18", "northeast",
                 PPATH + "rf22", "south",
              });
}

init( )
{
   ::init();
}
