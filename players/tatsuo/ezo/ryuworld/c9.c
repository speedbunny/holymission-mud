#define PPATH     "/players/tatsuo/ezo/ryuworld/"

inherit PPATH+"genCave";

reset( arg )
{
   ::reset( arg );

   if ( arg )
      return;

   dest_dir = ({ PPATH + "c4", "north",
                 PPATH + "c10", "east",
                 PPATH + "c14", "south",
                 PPATH + "c8", "west"
              });
}
