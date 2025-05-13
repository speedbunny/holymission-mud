/* my private display of "who" and "people",  Helenette, 8.9.92  */
#define FILENAME "tools/display"
#define RWHERE "/players/sauron/secure/sys/rwhere"
#define WHEREFROM "/players/sauron/secure/sys/rwhere"
#define VERSION "1.0"
#define LASTCHANGE "19.Mai 1993"
#define DECOR1 "=============================================================================="
#define DECOR2 "------------------------------------------------------------------------------"
#define BLANKS "                                                                              "
#define F_N file_name
#define E environment

id (str)   { return member_array(str,({"display","helenette_display","guildpass"})) +1; }

short ()   {
   object owner, spectator, helenette;
   helenette  = find_player ("helenette");
   owner      = environment (this_object());
   spectator  = this_player();
   if (owner==!spectator)
     tell_object (owner,capitalize(spectator->query_real_name()) + 
      " used " + query_verb() + " on your display.\n"); 
   return "The Display, v#" + VERSION;
   return 1;
}
   
long ()    {
    write (short() + " made by Helenette, last change: " + LASTCHANGE + ".\n\n" +
           
           "    all player table display commands: \n" +          
           "         ip, po, rwhere, weigh  \n\n" +
           
           "    single playerinfo commands:\n" +
           "         ffind < /p/o/f>, hp < /p/l>, ip <p>, rwhere <p>\n\n" +
          
           "    inventory display commands (room/living/object):\n "+
           "         weigh <l>,  L < /l/oe/f> \n\n" +
           
           "    other commands: \n" +
           "         find <l>, so <o> \n\n" +

           "    commands to the usage of the display itself: \n" +
           "         activate display, help <displaycommand>,\n" +
           "         help shortenings = help <>.\n\n");
}

init ()     {
    add_action ("display_hp",       "hp");
//    add_action ("display_ip",       "ip");
    add_action ("display_people",   "po");
//    add_action ("rwhere",           "rwhere");
//    add_action ("rwhere",           "..");
    add_action ("weigh",            "weigh");
    add_action ("activate",         "activate");
    add_action ("help",             "help");
    add_action ("search_object",    "so");
    add_action ("look_here",        "L");
    add_action ("file_find",        "ffind");
    add_action ("find",             "find");
    add_action ("send_display",     "dsend");
    add_action ("look_carefully",   "look");
}

get ()      { return 1; }
drop ()     { return 1; }
query_auto_load () { return FILENAME + ":"; }

level_descending(p1,p2) { int q1, q2, l1, l2;
/*---------------------------------------------------------------------*
 * levelsort: exp decides in case both players have same level         *
 *---------------------------------------------------------------------*/
  l1=p1->query_level();        q1=p1->query_exp();
  l2=p2->query_level();        q2=p2->query_exp();
  if (l1 < l2) return 1; if (l2 < l1) return 0; return (q1 < q2);
}

hostsort(p1,p2) { return (query_ip_number(p1) > query_ip_number(p2)); }
/*---------------------------------------------------------------------*
 * hostsort ">" sorts herp (127.0.0.1) before helenette (140.78.4.19)  *
 *---------------------------------------------------------------------*/
 
namesort(p1,p2) { return (p1->query_real_name()<p2->query_real_name());}
/*---------------------------------------------------------------------*
 * alphabetische Sortierung der reinen Spielernamen                    *
 *---------------------------------------------------------------------*/
 
env_sort(p1,p2) { return Location(p1) > Location(p2); }
/*---------------------------------------------------------------------*
 * makes it easier to find location and size of congregations          *
 *---------------------------------------------------------------------*/

allow_display (obj) {
/*---------------------------------------------------------------------*
 * allow_display returns true, if the obj might be seen by this_player *
 *---------------------------------------------------------------------*/
  return (!(obj->query_invis()) ||        /* either the obj is visible */
     (this_player()->query_immortal() ||  /* or it is a wiz asking     */
      !(obj->query_immortal())));         /* or the obj is a player    */
}

sex (ob) {
/*----------------------------------------------------------------------*
 * sex returns gender as "m", "f", "x" if other                         *
 *----------------------------------------------------------------------*/
  if (ob->query_gender()==1) return ("m");
  if (ob->query_gender()==2) return ("f");
  return ("x");
}

