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
      
   dest_dir = ({ FPATH + "f5",   "north",
                 PPATH + "sh6",  "northeast",
                 PPATH + "sh10", "south",
                 FPATH + "f17",  "southwest",
                 FPATH + "f10",  "west",
                 FPATH + "f4",   "northwest",
              });
}

init( )
{
   ::init();
}
