#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "south, southwest and west" );
   set_coast_dirs( "northwest" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "rf13", "north",
                 PPATH + "rf16", "east",
                 PPATH + "rf19", "southeast",
                 PPATH + "rf12", "northwest",
              });
}

init( )
{
   ::init();
}