married (ob) {
  return 0;
}

work (object ob) {
/*----------------------------------------------------------------------*
 * gives a rough idea (8 chars) of what the player/wizard is doing      *
 *----------------------------------------------------------------------*/
 object attackedby; string monster, mlevel;
  if (!ob)                         return "bug1    ";
  if (!query_ip_number(ob))        return "linkdead"; 
  if (ob->query_ghost())           return "spooking";
  if (ob->query_editing())         return "editing ";  /* file-editing */
  if (query_input_pending (ob)) {
    if (!E(ob))                    return "at login";
    if (F_N(E(ob)) == "room/post") return "mailing ";
    else
    if (present("board",E(ob)))    return "writing "; /* posting a note */
                                   return "reading ";
  }
  if (ob->query_attack()) {
     attackedby=ob->query_attack();
     mlevel=attackedby->query_level();
     monster=attackedby->query_name();
     return radjust (mlevel,2) + " " + ladjust (monster,5);
     }
  if (!environment(ob)) return "at login";
  if (Location(ob) == "room/church" && query_idle(ob)<=30)   return "chatting";
  if (Location(ob) == "room/shop" && query_idle(ob)<=30)     return "shopping";
  if (Location(ob) == "room/pub2" && ob->query_intoxination()) return "drinking";
  return radjust (idle(ob),8);
}

idle (ob) {
  int idletime, idlemin, sec1, sec2;
  idletime=query_idle(ob);
  idlemin=idletime / 60;
  sec1=(idletime - (idlemin * 60)) / 10;
  sec2=idletime - idlemin*60 - sec1*10;
  return idlemin + ":" + sec1 + sec2;
}

time_display (int t) {
  string tmp; int sec1, sec2;
  tmp = "";
  if (t/43200) { tmp += t/43200 + " D "; t-=(t/43200)*43200; }
  tmp += radjust (t/1800,2) + ":";
  t-=(t/1800)*1800; 
  sec1=t/30 / 10;
  sec2=t/30 - sec1*10;
  tmp += (sec1 +"") + (sec2 +"");
  return tmp;
} /* end time_display (s) */

name (ob) { string n;
  if (ob->query_real_name()) {
    n = ob->query_real_name();
    if (!ob->short()) n = "(" + n + ")";
    else n = " " + capitalize(n);
  }
  else n=" logon";
  return n;
}  

Name (ob) { string name;
   name = ob->short();
   if (!name && ob->query_real_name())
      name = "(" + capitalize (ob->query_real_name()) + ")";
   if (!name) name = "Logon the title less";
   return name;
}

location (ob) {
  string where, s1;
  where = "- fabric of space -";
  if (environment (ob)) where=file_name(environment(ob));
  if (where=="players/"+ob->query_real_name() + "/workroom") where="*";
  if (sscanf(where,"players/"+ob->query_real_name()+"/%s",where))
     where="&/"+where;
  if (sscanf (where,"players/%s",s1)) where = "~/"+s1;
  return where;
}

Location (ob) {
  string where, s1;
  where = "- fabric of space -";
  if (environment (ob)) where=file_name(environment(ob));
  return where;
}

Creator (ob) {
  if (!ob) return "-";
  if (!creator(ob)) return file_name(ob);
  return capitalize (creator(ob));
}

ladjust (str,n) { return extract (str + BLANKS,0,n-1); }
radjust (str,n) { 
 int len;
    len=strlen(BLANKS + str);
    return extract (BLANKS + str,len-n,len);
}

level (ob) {
/*----------------------------------------------------------------*
 * level returns 4 chars of levelnumber                           *
 *----------------------------------------------------------------*/
  string lv; 
  lv = ob->query_level();
  if (lv<30 && ob->query_testchar())
      return ladjust (ob->query_testchar(),3) + " ";
  switch (lv) {
  case   30: return "App ";
  case   31: return "New ";
  case   33: return "Wiz ";
  case   35: return "Sen ";
  case   36: return "Ret ";
  case   40: return "Lrd ";
  case 1000: return "God ";
  default:
  if (lv >= 50 && lv <= 999) return "Arc ";
  if (lv <30) return radjust (lv + " ",4);
  return "bug ";
  }
}

