#define PPATH     "/players/tatsuo/ezo/ryuworld/"

inherit PPATH+"genCave";

reset( arg )
{
   ::reset( arg );

   if ( arg )
      return;

   dest_dir = ({ PPATH + "c9", "north",
                 PPATH + "c15", "east",
                 PPATH + "c13", "west"
              });
}
