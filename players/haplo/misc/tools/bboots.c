/* board boots, for easy access to most of the available boards */
/* Editted by Mangla to eliminate the say for invis wizzes      */
/*     and removed guild change for jedi guild. 01-31-94        */
/* 01-31-94 Added barbarian and vagabond guilds to list         */
/* 02-13-94 Removed guild change for monks and sorted guilds    */

#include "/sys/levels.h"
#include "/obj/adjust.h"
#define FILENAME "tools/bboots:"
#define SilentMove(x,y) if(!this_player()->query_invis()) { say(this_player()->query_name() + \
        " takes a big step away to the " + y + " board.\n"); } \
        move_object(this_player(),x);  \
        command("look at board",this_player()); \
        if(!this_player()->query_invis()) say(capitalize(this_player()->query_real_name()) + \
      " rushes in, takes a quick peek at the board and" + \
      " checks out\nthe latest messages.\n")

#define T_M(x) this_player()->move_player("does a big jump away",x)

id (str)    { return str=="bboots" || str=="boardboots" || str=="board boots"; }

short ()   {
	return;
    return "Bboots (Board boots V 1.2) (worn)"; }

long ()    { write ("available boards:\n" +
      "\n     common boards:\n" +
      "        b adv .... (b 1) .... guild .... adv_guild\n" +
      "        b pflame . (b 2) .... bpf ...... player_flame\n" +
      "        b friend . (b 3) .... bfr ...... friendship\n" +
      "        b fghant . (b 4) .... bsi ...... silas houses\n" +
      "        b psheriff (b 5) .... bps ...... sheriff's office\n" +
      "        b jedi0 .. (b 6) .... bje0 ..... outer jedi board\n" +
      "        b barbarian(b 7) .... bbr ...... barbarian wall\n" +
      "        b vagabond (b 8) .... bva ...... vagabond board\n");
	write (
	  "        b prison .  ----  ... bpr ...... mages prison\n");
    write (
      "\n     guild only boards:\n" +
      "        b thief .. (b 9) .... bth ...... thiefs guild\n" +
      "        b fighter  (b 10) ... bfi ...... fighters guild\n" +
      "        b jedi ... (b 11) ... bje ...... jedis guild\n" +
      "        b mage ... (b 12) ... bma ...... mages guild\n" +
      "        b monk ... (b 13) ... bmk ...... monks board\n" +
      "        b ninja .. (b 14) ... bni ...... ninjas' board\n" +
      "        b summ ... (b 15) ... bsm ...... summoners board\n" +
      "        b samu ... (b 16) ... bsa ...... samurai board\n" );

    if (this_player()->query_immortal()) 
	write (
	  "\n     wiz only boards:\n" +
	  "        b inner .. (b 17) ... inner .... adv_inner\n" +
	  "        b lpc .... (b 18) ... lpc ...... adv_inner2\n" +
	  "        b wflame . (b 19) ... bwf ...... wiz_flame\n" +
	  "        b illegal  (b 20) ... bill ..... illegal\n" +
	  "        b guilds . (b 21) ... bg ....... guilds\n" +
	  "        b change . (b 22) ... bch ...... code changes\n" +
          "        b quest .. (b 23) ... bq ....... quests\n"
	);
    if (this_player()->query_immortal() || this_player()->query_testchar())
	write (
	  "        b wsheriff (b 24) ... bws ...... wiz's sheriff\n");
	write (
	  "        b bugs ...  ---  .... bbugs .... bugs to fix\n");
    write (
      "        b mentor . (b 25) ... bmn ...... mentor board\n" +
      " "
    );
    write ("\nFurther commands: find <name>, find_castle <name>\n");
    write ("  ffind <name>, bsend <name>, so <object>");
    if (this_player()->query_level()>30) write (", imprison <name>");
    write ("\n");
}

