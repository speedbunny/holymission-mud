#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "northwest" );
   set_up_dir( PPATH + "t10" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f4",   "north",
                 PPATH + "f5",   "northeast",
                 SPATH + "sh8",  "east",
                 SPATH + "sh10", "southeast",
                 PPATH + "f17",  "south",
                 PPATH + "f16",  "southwest",
                 PPATH + "f9",   "west",
              });
}

init( )
{
   ::init();
}
