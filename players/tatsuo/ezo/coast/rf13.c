#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "southwest" );
   set_coast_dirs( "northeast and east" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c12",  "north",
                 PPATH + "rf16", "southeast",
                 PPATH + "rf15", "south",
                 PPATH + "rf12", "west",
                 PPATH + "rf9",  "northwest",
              });
}

init( )
{
   ::init();
}
