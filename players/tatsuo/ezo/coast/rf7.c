#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "southeast, south and southwest" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c8",   "north",
                 PPATH + "c9",   "northeast",
                 PPATH + "rf8",  "east",
                 PPATH + "rf6",  "west",
                 PPATH + "c7",   "northwest",
              });
}

init( )
{
   ::init();
}
