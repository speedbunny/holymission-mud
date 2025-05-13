#define PPATH "/players/tatsuo/ezo/coast/"
#define FPATH "/players/tatsuo/ezo/forest/"

inherit "/players/tatsuo/ezo/coast/genShore";

reset( arg )
{
   set_rf_dirs( "northeast" );
   set_shore_dirs( "north and southeast" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "sh3", "north",
                 FPATH + "f2",  "east",
                 PPATH + "sh7", "southeast",
              });
}

init( )
{
   ::init();
}
