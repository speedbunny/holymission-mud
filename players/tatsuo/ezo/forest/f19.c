#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "" );
   set_up_dir( PPATH + "t19" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f12",  "north",
                 PPATH + "f13",  "northeast",
                 PPATH + "f20",  "east",
                 PPATH + "f25",  "southeast",
                 PPATH + "f24",  "south",
                 SPATH + "sh13", "southwest",
                 PPATH + "f18",  "west",
                 PPATH + "f11",  "northwest",
              });
}

init( )
{
   ::init();
}
