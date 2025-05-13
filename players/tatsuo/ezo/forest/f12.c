#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "northeast" );
   set_up_dir( PPATH + "t12" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f8",   "north",
                 PPATH + "f13",  "east",
                 PPATH + "f20",  "southeast",
                 PPATH + "f19",  "south",
                 PPATH + "f18",  "southwest",
                 PPATH + "f11",  "west",
                 PPATH + "f7",   "northwest",
              });
}

init( )
{
   ::init();
}
