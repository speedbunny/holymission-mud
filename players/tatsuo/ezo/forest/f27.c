#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "" );
   set_up_dir( PPATH + "t27" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f22",  "north",
                 PPATH + "f23",  "northeast",
                 PPATH + "f28",  "east",
                 PPATH + "f33",  "southeast",
                 PPATH + "f32",  "south",
                 PPATH + "f31",  "southwest",
                 PPATH + "f26",  "west",
                 PPATH + "f21",  "northwest",
              });
}

init( )
{
   ::init();
}
