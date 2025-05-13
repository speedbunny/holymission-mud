#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "southeast" );
   set_coast_dirs( "southwest, west and northwest" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c13",  "north",
                 PPATH + "rf14", "northeast",
                 PPATH + "rf18", "east",
                 PPATH + "rf20", "south",
              });
}

init( )
{
   ::init();
}
