#define PPATH "/players/tatsuo/ezo/coast/"
#define FPATH "/players/tatsuo/ezo/forest/"

inherit "/players/tatsuo/ezo/coast/genShore";

reset( arg )
{
   set_rf_dirs( "" );
   set_shore_dirs( "south and northwest" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ FPATH + "f18",  "north",
                 FPATH + "f19",  "northeast",
                 FPATH + "f24",  "east",
                 FPATH + "f29",  "southeast",
                 PPATH + "sh15", "south",
                 PPATH + "sh11", "northwest",
              });
}

init( )
{
   ::init();
}
