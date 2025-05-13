/* Board Boots:(wizard version)easy access to most of the boards    */
                                                                                                                                           
/* 01-31-94 Editted by Mangla to eliminate the say for invis wizzes */
/*     and removed guild change for jedi guild.                     */
/* 01-31-94 Added barbarian and vagabond guilds to list             */
/* 02-13-94 Removed guild change for monks and sorted guilds        */
/* 12-13-96 Saffrin: Removed all guilds not in use and fixed        */
/*     the paths of the boards themselves.                          */
/* 12-14-96 Saffrin: Cleaned up the code a bit                      */

#include "/players/mangla/defs.h"
#include "/obj/adjust.h"
#define FILENAME "/players/saffrin/misc/obj/bboots"
#define SilentMove(x,y) if(!TP->query_invis()) {\
                          say(TP->query_name() + \
                              " takes a big step away to the " + y + \
                              " board.\n"); } \
                          MO(TP,x);  \
                          command("look at board",TP); \
                          if(!TP->query_invis()) \
                            say(capitalize(TP->RNAME) + \
                                " rushes in, takes a quick peek at the " + \
                                "board and checks out\nthe latest messages.\n")

#define T_M(x) TP->MP("does a big jump away", x)

int id(string str) {

  return str=="bboots"
      || str=="boardboots"
      || str=="board boots";
}

string short() {
  return "Bboots (Board boots V 1.2) (worn)";
}

void long() {

  write (
         "available boards:\n" +
         "\tb adv .... (b 1) .... guild .... adv_guild\n" +
         "\tb pflame . (b 2) .... bpf ...... player_flame\n" +
         "\tb www .... (b 3) .... bww ...... webpage board\n" +
         "\tb fghant . (b 4) .... bsi ...... silas houses\n" +
         "\tb psheriff (b 5) .... bps ...... sheriff's office\n" +
         "\tb jedi0 .. (b 6) .... bje0 ..... outer jedi board\n\n" +
         "\tb barbarian(b 7) .... bbr ...... barbarian wall\n" +
         "\tb vagabond (b 8) .... bva ...... vagabond board\n" +
         "\tb thief .. (b 9) .... bth ...... thieves guild\n" +
         "\tb fighter  (b 10) ... bfi ...... fighters guild\n" +
         "\tb jedi ... (b 11) ... bje ...... jedis guild\n" +
         "\tb mage ... (b 12) ... bma ...... mages guild\n" +
         "\tb monk ... (b 13) ... bmk ...... monks board\n" +
         "\tb ninja .. (b 14) ... bni ...... ninjas board\n\n" +
         "\tb inner .. (b 17) ... inner .... adv_inner\n" +
         "\tb lpc .... (b 18) ... lpc ...... adv_inner2\n" +
         "\tb wflame . (b 19) ... bwf ...... wiz_flame\n" +
         "\tb illegal  (b 20) ... bill ..... illegal\n" +
         "\tb guilds . (b 21) ... bg ....... guilds\n" +
         "\tb bugs ... (b 22) ... bbugs .... bug board\n"+
         "\tb ideas .. (b 25) ... bid ...... idea board\n" +
         "\tb wsheriff (b 24) ... bws ...... wiz's sheriff\n"
        );

  write ("\nFurther commands: find <name>, find_castle <name>\n");
  write ("  ffind <name>, bsend <name>, so <object>\n");

  return;
}

void init() {

  add_action("find",          "find");          /* Wizard commands */
  add_action("look_here",     "L");
  add_action("ffind",         "ffind");
  add_action("search_object", "so");
  add_action("goto_board",    "b");
  add_action("send_boots",    "bsend");
  add_action("activate",      "activate");
  add_action("find_castle",   "find_castle");

  add_action("goto_guild",    "guild");         /* Public boards   */
  add_action("goto_pflame",   "bpf");
  add_action("goto_www",      "bww");
  add_action("goto_friend",   "bfr");
  add_action("goto_fghant",   "bsi");
  add_action("goto_jedi0",    "bje0");
  add_action("goto_psheriff", "bps");
  add_action("goto_thief",    "bth");
  add_action("goto_fighter",  "bfi");
  add_action("goto_jedi",     "bje");
  add_action("goto_mage",     "bma");
  add_action("goto_monk",     "bmk");
  add_action("goto_ninja",    "bni");
  add_action("goto_barb",     "bbr");
  add_action("goto_vag",      "bva");

  add_action("goto_inner",    "inner");         /* Wizard boards   */
  add_action("goto_lpc",      "lpc");
  add_action("goto_wflame",   "bwf");
  add_action("goto_illegal",  "bill");
  add_action("goto_guilds",   "bg");
  add_action("goto_bugs",     "bbugs");
  add_action("goto_ideas",    "bid");
  add_action("goto_wsheriff", "bws");
}

