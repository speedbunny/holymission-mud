#define PPATH     "/players/tatsuo/ezo/ryuworld/"

inherit PPATH+"genCave";

reset( arg )
{
   ::reset( arg );

   if ( arg )
      return;

   dest_dir = ({ PPATH + "c8", "north",
                 PPATH + "c14", "east",
                 PPATH + "c12", "west"
              });
}
