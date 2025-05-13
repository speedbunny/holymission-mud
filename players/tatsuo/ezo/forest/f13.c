#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "north and northeast" );
   set_up_dir( PPATH + "t13" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f14",  "east",
                 PPATH + "f21",  "southeast",
                 PPATH + "f20",  "south",
                 PPATH + "f19",  "southwest",
                 PPATH + "f12",  "west",
                 PPATH + "f8",   "northwest",
              });
}

init( )
{
   ::init();
}
