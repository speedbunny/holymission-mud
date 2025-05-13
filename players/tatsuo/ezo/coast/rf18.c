#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "northeast, east, southeast and south" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "rf14", "north",
                 PPATH + "rf20", "southwest",
                 PPATH + "rf17", "west",
                 PPATH + "c13",  "northwest",
              });
}

init( )
{
   ::init();
}