init () {
    add_action ("find",        "find");  add_action ("look_here",        "L");
    add_action ("ffind",      "ffind");  add_action ("search_object",   "so");
    add_action ("goto_board",     "b");  add_action ("send_boots",   "bsend");

    add_action ("goto_guild", "guild");  add_action ("goto_pflame",    "bpf");
    add_action ("goto_sex",    "bsex");  add_action ("goto_friend",    "bfr");
    add_action ("goto_fghant",  "bsi");  add_action ("goto_jedi0",    "bje0");
    add_action ("goto_psheriff","bps");

    add_action ("goto_thief",   "bth");  add_action ("goto_fighter",   "bfi");
    add_action ("goto_jedi",    "bje");  add_action ("goto_mage",      "bma");
    add_action ("goto_monk",    "bmk");  add_action ("goto_ninja",     "bni");
    add_action ("goto_summ",    "bsm");  add_action ("goto_mentor",     "bmn");
    add_action ("goto_barb",  "bbr");  add_action ("goto_vag", "bva");
    add_action ("goto_quest", "bq");

    if (this_player()->query_immortal()) {
	add_action ("goto_inner", "inner");  add_action ("goto_lpc",       "lpc");
	add_action ("goto_wflame",  "bwf");  add_action ("goto_illegal",  "bill");
	add_action ("goto_guilds",   "bg");  add_action ("goto_change",    "bch");
	add_action ("goto_bugs",  "bbugs");  add_action ("goto_prison",    "bpr");   
    }

    add_action ("goto_wsheriff","bws");  add_action ("rwho",          "xwho");

    add_action ("activate", "activate"); add_action ("send_gtitler", "gsend");
    add_action ("wesend",     "wesend");
    add_action ("find_castle","find_castle");
    if (this_player()->query_level()>30) add_action ("imprison","imprison");
}

get ()   { return 1; }
drop ()  { return 1; }
query_auto_load ()   { return FILENAME; }

goto_board (str) {
    switch (str) {
    case "1":
    case "adv":     goto_guild(); return 1; break;
    case "23":
    case "quest":   goto_quest(); return 1; break;
    case "22":
    case "change":  goto_change(); return 1; break;
    case "21":
    case "guilds":  goto_guilds(); return 1; break;
    case "20":
    case "illegal": goto_illegal(); return 1; break;
    case "19":
    case "wflame":  goto_wflame(); return 1; break;
    case "18":
    case "lpc":     goto_lpc(); return 1; break;
    case "17":
    case "inner":   goto_inner(); return 1; break;
    case "16":
    case "samu":    goto_samu(); return 1; break;
    case "15":
    case "summ":    goto_summ(); return 1; break;
    case "14":
    case "ninja":   goto_ninja(); return 1; break;
    case "13":
    case "monk":    goto_monk(); return 1; break;
    case "12":
    case "mage":    goto_mage(); return 1; break;
    case "11":
    case "jedi":    goto_jedi(); return 1; break;
    case "10":
    case "fighter": goto_fighter(); return 1; break;
    case "9":
    case "thief":   goto_thief(); return 1; break;
    case "sex":     goto_sex(); return 1; break;
    case "2":
    case "pflame":  goto_pflame(); return 1; break;
    case "5":
    case "psheriff":goto_psheriff(); return 1; break;
    case "6":
    case "jedi0":   goto_jedi0(); return 1; break;
    case "bugs":    goto_bugs();   return 1; break;
    case "prison":  goto_prison(); return 1; break;
    case "24":
    case "wsheriff":goto_wsheriff(); return 1; break;
    case "25":
    case "mentor":goto_mentor(); return 1; break;
    case "7":
    case "barbarian":goto_barb(); return 1; break;
    case "8":
    case "vagabond" :goto_vag();  return 1; break;
    case "3":
    case "friend":goto_friend(); return 1; break;
    case "4":
    case "fghant":goto_fghant(); return 1; break;
	return 0;
    }
}

goto_quest ()    { SilentMove
    ("players/matt/public/questroom","quest"); return 1; }
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
    ("players/mangla/guild/room","jedi outer"); return 1; }