int    get ()             { return 1;        }
int    drop ()            { return 1;        }
string query_auto_load () { return FILENAME; }

int goto_guild() {
  SilentMove("room/adv_guild","adventurers guild");
  return 1;
}

int goto_pflame() {
  SilentMove("/room/player/flame","player flame");
  return 1;
}

int goto_www()  {
  SilentMove("players/jewel/rooms/www","webpage board");
  return 1;
}

int goto_fghant() {
  SilentMove("players/silas/fghant/ktownhall","silas houses");
  return 1;
}

int goto_psheriff() {
  SilentMove("/room/player/sheriff","sheriff's");
  return 1;
}

int goto_jedi0() {
  SilentMove("players/mangla/guild/room","jedi outer");
  return 1;
}

int goto_barb() {
  SilentMove ("players/apollo/guild/room","barbarian wall");
  return 1;
}

int goto_vag() {
  SilentMove("players/nylakoorub/guild/room","vagabond guild");
  return 1;
}

int goto_thief() {
  SilentMove("players/blade/guild/hideout","thiefs guild");
  return 1;
}

int goto_fighter() {
  SilentMove("players/gareth/guild/rooms/restroom","fighters guild");
  return 1;
}

int goto_jedi() { 
  SilentMove("players/mangla/guild/inner","jedi inner");
  return 1;
}

int goto_mage() {
  SilentMove("/players/saffrin/area/tower/room/donation","mages guild");
  return 1;
}

int goto_monk() {
  SilentMove("players/whisky/guild/room/c10","monks guild");
  return 1;
}

int goto_ninja() {
  SilentMove("players/patience/ezo/empty","ninjas'");
  return 1;
}

int goto_inner() {
  SilentMove("room/adv_inner","wiz");
  return 1;
}

int goto_lpc() {
  SilentMove("/room/wiz/lpc","lpc");
  return 1;
}

int goto_wflame() {
  SilentMove("/room/wiz/flame","wizards flame");
  return 1;
}

int goto_illegal() {
  SilentMove("/room/wiz/illegal","Illegal items");
  return 1;
}

int goto_guilds() {
  SilentMove("/room/wiz/guild","guild discussion");
  return 1;
}

int goto_bugs() {
  SilentMove("/room/player/bug","game bugs");
  return 1;
}

int goto_ideas()  {
  SilentMove("/room/wiz/idea","idea board");
  return 1;
}

int goto_wsheriff() {
   SilentMove("/room/wiz/sheriff","wizards sheriff's");
  return 1;
}

int goto_friend() {
  SilentMove("players/rasta/room/bulletin","friendship");
  return 1;
}

int goto_board(string str) {

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
    case "barbarian":
      goto_barb();
      return 1;
      break;

    case "8":
    case "vagabond" :
      goto_vag();
      return 1;
      break;

    case "9":
    case "thief":
      goto_thief();
      return 1;
      break;

    case "10":
    case "fighter":
      goto_fighter();
      return 1;
      break;

    case "11":
    case "jedi":
      goto_jedi();
      return 1;
      break;

    case "12":
    case "mage":
      goto_mage();
      return 1;
      break;

    case "13":
    case "monk":
      goto_monk();
      return 1;
      break;

    case "14":
    case "ninja":
      goto_ninja();
      return 1;
      break;

    case "15":
      return 1;
      break;

    case "16":
      return 1;
      break;

    case "17":
    case "inner":
      goto_inner();
      return 1;
      break;

    case "18":
    case "lpc":
      goto_lpc();
      return 1;
      break;

    case "19":
    case "wflame":
      goto_wflame();
      return 1;
      break;

    case "20":
    case "illegal":
      goto_illegal();
      return 1;
      break;

    case "21":
    case "guilds":
      goto_guilds();
      return 1;
      break;

    case "22":
    case "bugs":
      goto_bugs();
      return 1;
      break;

    case "23":
    case "ideas":
      goto_ideas();
      return 1;
      break;

    case "24":
    case "wsheriff":
      goto_wsheriff();
      return 1;
      break;

   case "friend":
      goto_friend();
      return 1;
      break;

    return 0;
  }
}

