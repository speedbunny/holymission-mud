#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "" );
   set_up_dir( PPATH + "t25" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f20",  "north",
                 PPATH + "f21",  "northeast",
                 PPATH + "f26",  "east",
                 PPATH + "f31",  "southeast",
                 PPATH + "f30",  "south",
                 PPATH + "f29",  "southwest",
                 PPATH + "f24",  "west",
                 PPATH + "f19",  "northwest",
              });
}

init( )
{
   ::init();
}
