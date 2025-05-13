#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "southeast" );
   set_coast_dirs( "west and northwest" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c11",  "north",
                 PPATH + "rf1",  "northeast",
                 PPATH + "rf11", "east",
                 PPATH + "rf14", "south",
                 PPATH + "c13",  "southwest",
              });
}

init( )
{
   ::init();
}
