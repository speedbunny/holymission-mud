#define PPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/coast/genCoast";

reset( arg )
{
   set_tekagi();

   ::reset( arg );
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "c4",  "east",
                 PPATH + "rf3", "southeast",
                 PPATH + "rf2", "south",
                 PPATH + "rf1", "southwest",
                 PPATH + "c2",  "west",
              });
}

init( )
{
   ::init();
}