Level (ob) {
/*----------------------------------------------------------------*
 * level returns 3 chars of levelnumber                           *
 *----------------------------------------------------------------*/
  string lv; 
  lv = ob->query_level();
  if (lv<30 && ob->query_testchar())
      return ladjust (ob->query_testchar(),3);
  switch (lv) {
  case   30: return "Ap ";
  case   31: return "Nw ";
  case   33: return "Wz ";
  case   35: return "Sn ";
  case   36: return "Re ";
  case   40: return "Ld ";
  case 1000: return "Gd ";
  default:
  if (lv >= 50 && lv <= 999) return "Ar ";
  if (lv <30) return radjust (lv + " ",3);
  return "<> ";
  }
}

display_hp (player) {
    object who, attackedby; int hp, sp, mhp, msp, intox; string monster;
    if (!player) player=this_player()->query_real_name();
    who= present(player,environment(this_player()));
    if (!who) who=find_living(player);
    if (!who) who=find_object(player);
    if (!who) { write ("not found\n"); return 1; }
    write ("HP: " + who->query_hp() + "(" + who->query_max_hp() + ")    SP: " +
      who->query_spell_points() + "(" + who->query_max_sp() + ")    Intox: " +
      who->query_intoxination());
    monster= " ";
    if (attackedby=who->query_attack()) monster=attackedby->query_name();
    if (who->query_ghost()) write ("    ## some mist ##");
    if (attackedby) write ("   (" + attackedby->query_level() + ") " +
    monster + "  HP: " + attackedby->query_hp() + "(" + 
    attackedby->query_max_hp() + ")");
    write ("\n");
    return 1;
} /* end display_hp */

display_people () {
  object u;
  int i, players, actives;
  string where, level, b1, b2, s1, s2;
  u = sort_array(users(),"env_sort",this_object());
  players=sizeof(u); actives=players;
  write (DECOR2 + "\n" +
  "ip_number       lv g playername      game-age   working location\n");
  for (i=0;i<players;i++) {
     write (ladjust (query_ip_number(u[i]), 16)  +
       radjust (u[i]->query_level(), 2) + " " +
       sex (u[i]) + 
       ladjust (name(u[i]),13) +
       radjust (time_display (u[i]->query_age()),13) + " " +
       work(u[i]) + " " +
       location(u[i]) + "\n");
     if (query_idle(u[i]) > 117) actives--;
  } /* end for (i=0;i<players;i++) */

  write ("------- " + radjust (players,2) + " players (" +
         radjust (actives, 2) + " active) ------- " +
          query_load_average() + " --------\n");
  return 1;
} /* end display_people() */

send_display(str) {
  object who, display, olddisp; status updated;
  if (!str) return 0;
  if ((this_player()->query_real_name()!="helenette"))
     write ("Trying to send the " + short() + " of Helenette\n");
  if (!str) str = this_player()->query_real_name();
  who=find_player(str);
  if (!who) { write ("Receiver not found, sorry.\n"); return 0; };
  if (!interactive(who)) {  /* dont send it to linkdead people secretly */
    write ("That player is not alive.\n"); return; }
  if (who->query_idle() > 300) { /* not to idle people either */
    write ("That player is too sleepy to receive the display.\n"); return 1; }
  if (!who->query_immortal() && !who->query_testchar()) { /* no players!!*/
    write ("Too low level to receive that display!\n"); return 1; }
  updated = olddisp = present ("helenette_display",who);

  display=transfer(clone_object(FILENAME),who);
  if (updated) {
    tell_object (who,this_player()->query_name() + " updated " 
        + short() + "!\n");
    write ("You updated " + short() + " of" + name(who) + ".\n");
    }
  else {
    tell_object (who,this_player()->query_name() + " sent " + short()
        + " to you!\n");
    write ("You sent " + short() + " to" + name(who) + ".\n");
  }
  if (olddisp) destruct (olddisp);
  return 1;
} /* end send_display(str) */

