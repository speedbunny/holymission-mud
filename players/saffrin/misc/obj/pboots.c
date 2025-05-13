/* Board Boots:(player version) easy access to most of the boards   */
                                                                                                                                        
/* 01-31-94 Editted by Mangla to eliminate the say for invis wizzes */
/*     and removed guild change for jedi guild.                     */
/* 01-31-94 Added barbarian and vagabond guilds to list             */
/* 02-13-94 Removed guild change for monks and sorted guilds        */
/* 12-13-96 Saffrin: Removed all guilds not in use and fixed        */
/*     the paths of the boards themselves.                          */
/* 12-14-96 Saffrin:  Created a players pair of bboots              */

inherit "/obj/armour";
#include "/players/saffrin/defs.h"
#include "/obj/adjust.h"
#define FILENAME "/players/saffrin/misc/pboots:"
#define SilentMove(x,y) if(!TPINV) {\
                          say(TPQN + \
                              " takes a big step away to the " + y + \
                              " board.\n"); } \
                          MOVE(TP,x);  \
                          command("look at board",TP); \
                          if(!TPINV) \
                               say(CRN +\
                                " rushes in, takes a quick peek at the " + \
                                "board and checks out\nthe latest messages.\n")

#define T_M(x) TP->TPMV("does a big jump away", x)


void reset(int flag) {

   ::reset(flag);
   if (flag == 0) {
         set_name("pboots");
         set_alias("boots");
         set_short("Pboots: Players board boots V S1");
         set_long(
                 "A pair of soft black leather boots with an unusal green\n"+
                 "glow on their soles.  Branded into the sides of the boots\n"+
                 "is the word 'helpboots'.\n"
         );
         set_ac(1);
         set_value(200);
         set_weight(0);
         set_size("any");
         set_type("boot");
   }
}

init() {
   ::init();
         AA("goto_board",    "b");
         AA("_helpboots",    "helpboots");

         AA("goto_guild",    "guild");
         AA("goto_pflame",   "bpf");
         AA("goto_www",      "bww");
         AA("goto_friend",   "bfr");
         AA("goto_fghant",   "bsi");
         AA("goto_jedi0",    "bje0");
         AA("goto_psheriff", "bps");
         AA("goto_mudads",   "bmuds");
         AA("goto_bugs",     "bbugs");
         AA("goto_gnome",    "bgnom");
         AA("goto_nworld",   "bnwor");
         AA("goto_clearp",   "bclp");
         AA("goto_amazon",   "bamaz");
}

_helpboots()  {
  write (
         "available boards:\n" +
         "\tb adv .... (b 1) .... guild .... adv_guild\n" +
         "\tb pflame . (b 2) .... bpf ...... player_flame\n" +
         "\tb www .... (b 3) .... bww ...... webpage board\n" +
         "\tb fghant . (b 4) .... bsi ...... silas houses\n" +
         "\tb psheriff (b 5) .... bps ...... sheriff's office\n" +
         "\tb jedi0 .. (b 6) .... bje0 ..... outer jedi board\n" +
         "\tb mudads . (b 7) .... bmuds .... mud advertisments\n" +
         "\tb bugs ... (b 8) .... bbugs .... bug board\n"+
         "\tb gnome .. (b 9) .... bgnom .... gnome board\n"+
         "\tb nworld . (b 10) ... bnwor .... newworld board\n"+
         "\tb clearp . (b 11) ... bclp ..... clearing of peacefulness\n"+
         "\tb amazon . (b 12) ... bamaz .... jewel's amazon board\n"
        );

  return 1;
}
  
goto_guild() {
  SilentMove("room/adv_guild","adventurers guild");
  return 1;
}

goto_pflame() {
  SilentMove("players/mangla/rooms/player_flame","player flame");
  return 1;
}

goto_www()  {
  SilentMove("players/jewel/rooms/www","webpage board");
  return 1;
}

goto_fghant() {
  SilentMove("players/silas/fghant/ktownhall","silas houses");
  return 1;
}

goto_psheriff() {
  SilentMove("players/exos/rooms/player_office","sheriff's");
  return 1;
}

goto_jedi0() {
  SilentMove("players/mangla/guild/room","jedi outer");
  return 1;
}

goto_mudads() {
  SilentMove("players/silas/mudadsroom","mud advertisements");
  return 1;
}

goto_bugs() {
  SilentMove("players/mangla/rooms/bug_room","game bugs");
  return 1;
}

goto_gnome() {
  SilentMove("players/whisky/island/room/gnome17","gnome board");
  return 1;
}

goto_nworld() {
  SilentMove("players/matt/newworld/entry","newworld board");
  return 1;
}

goto_clearp() {
  SilentMove("players/nylakoorub/clearing/path/rooms/c017","clearing of peacefulness");
  return 1;
}

goto_amazon() {
  SilentMove("players/jewel/rooms/amazon","jewel's amazon board");
  return 1;
}

/* Closed until area reopens
goto_friend() {
  SilentMove("players/rasta/room/bulletin","friendship");
  return 1;
}
*/

goto_board(string str) {

  switch (str) {

    case "1":
    case "adv":
      goto_guild();
      return 1;
      break;

    case "2":
    case "pflame":
      goto_pflame();
      return 1;
      break;

    case "3":
    case "www":
      goto_www();
      return 1;
      break;

    case "4":
    case "fghant":
      goto_fghant();
      return 1;
      break;

    case "5":
    case "psheriff":
      goto_psheriff();
      return 1;
      break;

    case "6":
    case "jedi0":
      goto_jedi0();
      return 1;
      break;

    case "7":
    case "mudads":
      goto_mudads();
      return 1;
      break;

    case "8":
    case "bugs":
      goto_bugs();
      return 1;
      break;

    case "9":
    case "gnome":
      goto_gnome();
      return 1;
      break;

    case "10":
    case "nworld":
      goto_nworld();
      return 1;
      break;

    case "11":
    case "clearp":
      goto_clearp();
      return 1;
      break;

    case "12":
    case "amazon":
      goto_amazon();
      return 1;
      break;

    return 0;
  }
}