int find_castle(string str) {

  object who;

  who=find_object("players/"+str+"/castle");
  if (!who) {
    write ("Castle of " + str + " not found. *sigh*\n");
    return 1;
  }
  if(!ENV(who)) {
    write ("That castle is nowhere at the moment.\n");
    return 1;
  }
  write("players/" + str + "/castle found at " +
        file_name(ENV(who)) + ".\n");
  return 1;
}

int find (string target) {

  object obj, *allobj;
  int i,j;

  if (!target) {
    write ("You find nothing.\n");
    return 1;
  }
  obj=find_living(target);
  if (!obj) {
    write ("Unable to find " + target + ".\n");
    return 1;
  }
  obj=environment(obj);
  if (!obj) {
    write (target + " has no environment. \n");
    return 1;
  }
  write ("\n     " + file_name (obj) + "\n");
  obj->long();
  allobj=all_inventory(obj);
  write ("\n     " + sizeof(allobj) + " objects in that room.\n\n");
  for (i=0,j=sizeof(allobj);i<j;i++)
    if (allobj[i]->short())
      write (ladjust (i+1,5) + allobj[i]->short() + ".\n");
  return 1;
}

int look_here(string str) {

  object obj, *allobj;
  int i, j;
  string name;

  if (str) return 0;

  obj = ENV(TP);
  write("\n     " + file_name (obj) + "\n");
  obj->long();
  allobj = all_inventory(obj);
  for (i = 0, sizeof(allobj); i < j; i++) {
    name = "Invisible object";
    if(allobj[i]->short())
      name = allobj[i]->short();
    if(allobj[i]->query_id())
      name = allobj[i]->query_id();
    if(allobj[i]->NAME)
      name = allobj[i]->NAME;
    if(allobj[i]->RNAME)
      name = allobj[i]->RNAME;
    if(!allobj[i]->short())
      name = ("(" + name + ")");
    write(ladjust(i + 1, 3) +
          ladjust(file_name(allobj[i]), 37) +
          ladjust(CAP(name) + ".", 38) + "\n");
  }
  return 1;
}

int send_boots(string who) {

  object boots, player;
  status b_updated, myself;
  string s1;

  if(!who)
    return 0;

  player = find_living(who);
  if(!player)
    return 0;

  if(!player->query_immortal() && !player->query_testchar()) {
    write ("Too low level to receive Board Boots!\n");
    return 1;
  }
  boots  = present("bboots", player);
  myself = (player == TP);
  if(boots && sscanf(file_name (boots),"tools/bboots%s", s1)) {
    b_updated = 1;
  }
  else
    b_updated = 0;

  move_object(clone_object("tools/bboots"), player);
  if(myself) {
    write("You updated your Bboots.\n");
    return 1;
  }
  if(!b_updated) {
    tell_object(player, CAP(TP->RNAME) +
                " sent you some fine Board Boots.\n");
    write("You sent some fine Bboots to " + CAP(who) + ".\n");
  }
  else {
    tell_object(player, CAP(TP->RNAME) +
               " updated your Bboots.\n");
    write("You updated the Bboots of " + CAP(who) + ".\n");
    destruct(boots);
  }
  return 1;
}

int activate(string str) {

  if(!str || !id(str))
    return 0;

  MO(TO, ENV(TO));
  write ("Bboots activated.\n");
  return 1;
}

int ffind(string str) {

  object what;

  if(!str)
    str = TP->RNAME;

  what = find_living(str);
  if(!what)
    what = find_object(str);
  if(!what) {
    write (str + " not found, sorry.\n");
    return 1;
  }
  write(str + " (" + file_name(what) + ") found at: ");
  if (ENV(what))
    write(file_name(ENV(what)));
  else
    write(file_name(what));
  write ("\n");
  return 1;
}

int search_object(string str) {

  object *u, ob;
  int i, d, max, sum;

  if(!str)
    return 0;

  sum = 0;
  u   = users();
  max = sizeof (u);
  d   = (max + 1) / 2;

  for(i = 0; i < d; i++) {
    write(radjust(u[i]->query_level(),4) + " " +
          ladjust (CAP(u[i]->RNAME),13));
    ob = present(str,u[i]);
    if(ob) {
      sum++;
      write("   " + ladjust(creator(ob),13));
    } 
    else
      write("                ");
    if(i + d < max) {
      write(radjust(u[i+d]->LEVEL, 6) + " " +
            ladjust(CAP(u[i+d]->RNAME), 13));
      ob = present(str, u[i+d]);
      if(ob) {
        sum++;
        write ("   " + ladjust (creator(ob), 13));}
      }
    write("\n");
  }
  write("\n" + sum + " players own a " + str + ".\n\n");
  return 1;
}

