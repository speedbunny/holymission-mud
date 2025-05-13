#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "" );
   set_up_dir( PPATH + "t22" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f15",  "north",
                 PPATH + "f16",  "northeast",
                 PPATH + "f23",  "east",
                 PPATH + "f28",  "southeast",
                 PPATH + "f27",  "south",
                 PPATH + "f26",  "southwest",
                 PPATH + "f21",  "west",
                 PPATH + "f14",  "northwest",
              });
}

init( )
{
   ::init();
}
