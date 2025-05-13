#define PPATH "/players/tatsuo/ezo/coast/"
#define FPATH "/players/tatsuo/ezo/forest/"

inherit "/players/tatsuo/ezo/coast/genShore";

reset( arg )
{
   set_rf_dirs( "west, northwest and north" );
   set_shore_dirs( "northeast and south" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "sh1", "northeast",
                 PPATH + "sh4", "south",
                 FPATH + "f1",  "southwest",
              });
}

init( )
{
   ::init();
}
