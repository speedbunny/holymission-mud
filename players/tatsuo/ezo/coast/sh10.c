#define PPATH "/players/tatsuo/ezo/coast/"
#define FPATH "/players/tatsuo/ezo/forest/"

inherit "/players/tatsuo/ezo/coast/genShore";

reset( arg )
{
   set_rf_dirs( "" );
   set_shore_dirs( "southwest and north" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "sh8",  "north",
                 PPATH + "sh12", "southwest",
                 FPATH + "f17",  "west",
                 FPATH + "f12",  "northwest",
              });
}

init( )
{
   ::init();
}
