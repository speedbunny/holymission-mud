#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "southeast, south and southwest" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c5",   "north",
                 PPATH + "c6",   "northeast",
                 PPATH + "rf5",  "east",
                 PPATH + "rf3",  "west",
                 PPATH + "c4",   "northwest",
              });
}

init( )
{
   ::init();
}
