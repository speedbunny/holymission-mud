#define PPATH "/players/tatsuo/ezo/forest/"

inherit "/players/tatsuo/ezo/forest/genTree";

reset( arg )
{
   set_down_dir( PPATH + "f9" );

   ::reset( arg );
}

init( )
{
   ::init();
}