help (str) {
  if (!str) return;
  switch (str) {
  case "so":
    write ("search object --> find all players who have at least one object\n" +
    "of the id==<object> in their visible inventory (not deep-inv).\n");
    break;
  case "ffind":
    write ("Find the filename / short() of the environment of the object.\n" +
    "no argument: myself; arguments: livings, objects, rooms");
    break;
  case "rwhere": case "..":
    write ("The well-loved display where people are calling from.\n" +
    "no argument = whole table; arguments possible: player");
    break;
  case "L":
    write ("Look without argument: look here; \n" +
    "with arguments: like \"I\" (inventory) of the shell.\n");
    break;
  case "hp":
    write ("A single line of HP + SP + Intox. (in combat: + Level + HP of foe)\n" +
    "no argument: myself; arguments possible: any living");
    break;
  case "ip":
    write ("without argument: a host-sorted display with maximum info about sites.\n" +
    "possible argument: a certain player\n");
    break;
  case "display":
    long ();
    break;
  case "weigh":
    write ("Check the weight of the items carried by a player or all weights.\n");
    break;
  case "activate":
    write ("If one of your display commands does not work as another object\n" +
    "has defined the same command and is higher up in your inventory: \n" +
    "\"activate display\" will move " + short() + " to the top of your inventory.\n");
    break;
  case "po":
    write ("Party-orientated display.\n");
    break;
  case "shortenings": case "<>": write (
    "    < > = no argument for default     \n" +
    "    <p> = player                      \n" +
    "    <l> = living (player or npc)      \n" +
    "    <o> = object given by id          \n" +
    "    <eo>= object in environment by id \n" +
    "    <f> = object given by filename    \n");
  return 1;
  default: return 0;
  }
  return 1;
} /* end help(str) */

weigh (pl) {  /* function weigh added on oct 6 1992     --- Helenette */
  object who, inv, u, obj; int sumweight,i,j,maxweight; string file,s1,s2,b;
  if (!pl || pl=="fix") {  /* weigh all players ||  weigh ++ fix all weights */
    /* security-check: dont fix weights just for fun! it makes it too */
    /* difficult to find the bug-producers                            */
    if (pl=="fix" && !this_player()->query_real_name()=="helenette") pl=0;
    u = sort_array(users(),"namesort",this_object());

    write (DECOR1 + "\n" +
      "Level Player...... weights (max)   # mud-location:\n" +
      DECOR2 + "\n");
    for (i=0;i<sizeof(u);i++) {
      if (u[i]->query_invis()) {
        write ("(" + radjust (u[i]->query_level(),2) + ") ("); b=")"; }
      else { write (radjust (u[i]->query_level(),4) + "  "); b=" "; }
      write (ladjust(capitalize(u[i]->query_real_name()) + b,12));
      write (radjust(u[i]->query_weight(),3));
      sumweight=0;
      inv=all_inventory(u[i]);
      for (j=0;j<sizeof(inv);j++) sumweight+=inv[j]->query_weight();
      if (u[i]->query_weight() > sumweight) write (" >");
      else if (u[i]->query_weight() < sumweight) write (" <");
      else write (" =");

      maxweight=(u[i]->query_level() + u[i]->query_str()) / 2 + 10;
      write (radjust(sumweight,3) + " (" + radjust(maxweight,2) + ")");
     
      if (u[i]->query_weight()!=sumweight && pl=="fix") { /* needs fix */
        if(u[i]->add_weight(-u[i]->query_weight()+sumweight))
        write ("#"); /* weight adjusted */
        if (u[i]->query_weight()<sumweight)  { /* adjust failed */
          if (u[i]->query_weight()<maxweight) {
             u[i]->add_weight(-u[i]->query_weight()+maxweight);
             write ("+"); /* weight raised to max-weight */ }
           else write ("!");
        } /*  end of adjust after fail */
      }  /* end of fixing */
      else write (" ");

      write (radjust(j,3) + " " + location(u[i]) + "\n");
    }
    write (DECOR1 + "\n");
    return 1;
  }
  
  /* --------- weigh a special player, given as argument ------------------- */
  who=present(pl,environment(this_player()));
  if (!who) who=find_player(pl);
  if (!who) who=find_living(pl);
  if (!who) { notify_fail ("Not found, sorry.\n"); return 0; }
  sumweight=0;
  write (DECOR1 + "\n" +
    Name(who) +" (" +file_name(who)+ ") now at: " + location (who) +
    " weight: " + who->query_weight() + "(" +
    ((who->query_level() + who->query_str()) / 2 + 10) + ")\n" +
    DECOR2 + "\n");
  write ("Object:............................");
  write ("Creator:.... weight  ..value  WC AC A-Type\n");
  inv=all_inventory(who);
  for (i=sizeof(inv)-1;i>=0;i--) {
    file=file_name(inv[i]);
    if (sscanf(file,"%s#%s",s1,s2)==2) file=s1; { /* if 1 */
      if (sscanf(file,"players/%s",s1)==1) file="~"+s1; {  /* if 2 */
        if (sscanf(file,"%sjojina%s",s1,s2) || !inv[i]->short()) {
          write (ladjust(file + " ",36)); }
        else
          { write (ladjust (inv[i]->short() ,35)+ " "); }
      } /* end if 2 */
    } /* end if 1 */

    if (creator(inv[i]))
      write (ladjust (creator(inv[i]),12));
    else write ("            ");
    write (radjust(inv[i]->query_weight() + " ",4));
    sumweight+=inv[i]->query_weight();
    write (radjust(sumweight + " ",4));
    write (radjust(inv[i]->query_value(),8));
    if (inv[i]->weapon_class())
      write (radjust(inv[i]->weapon_class(),4));
    else write ("    ");
    if (function_exists("weapon_hit",inv[i]))
      write ("#");
    else write (" ");
    /* buggy bei uranus wand ---!! */
    /* if (id(inv[i])=="armour") */
    if (inv[i]->armour_class())
      write (radjust (inv[i]->armour_class()+ " ",3));
    else write ("   ");
    if (inv[i]->query_type())
      write (ladjust(inv[i]->query_type(),7));
    write ("\n");
  }
  write (DECOR1 + "\n");
  return 1;
} /* end weigh (pl) */

