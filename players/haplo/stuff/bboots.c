#include "/obj/adjust.h"
#include "/players/tamina/defs.h"

#define FILENAME "players/tamina/bboots:"

#define SilentMove(x,y) if(!TP->query_invis()) { say(TPN+ \
        " takes a big step away to the "+ y +" board.\n"); } \
        MO(TP, x); \
        command("look at board", TP); \
        if(!TP->query_invis()) say(CAP(TP->RNAME)+ \
        " rushes in, takes a quick peek at the board and"+ \
        " checks out\nthe latest messages.\n")

#define T_M(x) MPL("by a big jump away",x)

id (str)    { return str=="bboots" || str=="boardboots" || str=="board boots"; }

short ()   { return "Bboots (Board boots V 1.3)"; }

long ()
{ write (
"Available boards:\n\n" +
"     Common boards:                   |     Guild only boards:\n" +
"  (b 1) ... guild ... Adv Guild       |  (b 13) .. bje ...... Jedi Guild\n"+
"  (b 2) ... bpf ..... Players Flame   |  (b 14) .. bma ..... Mages Guild\n"+
"  (b 3) ... bfr ..... Friendship      |  (b 15) .. bni ..... Ninja Board\n"+
"  (b 4) ... bsi ..... Silas' houses   |  (b 16) .. bmk ..... Monks Board\n"+
"  (b 5) ... bps ..... Player Sheriff  |  (b 17) .. bsm ..Summoners Board\n"+
"  (b 6) ... bje0..... Jedi Outer      |  (b 18) .. bdr .....Druids Board\n"+
"  (b 7) ... bbr ..... Barbarian Wall  |  (b 19) .. bsa ... Samurai Board\n"+
"  (b 8) ... bva ..... Vagabond board  |  (b 20) .. bsd ...Samurai Daimyo\n"+
"  (b 9) ... bmd ..... Muds Ads Board  |  (b 21) .. bfi ...Fighters Board\n"+
"  (b 10) .. bpb ..... Players Bugs    |\n"+
"  (b 11) .. bwb ..... Wizards Bugs    |\n"+
"  (b 12) .. bnew .... New World       |\n"+
"   ----  .. bjun .... Jungle          |\n");
     if (TP->query_immortal() || TP->query_testchar())
     write (
"\n     Wiz only boards:\n"+
"  (b 22) ... inner .... Adv Inner     |  (b 27) .. bch ..... Code Changes\n"+
"  (b 23) ... lpc ...... Adv_inner2    |  (b 28) .. bmn .... Mentors Board\n"+
"  (b 24) ... bwf ...... Wiz Flame     |  (b 29) .. bws ...... Wiz sheriff\n"+
"  (b 25) ... bill ..... illegal       |  (b 30) .. bid ...... Ideas Board\n"+
"  (b 26) ... bg ....... guilds        |  (b 31) .. bq ....... Quest Board\n\n");

     if (TP->RNAME == "tamina")
     write (
"  ---  ..... bwc ...... Women's Chat\n"+
"  ---  ..... bmp ...... Mages Prison\n"+
"  ---  ..... bpr ...... Prison\n");
     write (" ");
     write (
"\nFurther commands: find <name>, find_castle <name>\n");
     write (
"  ffind <name>, bsend <name>, so <object>");
     if (TP->LVL > 30) write (", imprison <name>");
     write ("\n");
}

