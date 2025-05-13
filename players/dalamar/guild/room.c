#define GUILD           "ninja"                 /* ninja guild */
#define GM              "guild/master"
#define LGF             "GUILD.JOIN"
#define CONF            "/players/tatsuo/ezo/fconference"

inherit "guild/guild_room";

/*-------------------------------------------------------*/
/* All the Advance, Cost, List stuff here		 */
/*-------------------------------------------------------*/

#define TO		this_object()
#define TP		this_player()
#define TPN		this_player()->query_name()
#define env		environment
#define SAY(x)		tell_room(env(TO),x)

int	guild;

reset(tick)
{
    ::reset(tick);

    if (tick) return;
    guild=GM->query_number(GUILD);
    set_guild(guild);

    short_desc = "Ninja guild";
    long_desc =
       "This is the guild-room of the ninjas.\n"+
"You notice a sign on the wall saying:\n"+
"                   you can 'start' here now if you like.\n"+
"Commands: cost, advance,\n" +
"          list, list [number],\n" +
"          list all or join.\n";

    dest_dir = ({ "/players/tatsuo/ezo/empty","north",
                  "/room/church","church",
                  "/players/tatsuo/ezo/inner-yard1","west",
                  "/players/tatsuo/ezo/tearoom","south" });
}

init() {
    ::init();
    add_action("startroom","start");
}

do_advance(arg)
{
   ::do_advance(arg);
   this_player()->add_practice_sessions(2);
   return 1;
}

do_join() {


    /* --- quest-blocking --------------------- */
    if ( !TP->query_quests() || !(member_array("shadow_quest",explode(TP->query_quests(),"#"))+1)) 
    {
	write( "You have to free Holy-Mission, before you can join us!\n" );
	return( 1 );
    }
    /* --- needs an eastern religion ------------- */
    if ( TP->query_religion() != "Amaterasu" ) {
	write( "You have to believe in an eastern religion to join the ninjas.\n");
	return( 1 );
    } 
    /* --- is the player banished from the guild ?? ------ */
    if ( CONF->query_is_banished( TP->query_real_name() ) ) {
	write( "You have been banished from the guild, so stay away !!!\n\n" );
	TP->move_player( "this mighty place#/room/church" );
	return( 1 );
    }
    /* --- is the player accepted from the guild ??? ----- */
    if ( !(CONF->query_is_accepted( TP->query_real_name() )) ) {
	write( "You have to talk to a San to join the ninjas.\n" );
	return( 1 );
    }

/* if (::do_join()) return 1; */  /* Joining not possible */

  if (TP->query_money()<100) {
     write("You don't have enough gold coins.\n" +
           "You need to pay 100 gold coins for your mage's robe!\n");
     return 1;
  }
  TP->add_money(-100);
  TP->set_guild(guild);
  write("You pay your fee for joining.\n");
  log_file(LGF,TPN+" joins the "+GUILD+"'s guild at "+
	   ctime(time())+"\n");
  TP->add_practice_sessions(TP->query_level()*2+4);
  commune_ninja( "[*Yoshihiro-San*] "+TP->query_name()+" just joined our guild"+
                 " !\n" );
  return 1;
}

query_maxsp(my_int,ll) {
return( my_int*9 + my_int/3 + 120 + TP->query_legend_level()/3 );
}

query_maxhp(my_con,ll) {
  return( my_con*25+50+TP->query_legend_level()/2);
}

query_maxfp(my_dex,ll) {
   return( my_dex*17+30+TP->query_legend_level()/2 );
}

startroom(a)
{
/* 971009, Uglymouth: dunno why this is set to guild 5 (mages)... fixed it.
    if(this_player()->query_guild()!=5)
*/
    if( (int)this_player()->query_guild() !=
        (int)find_object( "/guild/master" )->query_number( "ninja" ) )
    {
        write("You have to go to your own guild.\n");
        return 1;
    }

    if(!a)
    {
        write("Where do you wnt to start? church or guild ?\n");
        return 1;
    }
    a=lower_case(a);
    switch(a)
    { 
        case "guild":
            this_player()->start_in_guild(1);
            write("You will start in the guild from now on.\n");
            this_player()->save_me(1);
            break;
        case "church":
            this_player()->start_in_guild(0);
            write("You will start in the church from now on.\n");
            this_player()->save_me(1);
            break;
        default:
            write("You have to start in the guild or the church!\n");
    };
    return 1;
}

commune_ninja( str )
{
    object *u;
    int    i;

    u = users();
    for ( i = 0; i < sizeof( u ); i++ )
	if ( u[i]->query_guild() == 8 )
	    tell_object( u[i], str );
}
