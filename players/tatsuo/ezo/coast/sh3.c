#define PPATH "/players/tatsuo/ezo/coast/"
#define FPATH "/players/tatsuo/ezo/forest/"

inherit "/players/tatsuo/ezo/coast/genShore";

reset( arg )
{
   set_rf_dirs( "north, northeast and east" );
   set_shore_dirs( "south" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ FPATH + "f2",  "southeast",
                 PPATH + "sh5", "south",
              });
}

init( )
{
   ::init();
}
