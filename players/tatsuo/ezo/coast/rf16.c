#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "southwest" );
   set_coast_dirs( "north, northeast, east and southeast" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "rf19", "south",
                 PPATH + "rf15", "west",
                 PPATH + "rf13", "northwest",
              });
}

init( )
{
   ::init();
}
