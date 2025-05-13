#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "east, southeast and south" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "rf1",  "north",
                 PPATH + "rf2",  "northeast",
                 PPATH + "rf14", "southwest",
                 PPATH + "rf10", "west",
                 PPATH + "c11",  "northwest",
              });
}

init( )
{
   ::init();
}
