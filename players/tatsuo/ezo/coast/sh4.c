#define PPATH "/players/tatsuo/ezo/coast/"
#define FPATH "/players/tatsuo/ezo/forest/"

inherit "/players/tatsuo/ezo/coast/genShore";

reset( arg )
{
   set_rf_dirs( "northwest" );
   set_shore_dirs( "north and south" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "sh2", "north",
                 PPATH + "sh6", "south",
                 FPATH + "f5",  "southwest",
                 FPATH + "f1",  "west",
              });
}

init( )
{
   ::init();
}
