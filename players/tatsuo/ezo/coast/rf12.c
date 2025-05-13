#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genRockFace";

reset( arg )
{
   set_rf_dirs( "south, southwest and west" );

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "rf9",  "north",
                 PPATH + "c12",  "northeast",
                 PPATH + "rf13", "east",
                 PPATH + "rf15", "southeast",
                 PPATH + "rf8",  "northwest",
              });
}

init( )
{
   ::init();
}
