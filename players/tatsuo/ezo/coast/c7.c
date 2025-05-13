#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genCoast";

reset( arg )
{
   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c8",  "east",
                 PPATH + "rf7", "southeast",
                 PPATH + "rf6", "south",
                 PPATH + "rf5", "southwest",
                 PPATH + "c6",  "west",
              });
}

init( )
{
   ::init();
}