init () 
{
    AA ("find",        "find");  AA ("look_here",        "L");
    AA ("ffind",      "ffind");  AA ("search_object",   "so");
    AA ("goto_board",     "b");  AA ("send_boots",   "bsend");

    AA ("goto_guild", "guild");  AA ("goto_pflame",    "bpf");
    AA ("goto_sex",    "bsex");  AA ("goto_friend",    "bfr");
    AA ("goto_fghant",  "bsi");  AA ("goto_jedi0",    "bje0");
    AA ("goto_psheriff","bps");  AA ("goto_mudads",    "bmd");
    AA ("goto_pbugs",   "bpb");  AA ("goto_wbugs",     "bwb");

    AA ("goto_thief",   "bth");  AA ("goto_fighter",   "bfi");
    AA ("goto_jedi",    "bje");  AA ("goto_mage",      "bma");
    AA ("goto_monk",    "bmk");  AA ("goto_ninja",     "bni");
    AA ("goto_summ",    "bsm");  AA ("goto_mentor",    "bmn");
    AA ("goto_barb",    "bbr");  AA ("goto_vag",       "bva");
    AA ("goto_samurai", "bsa");  AA ("goto_daimyo",    "bsd");
    AA ("goto_dru",     "bdr");  AA ("goto_new",      "bnew");
    AA ("goto_jun",    "bjun");

    if (TP->LVL > 33)            AA ("imprison",  "imprison");

    if (TP->query_immortal()) 
    {
    AA ("goto_inner", "inner");  AA ("goto_lpc",       "lpc");
    AA ("goto_wflame",  "bwf");  AA ("goto_illegal",  "bill");
    AA ("goto_guilds",   "bg");  AA ("goto_change",    "bch");
    AA ("goto_bugs",  "bbugs");  AA ("goto_mprison",   "bmp");   
    AA ("goto_ideas",   "bid");  AA ("goto_quest",      "bq");
    }
    AA ("goto_wsheriff",      "bws");  AA ("rwho",          "xwho");    
    AA ("activate",      "activate");  AA ("send_gtitler", "gsend");
    AA ("find_castle","find_castle");  AA ("wesend",      "wesend");

    if (TP->RNAME == "tamina") 
    {
      AA ("goto_prison","bpr");   
      AA ("ausend",  "ausend");    AA ("muell",      "muell");
      AA ("go",          "go");    AA ("goto_women",   "bwc");
    }
}

get ()   { return 1; }

drop ()  { return 1; }

query_auto_load ()   { return FILENAME; }

goto_board (str) {
  switch (str) {
    case "1":
    case "adv":     goto_guild(); return 1; break;
    case "2":
    case "pflame":  goto_pflame(); return 1; break;
    case "3":
    case "friend":  goto_friend(); return 1; break;
    case "4":
    case "fghant":  goto_fghant(); return 1; break;
    case "5":
    case "psheriff":goto_psheriff(); return 1; break;
    case "6":
    case "jedi0":   goto_jedi0(); return 1; break;
    case "7":
    case "barbarian":goto_barb(); return 1; break;
    case "8":
    case "vagabond" :goto_vag();  return 1; break;
    case "9":
    case "mudads":   goto_mudads(); return 1; break;
    case "10":
    case "pbugs":   goto_pbugs(); return 1; break;
    case "11":
    case "wbugs":    goto_wbugs(); return 1; break;
    case "12":
    case "new":    goto_new(); return 1; break;
    case "13":    
    case "jedi":    goto_jedi(); return 1; break;
    case "14":
    case "mage": goto_mage(); return 1; break;
    case "15":
    case "ninja":   goto_ninja(); return 1; break;
    case "16":
    case "monk":    goto_monk(); return 1; break;
    case "17":
    case "summ":    goto_summ(); return 1; break;
    case "18":
    case "dru":     goto_druid(); return 1; break;
    case "19":
    case "samurai":  goto_sam(); return 1; break;
    case "20":
    case "daimyo":  goto_guilds(); return 1; break;
    case "21":
    case "fighter":   goto_fighter(); return 1; break;
    case "22":
    case "inner":   goto_inner(); return 1; break;
    case "23":
    case "lpc":     goto_lpc(); return 1; break;
    case "24":
    case "wflame":  goto_wflame(); return 1; break;
    case "25":
    case "illegal":  goto_illegal(); return 1; break;
    case "26":
    case "guilds":  goto_guilds(); return 1; break;
    case "27":
    case "change":  goto_change(); return 1; break;
    case "28":
    case "mentor":  goto_mentor(); return 1; break;
    case "29":
    case "wsheriff":goto_wsheriff(); return 1; break;
    case "30":
    case "ideas":   goto_ideas(); return 1; break;
    case "31":
    case "quest":   goto_quest(); return 1; break;

    case "jungle":  goto_jungle(); return 1; break;
    case "sex":     goto_sex(); return 1; break;
    case "bugs":    goto_bugs();   return 1; break;
    case "prison":  goto_prison(); return 1; break;
    case "mage prison":  goto_mprison(); return 1; break;
    return 0;
  }
}

