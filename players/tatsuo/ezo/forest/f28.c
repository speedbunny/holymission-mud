#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   set_rf_dirs( "" );
   set_up_dir( PPATH + "t28" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f23",  "north",
                 SPATH + "sh12", "northeast",
                 SPATH + "sh14", "east",
                 SPATH + "sh16",  "southeast",
                 PPATH + "f33",  "south",
                 PPATH + "f32",  "southwest",
                 PPATH + "f27",  "west",
                 PPATH + "f22",  "northwest",
              });
}

init( )
{
   ::init();
}
