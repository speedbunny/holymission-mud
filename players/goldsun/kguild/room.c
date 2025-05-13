#define PPATH "/players/goldsun/guild/room/"
#include "tune.h"

#define GUILD   "knight"        /*Knight number to be inserted */
#define GN      15                     /* guild number remove it later  */
#define LGF     "GUILD.JOIN"
#define GM	"guild/master"
#define TP	this_player()

#define CONF    "/players/goldsun/guild/accept_banish"
#define MYFILE  "/players/goldsun/guild/joins.log"

#define SP  11
#define HP  11
#define _lg (this_player()->query_property("knight_legend")+1)
#define HPBASE (_lg*3/2 + HP * 4)
#define SPBASE (_lg + SP * 2)

#define QUESTNEED     "help_hern"
#define ALIGNMENTNEED 200
#define RACE          ({"giant","orc","troll"})
#define RELIGIONNEED  ({"Quercus","Illuvatar"})
#define MONEYNEED     500

inherit "guild/room";
inherit "room/room";

int guild;

reset(arg) {
    object ob;

    "guild/room"::reset(arg);
    "room/room"::reset(arg);

    if (!arg) {
  /*    guild=GM->query_number(GUILD);
        set_guild(guild);
        move_object("obj/book", this_object()); */
        guild=GN;
	short_desc="Guild Hall of the Knights";
        long_desc=
            "This is a Main Hall in the Carmaalot. It \n"+
	    "appears to be the Guild Hall of the Knights.\n"+
	    "Whole room is made of shiny white stone. There\n"+
	    "is a fantastic vault above you. The vault is supported\n"+
	    "by eight antic pillars. On the walls you can see\n"+
	    "lighted torches.\n"
	    "Commands: cost, list, list <number>, list all, advance, join.\n";

dest_dir=({PPATH + "hall","east",
 	   PPATH + "boardroom","north",
	   PPATH + "eastyard","west",
	   PPATH + "pub","south",
	   PPATH + "room/church","church",
                 });

        items=({ 
            "torch","They are fixed to the wall",
            "torches","They are fixed to the wall",
	    "pillar","A antic pillar",
	    "pillars","The antic pillars",
	    "wall","The wall is made of shiny stone",
	    "stone","Whole room is made of white shiny stone",
	    "walls","There are torches on the stone walls",
	    "vault","A fantastic vault"
              });
	property=({ "no_steal","has_fire"});
    }
}


init() {
    "guild/room"::init();
    "room/room"::init();
}


try_attack(ob) { return "room/church"->try_attack(ob); }

light_text(str) {
  write("You light your "+str+" with the torches on the wall.\n");
  say(this_player()->query_name()+" uses the torches on the wall to light a "+str+".\n");
}


do_join()
{
  string quests;

    /*  write( "You cannot join at the moment.\n" );
      return( 1 );
   */

 /* --- alignment-blocking ------------------ */
    
 if ( TP->query_alignment() < ALIGNMENTNEED ) {
      write("If you want to join us, you have to make a lot of good acts.\n");
      return( 1 );
  }

 /* --- race-blocking ----------------------- */
 
 if ( member_array(TP->query_race(),RACE) != -1 ) {
   write("Sorry, but your anatomy and nature don't suit this guild!\n"); 
   return( 1 );
 }

 /* --- quest-blocking --------------------- */

 if ( !TP->query_quests() || (member_array(QUESTNEED,explode(TP->query_quests(),"#"))+1)==-1 ) 
   {
  write( "You have to help wizard of time and destiny, before you can join us!\n" );
  return( 1 );
}

 /* --- needs a  religion ------------- */

if ( member_array(TP->query_religion(),RELIGIONNEED)==-1 ) {
 write( "You have to believe in immortal religion to join the knights.\n");
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
   write( "You have to talk to a Knight of round table to join the knights.\n" );
   return( 1 );
}
 
if (TP->query_money() < MONEYNEED){
  write("You are low of money to join the knights.\n");
  return 1;
}
/*
   if ( !::do_join() ){write("hehe join\n");

       return 1;                     }
  */
    TP->set_guild(guild);
    write("Welcome to the knights !!!\n");
    TP->set_al(1000);
    TP->add_money(-MONEYNEED);

    "/sys/chatd"->do_chat(GN,"<<Knight Goldsun>> "+
    TP->query_name()+" has joined our guild !\n");
    log_file(LGF,TP->query_real_name()+" joins the "+GUILD+"'s guild at "+
      ctime(time())+"\n");
    write_file( MYFILE, TP->query_real_name()+"      joined at " +
      ctime(time())+"\n" );
    return 1;

}

int query_maxsp(int lvl) 
{
  return (SPBASE + lvl * SP);
}
                     
int query_maxhp(int lvl) 
{
  return (HPBASE + lvl * HP);
}
  
int query_player()
{
    return 1;
}

do_advance( arg )
{
    ::do_advance();

/*    if ( TP->query_level() = RTMEM ) */
 return 1;
}
