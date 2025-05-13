#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "south and southwest" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c9",   "north",
                 PPATH + "c10",  "northeast",
                 PPATH + "rf9",  "east",
                 PPATH + "rf12", "southeast",
                 PPATH + "rf7",  "west",
                 PPATH + "c8",   "northwest",
              });
}

init( )
{
   ::init();
}