activate (str) {
  if (!str || !id(str)) return 0;
  move_object(this_object(),environment(this_object()));
  write ("Display activated.\n");
  return 1;
}

hwho () {
  object u;
  status wiz;
  int i, w, visible, all;
  string line;
  u = sort_array (users(),"level_descending",this_object());
  write (DECOR1 + "\n");
  wiz = 1;
  all = sizeof(u);
  visible = all;
  w=0;
  for (i=0;i<all;i++) {
    
    /* -------- create the line ---------------------------------------- */
    line = level(u[i]) + Name(u[i]) + "\n";
        
    /* display line only if this_player is permitted to see that line -- */
    if (allow_display(u[i])) {
      if (wiz) {
        if (i>0 && !u[i]->query_immortal()) {
          write (DECOR2 + "\n");
          wiz = 0;
        }
        w++;
      }
      write (line);
    }
    else visible--;
  }

  write ("=================" + (visible<10 ? "= " : " ") + visible +
        " user(s) online, " + radjust (w-1,2) + " wizards, " +
        radjust (1+all-w,2) + " players ==================\n");
  return 1;
}

display_ip (str) {
  object *u, ob; int i;
  
  if (str) {
    ob=find_player(str);
    if (!ob) {
       notify_fail ("That player is currently not logged on.\n");
       return 0;
    }
    if (!interactive(ob)) {
      write ("That player is not interactive.\n");
      return 1;
    }
    write ("ip-info for: " + level (ob) + ob->short() +
         " (idle: " + query_idle(ob) + ")\n" +
         ladjust(capitalize (ob->query_real_name()),12) +
         ladjust(query_ip_number(ob),16) +
         ladjust(WHEREFROM->wherefrom (ob),25) +
         query_ip_name(ob) + "\n");
    return 1;
  } 
 
  u = sort_array(users(),"hostsort",this_object());
  for (i=0; i<sizeof(u);i++) {
     write (
     level (u[i]) +
     ladjust(capitalize (u[i]->query_real_name()),12) +
     ladjust(query_ip_number(u[i]),16) +
     ladjust(WHEREFROM->wherefrom (u[i]),25) +
     query_ip_name(u[i]) + "\n");
  }
  return 1;
}

rwhere (str) { return RWHERE->where(str); }

#if 0
misend (str) {
   object what, where; string s1, s2;
   object *u; int i;
   if (sscanf(str,"%s %s",s1,s2) !=2) return;
   what=present(s1,this_player());
   if (!what) what=present(s1,environment(this_player()));
   if (!what) what=find_player(s1);
   if (!what) what=find_living(s1);
   if (!what) what=find_object(s1);
   if (!what) {
     u=users(); i=0;
     while (i<sizeof(u) && !what) { what=present(str,u[i]); i++; }
  }
  if (!what) { notify_fail (s1 + " not found, sorry.\n"); return 0; }

  where=present(s2,environment(this_player()));
  if (!where) where=find_player(s2);
  if (!where) where=find_living(s2);
  if (!where) where=find_object(s2);
  if (!where) {
     u=users(); i=0;
     while (i<sizeof(u) && !where) { where=present(str,u[i]); i++; }
  }
   if (!where) { notify_fail ("Destination not available.\n"); return 0; }
   move_object(what,where);
   return 1;
}
#endif

