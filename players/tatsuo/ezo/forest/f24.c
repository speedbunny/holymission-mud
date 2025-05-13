#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "" );
   set_up_dir( PPATH + "t24" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f19",  "north",
                 PPATH + "f20",  "northeast",
                 PPATH + "f25",  "east",
                 PPATH + "f30",  "southeast",
                 PPATH + "f29",  "south",
                 SPATH + "sh15", "southwest",
                 SPATH + "sh13", "west",
                 PPATH + "f18",  "northwest",
              });
}

init( )
{
   ::init();
}