goto_guild ()    { SilentMove
  ("room/adv_guild","adventurers guild"); return 1; }
goto_pflame ()   { SilentMove
  ("players/calidor/others/board/pla","player flame"); return 1; }
goto_friend ()   { SilentMove
  ("players/rasta/room/bulletin","friendship"); return 1; }
goto_sex ()      { SilentMove
  ("players/whisky/meadow/room/tent","sex"); return 1; }
goto_fghant ()   { SilentMove
  ("players/silas/fghant/ktownhall","silas houses"); return 1; }
goto_jedi0 ()    { SilentMove
  ("players/kelly/guild/room","jedi outer"); return 1; }
goto_mprison ()   { SilentMove
  ("players/dancer/guild/spells/prison","mages prison"); return 1; }
goto_prison ()   { SilentMove
  ("room/prison","prison"); return 1; }
goto_psheriff () { SilentMove
  ("players/acdc/office/player_office","sheriff's"); return 1; }

goto_thief ()    { SilentMove
  ("players/herp/guild/hideout","thiefs guild"); return 1; }
goto_fighter ()  { SilentMove
  ("players/capablanca/guild/restroom","fighters guild"); return 1; }
goto_jedi ()     { SilentMove 
  ("players/kelly/guild/inner","jedi inner"); return 1; }
goto_mage ()     { SilentMove
  ("players/dancer/guild/tower/chamber","mages guild"); return 1; }
goto_monk ()     { SilentMove 
  ("players/whisky/guild/room/c10","monks guild"); return 1; }
goto_ninja ()    { SilentMove
  ("players/patience/ezo/empty","ninjas'"); return 1; }
goto_summ()      { SilentMove
  ("players/matt/guild/rooms/lounge","summoners guild"); return 1; }
goto_mentor()    { SilentMove
  ("players/airborne/mentor/mentor","airborne's mentor board"); return 1; }
goto_barb () { SilentMove
  ("players/moonchild/guild/room","barbarian wall"); return 1; }
goto_vag ()  { SilentMove
  ("players/colossus/guild/room","vagabond guild"); return 1; }
goto_dru ()  { SilentMove
  ("players/meecham/guild/central","druid guild"); return 1; }
goto_pbugs () { SilentMove
  ("players/kbl/boards/player_bug","players' bugs"); return 1; }
goto_wbugs () { SilentMove
  ("players/kbl/boards/wiz_bug","wizards' bugs"); return 1; }
goto_mudads () { SilentMove
  ("players/silas/mudadsroom","MUDS room"); return 1; }

goto_inner()     { SilentMove
  ("room/adv_inner","wiz"); return 1; }
goto_lpc ()      { SilentMove
  ("room/adv_inner2","lpc"); return 1; }
goto_wflame ()   { SilentMove
  ("players/calidor/others/board/wiz","wizards flame"); return 1; }
goto_illegal ()  { SilentMove
  ("players/whisky/genobj/illegal",">illegal items<"); return 1; }
goto_guilds ()   { SilentMove
  ("players/whisky/genobj/guild_room","guild discussion"); return 1; }
goto_ideas ()   { SilentMove
  ("players/whisky/genobj/idea_room","ideas"); return 1; }
goto_change ()   { SilentMove
  ("players/moonchild/changes","code changes"); return 1; }
goto_quest ()   { SilentMove
  ("players/moonchild/quest","quest"); return 1; }
goto_bugs ()     { SilentMove
  ("players/moonchild/misc/bugs_to_fix","game bugs"); return 1; }
goto_wsheriff () { SilentMove
  ("players/acdc/office/wiz_office","wizards sheriff's"); return 1; }
goto_daimyo () { SilentMove
  ("players/tatsuo/guild/daimyo_board","daimyo"); return 1; }
