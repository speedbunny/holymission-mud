#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "northwest and north" );
   set_up_dir( PPATH + "t15" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f9",   "northeast",
                 PPATH + "f16",  "east",
                 PPATH + "f23",  "southeast",
                 PPATH + "f22",  "south",
                 PPATH + "f21",  "southwest",
                 PPATH + "f14",  "west",
              });
}

init( )
{
   ::init();
}
