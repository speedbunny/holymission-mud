#define PPATH ("/players/tatsuo/eastMonst/")
inherit "obj/monster";

reset(arg)
{
    int rnd;
    object wep;
    string wep_name;

    ::reset( arg );

    if ( arg )
	return;

    set_name("hengeyokai");
    set_alias("cat");
    set_level(10);
    set_size(3);
    set_short("a hengeyokai");
   set_long("A hengeyokai is a man-like being who wanders the lands in\n" +
            "search of a cure for his curse.  The curse of turning into a cat \n" +
            "whenever he gets angry or is scared.  He looks like a normal man but\n" +
            "whiskers and sharp like claws on his finger nails change his appearance.\n" +
            "The hengeyokai can transform into any animal but prefers the feline form\n" +
            "which has lived on the island of ezo for centuries.");

    rnd = random( 50 );
    switch( rnd ) {
    case 0..10:
	transfer( wep=clone_object("/players/tatsuo/guild/nweap/kama" ),
	  this_object() );
	break;
    case 11..21:
	transfer( wep=clone_object( "/players/tatsuo/guild/nweap/yari" ),    
	  this_object() );
	break;
    case 22..27:
	transfer( wep=clone_object("/players/tatsuo/guild/nweap/nunchaku"),
	  this_object() );
	break;
    case 28..40:
	transfer( wep=clone_object( "/players/tatsuo/guild/nweap/naginata" ),
	  this_object() );
	break;
    case 41..49:
	transfer( wep=clone_object( "/players/tatsuo/guild/nweap/sa-tja-koen"),
	  this_object() );
	break;
    default: 
	break;
    }

    /* whisky wields now again */
    if (objectp(wep))
    {
	wep_name = wep->query_name();
	command("wield "+wep_name);
    }
    set_dead_ob( "/players/tatsuo/eastMonst/monst_died" );
}

/* removed whisky.. newbiekiller on the way to the guild
init( )
{
   ::init();

   if ( this_player() && this_player()->query_race() == "human" )
      set_aggressive( 1 );
}
  end comment */
