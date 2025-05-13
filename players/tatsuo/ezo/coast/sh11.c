#define PPATH "/players/tatsuo/ezo/coast/"
#define FPATH "/players/tatsuo/ezo/forest/"

inherit "/players/tatsuo/ezo/coast/genShore";

reset( arg )
{
   set_rf_dirs( "" );
   set_shore_dirs( "north and southeast" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "sh9",  "north",
                 FPATH + "f11",  "northeast",
                 FPATH + "f18",  "east",
                 PPATH + "sh13", "southeast",
              });
}

init( )
{
   ::init();
}
