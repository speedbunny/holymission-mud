#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "southeast, south and southwest" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c6",   "north",
                 PPATH + "c7",   "northeast",
                 PPATH + "rf6",  "east",
                 PPATH + "rf4",  "west",
                 PPATH + "c5",   "northwest",
              });
}

init( )
{
   ::init();
}
