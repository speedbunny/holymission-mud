#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genCoast";

reset( arg )
{
   set_tekagi();

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "rf10", "northeast",
                 PPATH + "rf14", "east",
                 PPATH + "rf18", "southeast",
                 PPATH + "rf17", "south",
              });
}

init( )
{
   ::init();
}
