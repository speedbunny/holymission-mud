#define TO (this_object())

inherit "/players/tatsuo/GenObj/storeroom";
reset(arg) {
   if(!sizeof(all_inventory(TO))) {
	transfer( clone_object( "/players/tatsuo/guild/nweap/yari"), TO );
	transfer( clone_object( "/players/tatsuo/guild/nweap/yari"), TO );
	transfer( clone_object( "/players/tatsuo/guild/nweap/sa-tja-koen"), TO);
	transfer( clone_object( "/players/tatsuo/guild/nweap/sa-tja-koen"), TO);
	transfer( clone_object( "/players/tatsuo/guild/nweap/nstick"), TO );
	transfer( clone_object( "/players/tatsuo/guild/nweap/nstick"), TO );
	transfer( clone_object( "/players/tatsuo/guild/nweap/nstick"), TO );
	transfer( clone_object( "/players/tatsuo/guild/nweap/nstick"), TO );
    }
    if (!present("/players/tatsuo/guild/nweap/dart", TO)) {
        transfer(clone_object("/players/tatsuo/guild/nweap/dart"),TO);
        transfer(clone_object("/players/tatsuo/guild/nweap/dart"),TO);
        transfer(clone_object("/players/tatsuo/guild/nweap/dart"),TO);
        transfer(clone_object("/players/tatsuo/guild/nweap/dart"),TO);
    }
    if (!present("/players/tatsuo/guild/nweap/shuriken", TO)) {
        transfer(clone_object("/players/tatsuo/guild/nweap/shuriken"),TO);
        transfer(clone_object("/players/tatsuo/guild/nweap/shuriken"),TO);
        transfer(clone_object("/players/tatsuo/guild/nweap/shuriken"),TO);
        transfer(clone_object("/players/tatsuo/guild/nweap/shuriken"),TO);
        transfer(clone_object("/players/tatsuo/guild/nweap/shuriken"),TO);
        transfer(clone_object("/players/tatsuo/guild/nweap/shuriken"),TO);
        transfer(clone_object("/players/tatsuo/guild/nweap/shuriken"),TO);
        transfer(clone_object("/players/tatsuo/guild/nweap/shuriken"),TO);
        transfer(clone_object("/players/tatsuo/guild/nweap/shuriken"),TO);
    }
  if(!present("/players/tatsuo/guild/nweap/aikuchi",TO)) {
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/aikuchi"),TO);
}
  if(!present("/players/tatsuo/guild/nweap/naginata",TO)) {
transfer(clone_object("/players/tatsuo/guild/nweap/naginata"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/naginata"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/nagimaki"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/nagimaki"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/nagimaki"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/bisento"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/bisento"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/kama"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/kama"),TO);
transfer(clone_object("/players/tatsuo/guild/nweap/kama"),TO);
}
    ::reset( arg );
    if ( !arg ) {
	set_trader( "Yukio Usami" );
	set_info( "Weapon" );
    }
}

check_allow(ob) {
    if ( ob )
	return( ob->query_weapon() );
    return( 0 );
}
