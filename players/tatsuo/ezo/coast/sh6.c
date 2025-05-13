#define PPATH "/players/tatsuo/ezo/coast/"
#define FPATH "/players/tatsuo/ezo/forest/"

inherit "/players/tatsuo/ezo/coast/genShore";

reset( arg )
{
   set_rf_dirs( "" );
   set_shore_dirs( "north and southwest" );
   
   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "sh4",  "north",
                 PPATH + "sh8",  "southwest",
                 FPATH + "f5",   "west",
                 FPATH + "f1",   "northwest",
              });
}

init( )
{
   ::init();
}
