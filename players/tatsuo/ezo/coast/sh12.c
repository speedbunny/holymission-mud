#define PPATH "/players/tatsuo/ezo/coast/"
#define FPATH "/players/tatsuo/ezo/forest/"

inherit "/players/tatsuo/ezo/coast/genShore";

reset( arg )
{
   set_rf_dirs( "" );
   set_shore_dirs( "northeast and south" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ FPATH + "f17",  "north",
                 PPATH + "sh10", "northeast",
                 PPATH + "sh14", "south",
                 FPATH + "f28",  "southwest",
                 FPATH + "f23",  "west",
                 FPATH + "f16",  "northwest",
              });
}

init( )
{
   ::init();
}