goto_samurai () { SilentMove
  ("players/tatsuo/guild/boardroom","samurai"); return 1; }
goto_new () { SilentMove
  ("players/matt/newworld/entry","new world"); return 1; }
goto_women () { SilentMove
  ("players/tatsuo/guild/kitchen","kitchen"); return 1; }
goto_jun () { SilentMove
  ("players/pace/jungle/rooms/east1", "jungle"); return 1; }

find_castle(str) 
{
  object who;
  who = find_object("players/"+str+"/castle");
  if (!who) 
  {
    write ("Castle of " + str + " not found. *sigh*\n"); return 1;
  }
  if (!environment(who)) 
  {
    write ("That castle is nowhere at the moment.\n"); return 1; 
  }
  write ("players/" +str+ "/castle found at " + file_name(environment(who)) + ".\n");

  return 1;
}

find (target) 
{
    object obj;
    int i;
    if (!target) { write ("You find nothing.\n"); return 1; }
    obj=find_living(target);

    if (!obj) { write ("Unable to find " + target + ".\n"); return 1; }
    obj=environment(obj);

    if (!obj) { write (target + " has no environment. \n"); return 1; }
    write ("\n     " + file_name (obj) + "\n");
    obj->long();
    obj=all_inventory(obj);
    write ("\n     " + sizeof(obj) + " objects in that room.\n\n");
    for (i=0;i<sizeof(obj);i++)
      if (obj[i]->short())
       write (ladjust (i+1,5) + obj[i]->short() + ".\n");
    return 1;
}

look_here(str) {
    object obj; int i; string name;
    if (str) return 0;
    obj=environment(this_player());
    write ("\n     " + file_name (obj) + "\n");
    obj->long();
    obj=all_inventory(obj);
    for (i=0;i<sizeof(obj);i++)
    {
      name = "Invisible object";
      if (obj[i]->short()) name=obj[i]->short();
      if (obj[i]->query_id()) name=obj[i]->query_id();
      if (obj[i]->query_name()) name=obj[i]->query_name();
      if (obj[i]->query_real_name()) name=obj[i]->query_real_name();
      if (!obj[i]->short()) name= ("("+name+")");
      write (ladjust (i+1,3) +
             ladjust (file_name(obj[i]),37) +
             ladjust (capitalize (name) + ".", 38) + "\n");
    }
    return 1;
}

send_boots (who) {
    object boots, player; status b_updated, myself; string s1;
    if (!who) return;
    player=find_living(who);
    if (!player) return;
    if (!player->query_immortal() && !player->query_testchar()) {
      write ("Too low level to receive Board Boots!\n"); return 1; }
    boots = present("bboots",player);
    myself = (player == TP);
    if (boots && sscanf(file_name (boots),"players/tamina/bboots%s",s1)) {
      b_updated = 1; } else b_updated = 0;
      
    MO(CLO("players/tamina/bboots"),player);
    if (myself) { write ("You updated your Bboots.\n"); return 1; }
    if (!b_updated) {
    TOBJ(player, CAP(TP->RNAME) +
       " sent you some fine Board Boots.\n");
    write ("You sent some fine Bboots to " + CAP(who) + ".\n");
    }
    else {
    TOBJ(player, CAP(TP->RNAME) +" updated your Bboots.\n");
    write ("You updated the Bboots of "+CAP(who)+".\n");
    destruct (boots);
    }
    return 1;
}

activate (str) {
  if (!str || !id(str)) return 0;
  MO(TO,E(TO));
  write ("Bboots activated.\n");
  return 1;
}

ffind (str) {
  object what;
  if (!str) str=this_player()->query_real_name();
  what=find_living(str);
  if (!what) what=find_object(str);
  if (!what) {
    write (str + " not found, sorry.\n"); return 1;
  }
  write (str + " (" + file_name(what) + ") found at: ");
  if (environment(what))
    write (file_name(environment(what)));
  else write (file_name(what));
  write ("\n");
  return 1;
}

