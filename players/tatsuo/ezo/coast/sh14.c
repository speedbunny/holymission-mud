#define PPATH "/players/tatsuo/ezo/coast/"
#define FPATH "/players/tatsuo/ezo/forest/"

inherit "/players/tatsuo/ezo/coast/genShore";

string short() {
    return "Ezo's shore";
}

reset( arg )
{
/* Now loads from Tatsuos castle.
    if (!find_object("/players/haplo/ishikawa/sampan"))
        catch(call_other("/players/haplo/ishikawa/sampan","???"));
*/
   set_rf_dirs( "" );
   set_shore_dirs( "south and north" );

   ::reset( arg );
   
   if ( arg )
      return;
      
    long_desc=
	"You are standing on the shore of the island of Ezo. The "+
	"ground here is sandy, and you can see the waves rolling in. "+
	"Far, far away, You can see another island on the horizon.  An "+
	"old dock extends out into the nihonese sea here.  The shore "+
        "continues south and north.\n";
   dest_dir = ({ PPATH + "sh12", "north",
                 PPATH + "sh16", "south",
                 FPATH + "f33", "southwest",
                 FPATH + "f28",  "west",
                 FPATH + "f23",  "northwest",
              });
}

init( )
{
   ::init();
}
