#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "" );
   set_up_dir( PPATH + "t11" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f7",   "north",
                 PPATH + "f8",   "northeast",
                 PPATH + "f12",  "east",
                 PPATH + "f19",  "southeast",
                 PPATH + "f18",  "south",
                 SPATH + "sh11", "southwest",
                 SPATH + "sh9",  "west",
                 PPATH + "f6",   "northwest",
              });
}

init( )
{
   ::init();
}