search_object (str) {
  object u, ob;
  int i, d, max, sum;

  if (!str) return 0;
  sum = 0;
  u=sort_array(users(),"level_descending",this_object());
  max = sizeof (u); d = (max + 2) / 3;
  for (i=0;i<d;i++) {

    write (
      Level(u[i]) + ladjust (capitalize(u[i]->query_real_name()),12));
    ob = present (str,u[i]);
    if (ob) {sum++; write (ladjust(Creator(ob),11));}
    else write (ladjust("-",11));
    write ("|");

    if (i+ d < max) {
      write (Level(u[i+d]) + ladjust (capitalize(u[i+d]->query_real_name()),12));
    ob = present (str,u[i+d]);
    if (ob) {sum++; write (ladjust (Creator(ob),11));}
    else write (ladjust("-",11));
    }
    else write (ladjust(" ",23));
    write ("|");
    
    if (i + d + d < max) {
      write (Level(u[i+d+d]) + ladjust (capitalize(u[i+d+d]->query_real_name()),12));
    ob = present (str,u[i+d+d]);
    if (ob) {sum++; write (ladjust (Creator(ob),11));}
    else write ("-");
    }
    
    write ("\n");
  }
  write ("\n" + sum + "(" + sizeof(u) + ") players own a " + str + ".\n\n");
  return 1;
}

file_find (str) {
  object what, where, *u; int i;
  if (!str) str=this_player()->query_real_name();
  what=present(str,environment(this_player()));
  if (!what) what=find_living(str);
  if (!what) what=find_object(str);
  if (!what) {
    u=users();i=0;
    while (i<sizeof(u) && !what) { what=present(str,u[i]); i++; }
  }
  if (!what) { notify_fail (str + " not found, sorry.\n"); return 0; }

  write (str + " (" + file_name(what) + ") found at:\n");
  where = environment (what);
  if (where) write (file_name(where) + " = " + where->short());
  else write (file_name(what));
  write ("\n");
  return 1;
}

look_here(str) {
  object obj; int i; string name, prt;
  if (!str) obj=environment(this_player());
  if (!obj) obj=present(str,environment(this_player()));
  if (!obj) obj=find_player(str);
  if (!obj) obj=find_living(str);
  if (!obj) obj=find_object(str);
  if (!obj) { notify_fail (str + " not found, cannot look at it.\n"); return 0; }
  
  write (file_name (obj) + "\n");
  obj->long();
  obj=all_inventory(obj);
  for (i=0;i<sizeof(obj);i++) {
    name = 0;
    if (file_name(obj[i])=="players/gruhl/hemska_saker/lookteller")
       name = "(lookteller)";
    if (!name && obj[i]->short()) name=obj[i]->short();
    if (!name && obj[i]->query_id()) name=obj[i]->query_id();
    if (!name && obj[i]->query_real_name()) {
      if (!obj[i]->short()) name= ("(" + obj[i]->query_real_name() + ")");
      else name = capitalize (obj[i]->query_real_name());
    }
    if (!name && obj[i]->query_name()) name=obj[i]->query_name();
    if (!name) name = "(- invisible -)"; /*  objects without short */
   /* write (radjust (i+1,3) + " " + ladjust (name + ".",18) + */
   /*----- wie zum teufel verwendet man sprintf? ------------------ */
    write (sprintf ("%3d  %-39s",i+1,extract(name + ".",0,38)) +
      "  " + file_name(obj[i]) + "\n");
    }
  return 1;
}

find (target) {
  object obj;
  int i;
  if (!target) { notify_fail ("You find nothing.\n"); return 0; }
  obj=find_player(target);
  if (!obj) obj=find_living(target);
  if (!obj) { notify_fail ("Unable to find " + target + ".\n"); return 0; }
  obj=environment(obj);
  write ("\n     " + (obj?file_name (obj):"- in the fabric of space -") + "\n");
  if (!obj) return 1;
  obj->long();
  obj=all_inventory(obj);
  write ("\n     " + sizeof(obj) + " objects in that room.\n\n");
  for (i=0;i<sizeof(obj);i++)
  if (obj[i]->short())
     write (ladjust (i+1,5) + obj[i]->short() + ".\n");
  return 1;
}

