#define TO (this_object())

inherit "/players/tatsuo/GenObj/storeroom";

reset( arg )
{
int i;
   ::reset( arg );
   
 if( !present("kote",this_object() ) )
transfer( clone_object( "/players/tatsuo/guild/narmour/kote"),TO);
transfer( clone_object( "/players/tatsuo/guild/narmour/kote"),TO);
transfer( clone_object( "/players/tatsuo/guild/narmour/kote"),TO);
transfer( clone_object( "/players/tatsuo/guild/narmour/kote"),TO);
 if( !present("kusari-kabuto",this_object() ) )
transfer ( clone_object("/players/tatsuo/guild/narmour/kusari-kabuto"),TO);
transfer ( clone_object("/players/tatsuo/guild/narmour/kusari-kabuto"),TO);
transfer ( clone_object("/players/tatsuo/guild/narmour/kusari-kabuto"),TO);
transfer ( clone_object("/players/tatsuo/guild/narmour/kusari-kabuto"),TO);
transfer ( clone_object("/players/tatsuo/guild/narmour/kusari-kabuto"),TO);
 if( !present("tabi",this_object() ) )
transfer( clone_object( "/players/tatsuo/guild/narmour/tabi"),TO);
transfer( clone_object( "/players/tatsuo/guild/narmour/tabi"),TO);
transfer( clone_object( "/players/tatsuo/guild/narmour/tabi"),TO);
transfer( clone_object( "/players/tatsuo/guild/narmour/tabi"),TO);
transfer( clone_object( "/players/tatsuo/guild/narmour/tabi"),TO);
transfer( clone_object( "/players/tatsuo/guild/narmour/tabi"),TO);
transfer( clone_object( "/players/tatsuo/guild/narmour/tabi"),TO);
if(!present("tekagi",this_object() ) )
transfer( clone_object( "/players/tatsuo/guild/narmour/tekagi"),TO);
transfer( clone_object( "/players/tatsuo/guild/narmour/tekagi"),TO);
   if ( !arg ) {
      set_trader( "Gidayu Nitta" );
      set_info( "Armour" );
   }
}

check_allow( ob )
{
   if ( ob )
      return( ob->query_armour() );
      
   return( 0 );
}