goto_prison ()   { SilentMove
    ("players/llort/guild/prison/prison","mages prison"); return 1; }
goto_psheriff () { SilentMove
    ("players/acdc/office/player_office","sheriff's"); return 1; }

goto_thief ()    { SilentMove
    ("players/blade/guild/hideout","thiefs guild"); return 1; }
goto_fighter ()  { SilentMove
    ("players/gareth/guild/restroom","fighters guild"); return 1; }
goto_jedi ()     { 
    SilentMove ("players/mangla/guild/inner","jedi inner"); return 1; }
goto_mage ()     { SilentMove

    ("players/saffrin/guild/rooms/donation","mages guild"); return 1; }
goto_monk ()     { /* int guild;
      guild=this_player()->query_guild();
      this_player()->set_guild(7); */
    SilentMove ("players/whisky/guild/room/c10","monks guild");
    /* this_player()->set_guild(guild); */ return 1; }
goto_ninja ()    { SilentMove
    ("players/patience/ezo/empty","ninjas'"); return 1; }
goto_summ()      { SilentMove
    ("players/matt/guild/rooms/lounge","summoners guild"); return 1; }
goto_samu()      { SilentMove
    ("players/haplo/guild/boardroom","samurai guild"); return 1; }
goto_mentor()    { SilentMove
    ("players/airborne/mentor/mentor","airborne's mentor board"); return 1; }

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
goto_change ()   { SilentMove
    ("players/moonchild/changes","code changes"); return 1; }
goto_bugs ()     { SilentMove
    ("players/moonchild/misc/bugs_to_fix","game bugs"); return 1; }
goto_wsheriff () { SilentMove
    ("players/acdc/office/wiz_office","wizards sheriff's"); return 1; }
goto_barb () { SilentMove
/*
    ("players/tatsuo/guild/room","barbarian wall");
    ("players/gambit/guild/room","barbarian wall");
*/
    ("players/apollo/guild/room","barbarian wall");
    return 1; }
goto_vag ()  { SilentMove
    ("players/nylakoorub/guild/room","vagabond guild"); return 1; }

find_castle(str) {
    object who;
    who=find_object("players/"+str+"/castle");
    if (!who) {
	write ("Castle of " + str + " not found. *sigh*\n"); return 1;
    }
    if (!environment(who)) {
	write ("That castle is nowhere at the moment.\n"); return 1; }
    write ("players/" + str + "/castle found at " + file_name(environment(who)) + ".\n");

    return 1;
}

find (target) {
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
    boots=present("bboots",player);
    myself = (player==this_player());
    if (boots && sscanf(file_name (boots),"toolsbboots%s",s1)) {
	b_updated = 1; } else b_updated = 0;

    move_object(clone_object("tools/bboots"),player);
    if (myself) { write ("You updated your Bboots.\n"); return 1; }
    if (!b_updated) {
	tell_object(player,capitalize(this_player()->query_real_name()) +
	  " sent you some fine Board Boots.\n");
	write ("You sent some fine Bboots to " + capitalize(who) + ".\n");
    }
    else {
	tell_object(player,capitalize(this_player()->query_real_name()) +
	  " updated your Bboots.\n");
	write ("You updated the Bboots of " + capitalize(who) + ".\n");
	destruct (boots);
    }
    return 1;
}

activate (str) {
    if (!str || !id(str)) return 0;
    move_object(this_object(),environment(this_object()));
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
    if (lv < L_WIZ) {
	u=users();
	for (i=0;i<sizeof(u);i++) {
	    if (u[i] -> query_level() > lv && u[i]->query_idle() < 120)
		permission = 0;
	}
    }
    if (!permission) {
	write ("You should better let a higher level do that.\n"); return 1; }
     player->move_player("into prison","players/mangla/rooms/prison");
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

rwho (str) { return "tools/rwho"->who(str); }