look_carefully (str) {
  mixed *items, *item_aliases; int i, n, wiz, pl, o; status comma;
  string junk, lookmsg;
  object *all, here;
  if (!str || str!="carefully") return 0;
       
  write ("\nYou look around carefully:\n\n");
  lookmsg=capitalize (this_player()->query_real_name()) +
   " looks around carefully.\n";

  /* looking carefully you notice first the obvious longdescription */
  here=environment(this_player());
  if (this_player()->query_immortal()) write ("/" + file_name(here) + "\n");
  here->long();
  
  /* insert delay */
  /* ---- you also see the visible objects in this room ------------*/
  all=all_inventory(here);
  wiz = 0; pl = 0; o = 0;
  for (i=0;i<sizeof(all);i++) {
    if (all[i]!=this_player()) {

  /* ---- print visible objects immediately and write lookmsg ----- */
       if (all[i]->short()) {
         write (all[i]->short() + ".\n");
         if (this_player()->short() || all[i]->query_immortal())
           tell_object (all[i],lookmsg);
       }
  
  /* ---- count invisible wiz, players and others ----------------- */
       else {
         if (sscanf(file_name(all[i]),"obj/player#%s",junk)) {

  /* ---- the invis wiz will notice the careful search of the room  */
           if (all[i]->query_immortal()) {
             tell_object (all[i],lookmsg);
             wiz++;
           }
           else {
  /* ---- the invis player will notice it if the searcher is visible */
             if (this_player()->short() && !this_player()->query_immortal())
                tell_object (all[i],lookmsg);
             pl++;
           }
         }
         else o++;
       }
    }
  }
  
  /* ------- check furthermore for interesting items -------------- */
  items=environment(this_player())->query_room("items",items);  
 
  /* --- no itemdescription found and no invis object/player ------ */
  if (!items && pl+o==0 && (wiz==0 || !this_player()->query_immortal())) {
     write ("\nAfter your careful inspection you feel sure there is " +
     "nothing worth\na further examination.\n");
     return 1;
  }

  /* ---- write which itemdescriptions were found ------------------ */
  comma = 0;

  if (items) {
      n = sizeof(items);
      write ("\nYour trained eyes find " + 
        (n == 1 ? "only one" : "following") +
        " interesting item" + (n > 1 ? "s:" : ":") + "\n");
      for (i = 0; i < n; i += 2) {
        item_aliases = items[i];
        if (comma) write (", "); else comma=1;
        if (pointerp(item_aliases))
           write (item_aliases[random(sizeof(item_aliases))]);
           else write (item_aliases);
       }
    write (".\n");
    }

  /* -- no invisible objects or the player has no power to see them:  */
  if (wiz+pl+o==0 || !this_player()->query_immortal() && pl+o==0) return 1;
  
  /* ------ give a hint on invisible dangers: ----------------------- */
  write ((comma ? "Furthermore" : "\nAfter looking around carefully") + " you ");
  if (wiz && !this_player()->query_immortal())
           write ("notice the presence of " + (wiz ==1 ? "an" : "some") +
           " invisible wizard" +
           (wiz > 1 ? "s" : "") + (pl + o = 0 ? ".\n" : ""));
  if (pl)  {if (this_player()->query_immortal())
             write ((wiz>0 && o > 0 ? ",\n" : (wiz==0 ? "notice " : "\nand ")) +
             (pl>1 ? pl + " invisible players" : "an invisible player"));
           else write ("notice some footprints on the ground");
           write ((o == 0 ? "." : "") + "\n"); }
  if (o)   if (this_player()->query_immortal())
             write ((wiz + pl > 0 ? "and\n" : "notice ") +
             (o > 1 ? o : "an") + " invisible object" + (o > 1 ? "s" : "") +
             " on the ground.\n");
           else write ((pl > 0 ? "and you" : "") +
             "get the feeling there is" + (pl ? "\n" : " ") + 
             "something strange in this room.\n");
  return 1;
}

