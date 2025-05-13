#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genCoast";

reset( arg )
{
   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c9",  "east",
                 PPATH + "rf8", "southeast",
                 PPATH + "rf7", "south",
                 PPATH + "rf6", "southwest",
                 PPATH + "c7",  "west",
              });
}

init( )
{
   ::init();
}
