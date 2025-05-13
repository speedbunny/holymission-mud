#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "southwest" );
   set_coast_dirs( "northeast" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c10",  "north",
                 PPATH + "c12",  "east",
                 PPATH + "rf13", "southeast",
                 PPATH + "rf12", "south",
                 PPATH + "rf8",  "west",
                 PPATH + "c9",   "northwest",
              });
}

init( )
{
   ::init();
}
