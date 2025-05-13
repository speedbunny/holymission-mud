#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genCoast";

reset( arg )
{
   set_tekagi();

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c6",  "east",
                 PPATH + "rf5", "southeast",
                 PPATH + "rf4", "south",
                 PPATH + "rf3", "southwest",
                 PPATH + "c4",  "west",
              });
}

init( )
{
   ::init();
}