imprison (who) {
  object player, *u; int i, lv; status permission; 
  if (!who) notify_fail ("imprison whom?\n");
  player = find_player (who);
  if (!player) notify_fail ("That player is not logged on\n");
  /* security check to avoid abuse */
  permission = 1; lv= this_player()->query_level();
  if (lv < 33) {
    u=users();
    for (i=0;i<sizeof(u);i++) {
      if (u[i] -> query_level() > lv && u[i]->query_idle() < 120)
        permission = 0;
    }
  }
  if (!permission) {
    write ("You should better let a higher level do that.\n"); return 1; }
  player->move_player("into prison","room/prison");
  tell_room(environment(player),player->query_name() + 
        " took a big step away into prison.\n");
  write ("You imprisoned " + capitalize (who) + ".\n");
  return 1;
}

search_object (str) {
  object u, ob;
  int i, d, max, sum;

  if (!str) return 0;
  sum = 0;
  u=users();
  max = sizeof (u); d = (max + 1) / 2;
  for (i=0;i<d;i++) {
    write (radjust(u[i]->query_level(),4) + " " +
      ladjust (capitalize(u[i]->query_real_name()),13));
    ob = present (str,u[i]);
    if (ob) {sum++; write (radjust (sum,2) + " " + 
      ladjust(creator(ob),13));} 
    else write ("                ");
    if (i+ d < max) {
      write (radjust(u[i+d]->query_level(),6) + " " +
      ladjust (capitalize(u[i+d]->query_real_name()),13));
    ob = present (str,u[i+d]);
    if (ob) {sum++; write (radjust(sum,2) + " " +
      ladjust (creator(ob),13));}
    }
    write ("\n");
  }
  write ("\n" + sum + " players own a " + str + ".\n\n");
  return 1;
}

rwho (str) { return "players/helenette/rwho"->who(str); }

send_gtitler (who) {
    object gt, player; status gt_updated, myself; string s1;
    if (!who) return;
    player=find_living(who);
    if (!player) return;
    gt=present("gtitler",player);
    myself = (player==this_player());
    if (gt && sscanf(file_name(gt),"players/helenette/obj/gtitler%s",s1)) {
      destruct (gt); gt_updated = 1; } else gt_updated = 0;
      
    gt=(move_object(clone_object("players/helenette/obj/gtitler"),player));
    if (myself) { write ("You updated your gtitler.\n"); return 1; }
    if (!gt_updated) {
    tell_object(player,capitalize(this_player()->query_real_name()) +
       " sent you a gtitler.\n");
    write ("You sent a gtitler to " + capitalize(who) + ".\n");
    }
    else {
    tell_object(player,capitalize(this_player()->query_real_name()) +
       " updated your gtitler.\n");
    write ("You updated the gtitler of " + capitalize(who) + ".\n");
    }
    return 1;
}

wesend (who) {
    object we, player, *inv; string s1; int i;
    if (!who) return;
    player=find_player(who);
    if (!player || 
       (player->query_level()<30 && !player->query_testchar())) return;
    inv=all_inventory(player);
    for (i=0;i<sizeof(inv);i++) {
      if (sscanf(file_name(inv[i]),"players/moonchild/misc/wiz_emote%s,s1")==1)
      we=inv[i];
    }
    if (we) { write ("that player already has a wiz-emote\n"); return 1; }
      
    we=(move_object(clone_object("players/moonchild/misc/wiz_emote"),player));
    tell_object(player,capitalize(this_player()->query_real_name()) +
       " sent you a wiz-emote.\n");
    write ("You sent a wiz-emote to " + capitalize(who) + ".\n");
    
    return 1;
}

ausend (str) {
   object au, player,who,what;
   if (sscanf(str,"%s %s",who,what) != 2) return;
   player=find_player(who);
   if (!player) return;
   au=(move_object(clone_object(what),player));
   return 1;
}

muell (obj) {
  object trash;
  trash=find_object (obj);
  destruct (trash);
  return 1;
}

go (str) {
  object what;
  if (!str) return;
  what=find_object(str);
  if (!what) {
    write (str + " not found, sorry.\n"); return 1;
  }
  move_object(what,environment(this_player()));
  return 1;
}

