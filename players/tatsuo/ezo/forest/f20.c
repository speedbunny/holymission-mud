#define PPATH "/players/tatsuo/ezo/forest/"
#define SPATH "/players/tatsuo/ezo/coast/"

inherit "/players/tatsuo/ezo/forest/genForest";

reset( arg )
{
   object tree;

   set_rf_dirs( "" );
   set_up_dir( PPATH + "t20" );

   ::reset( arg );

   tree = present( "strange tree", this_object() );
   if ( tree ) destruct( tree );                   //NO TREE HERE !!!
   
   if ( arg )
      return;
      
   dest_dir = ({ PPATH + "f13",  "north",
                 PPATH + "f14",  "northeast",
                 PPATH + "f21",  "east",
                 PPATH + "f26",  "southeast",
                 PPATH + "f25",  "south",
                 PPATH + "f24",  "southwest",
                 PPATH + "f19",  "west",
                 PPATH + "f12",  "northwest",
              });
}

init( )
{
   ::init();
}
