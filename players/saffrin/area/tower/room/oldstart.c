#define GUILD           "mage"                  /* mage guild */
#define GM                "guild/master"
#define LGF                "GUILD.JOIN"
#define SM                "spells/master"
#define TOWER             "/players/saffrin/area/tower/"

inherit "guild/guild_room";

/*-------------------------------------------------------*/
/* All the Advance, Cost, List stuff here                 */
/* All the pretitles, titles and exp levels for a mage.  */
/*-------------------------------------------------------*/

#define TO                this_object()
#define TP                this_player()
#define TPN                TP->query_name()
#define env                environment
#define SAY(x)                tell_room(env(TO),x)

int        done_already = 0;
int        guild;
int        nr_of_spells;                /* for the skill-system */
object     yorel, sign;
mixed      *spells;

void new_reset(int arg) {
  done_already = 1;
  reset(arg);
  return;
}

int init_spell_list(int gid) {

  int i, nr;
  mixed *tmp;

  spells = ({ ({ }), ({ }), ({ }), ({ }), });

  tmp = SM->dump_spells();
  if(!tmp) {
    write("SYSTEM-Error: Empty skill Database!\n");
    return 1;
  };
  for(i = nr = 0; i < sizeof(tmp[0]); i++) {
    if(tmp[2][i] == gid) {
      spells[0]  += ({ tmp[0][i], });
      spells[1]  += ({ tmp[1][i], });
      spells[2]  += ({ tmp[1][i]->level(), });
      spells[3]  += ({ tmp[1][i]->min_speed(), });
      nr++;
    };
  };
  return nr;
}

void reset(int arg) {

  ::reset(arg);

  if(arg) return;

  guild = GM->query_number(GUILD);
  set_guild(guild);

  short_desc = "Mages guild";
  long_desc =
              "Mages guild. The place is dominated by lots of mirrors " +
              "covering the walls. To the west you can see a hallway " +
              "leading deeper into the Tower. The doorway emits a " +
              "lightblue glow. You notice a sign on the wall saying:\n"+
              "                   You can 'start' here now if you like.\n"+
              "Commands: advance,\n" +
              "          list, list [number],\n" +
              "          list all or join.\n";

  property = ({ "no_fight" });
  dest_dir = ({ "room/mount_top2","south",
                TOWER+"room/hall1", "west",
             });
  if(!done_already) {
  call_out("new_reset", 5, 0);
  }
  else {
move_object(clone_object(TOWER+"npc/oldyorel"),
    this_object());
  sign=clone_object(TOWER+"obj/sign");
  move_object(sign,this_object());
  }
}

int re_init() {
  return nr_of_spells = init_spell_list(guild);
}

init() {

  ::init();
  add_action("envoke","envoke");
  add_action("practice","practice");
  add_action("startroom","start");
  if(member_array(TP->query_real_name(), ({ "saffrin", "waldo" })) != -1) {
    add_action("re_init","init_spells");
  }
}

int envoke(string arg) {

  object scep;

  if(!arg) {
    notify_fail("Envoke what?\n");
    return 0;
  }
  if(arg=="scepter" || arg=="scepter of arcanarton") {
    if(scep=present("scepter of arcanarton",TP)) {
      write("As you wave the scapter, a bright flash breaks free of the "+
            "mirrors,\nand the scepter disappears from your hand.\n"+
            "A strange voice forms the words ..\n"+
            "    'Well done, you solved that quest'\n"+
            "                                       .. in your mind.\n");
      destruct(scep);
      return 1;
    }
  }
  write("You cannot envoke that.\n");
  return 1;
}


int do_advance(string arg) {

  int lev, llev, oldlev, oldll, pracs, plevs;

  oldlev = TP->query_level();
  oldll = TP->query_legend_level();
  ::do_advance(arg);
  lev = TP->query_level();
  llev = TP->query_legend_level();
  if(lev + llev == oldlev + oldll + 1) {
    TP->add_practice_sessions(8 + (TP->query_wis() - oldlev) / 2 );
  }
  return 1;
}

int do_join() {

  string qu;

  if(::do_join())
    return 1; /* Joining not possible */

  if (TP->query_int() < 4) {
    write("Mage-Master Yorel tells you: You are too dull to learn spells.\n");
    return 1;
  }  
  if (TP->query_money() < 100) {
    write("Mage-Master Yorel tells you: You don't have enough gold coins.\n" +
          "Mage-Master Yorel tells you: You need to pay 100 gold coins for " +
                           "your mage's robe!\n");
    return 1;
  }
  TP->add_money(-100);
  TP->set_guild(guild);
  write("You pay your fee for joining.\n");
  write("Mage-Master Yorel tells you: Now you are a mage !\n");
  say(TPN + " has joined the mages guild.\n");
  log_file(LGF, TPN + " joins the " + GUILD + "'s guild at " +
                ctime() + "\n");
  TP->add_practice_sessions(10);
  return 1;
}

int query_maxsp(int my_int, int ll) {

  int max,i;

  i   = my_int;
  max = 90 + (i * 12) + (this_player()->query_int() * 5);
  while(i > 0) {
    max += ( i / 2 );
    --i; 
  }
  return max + ll * 10;
}

int query_maxhp(int my_con, int ll) {

  int _hp;

  _hp = 40;
  switch(my_con) {
    case 11..20:
      _hp += 140;
      _hp += (my_con - 10) * 13;
      break;
    case 21..30:
      _hp += 270;
      _hp += (my_con - 20) * 11;
      break;
    case 31..40:
      _hp += 380;
      _hp += (my_con - 30) * 9;
      break;
    default:
      _hp += my_con * 14;
      break;
  }
  if(ll < 11)
    _hp += ll * my_con / 3;
  else
    _hp += 10 * my_con / 3 + (ll - 10) * my_con / 4;
  return _hp;
}

int soul() {

  object s;

  if(s = present("magerobe", TP))
    destruct(s);

  s = clone_object("players/saffrin/guild/soul2");
  if(s)
    move_object(s, TP);
  return 1;
}

/************************** SKILL SYSTEM **************************/

string know_level(int val) {

  string rtc;

  if(val ==   0)      rtc = "not learned";
  else if(val <   10) rtc = "Awful";
  else if(val <   25) rtc = "Bad";
  else if(val <   40) rtc = "Poor";
  else if(val <   60) rtc = "Average";
  else if(val <   80) rtc = "Fine";
  else if(val <   90) rtc = "Good";
  else if(val <   95) rtc = "Very good";
  else if(val <  100) rtc = "Superb";
  else if(val == 100) rtc = "Perfect";
  else                rtc = " ** Strange ** ";

  return rtc;
}

string time_level(int val) {

  string rtc;

  if(val <  -2) rtc = " ** Strange ** ";
  else if(val == -2) rtc = "-----";
  else if(val == -1) rtc = "Immediate";
  else if(val ==  0) rtc = "Very short";
  else if(val ==  1) rtc = "Short";
  else if(val ==  2) rtc = "Average";
  else if(val ==  3) rtc = "Long";
  else if(val ==  4) rtc = "Very long";
  else rtc = "Extremly long";

  return rtc;
}

int act_practice(string arg) {

  mixed *spdat, *mysp;
  int new;

  if(TP->get_skill("mage_practice")[0]<=1) {
    write("You have to go out and earn more experience "
          "before coming here again!\n");
    return 1;
  };

  new = 0;
  spdat = SM->get_spell(arg);
  if(!spdat || spdat[2] != 5) {
    write("You can find no library-entry about this field of knowledge.\n");
    return 1;
  };
  mysp = TP->get_spell(spdat[0]); 
  if(!mysp) {
    new = 1;
    mysp = ({ spdat[0], 0, 100, 5 });
  };
  mysp[3] = spdat[1]->speed(TP->query_level());
  if(mysp[1] > 94) {  
    write("You already know as much in this skill, " +
          "as you ever could learn here.\n");
    return 1;
  };

  if(spdat[1]->level()>TP->query_level()) {
    write("After studing for a while, you're sure, to be too unexperienced"+
          "to master this field of knowledge.\n");
    return 1;
  };

  if(mysp[1] < 25) mysp[1] += 10 + random(10);
  else if(mysp[1] < 40) mysp[1] += 8 + random(8);
  else if(mysp[1] < 50) mysp[1] += 7 + random(7);
  else if(mysp[1] < 60) mysp[1] += 6 + random(6);
  else if(mysp[1] < 70) mysp[1] += 5 + random(5);
  else if(mysp[1] < 80) mysp[1] += 4 + random(4);
  else if(mysp[1] < 90) mysp[1] += 3 + random(3);
  else if(mysp[1] < 95) mysp[1] += 2 + random(2);
  else mysp[1] = 95;

  if(new) {
    write("You start to understand a totally new field of knowledge.\n");
  }
  else {
    write("You improve your knowledge in this field.\n");
    if(mysp[1]>94) {
      mysp[1]=95;
      write("You are now learned in this field.\n");
    };
  };
  TP->change_spell(mysp[0], mysp[1], mysp[2], mysp[3]);
  TP->change_spell(mysp[0], -2, mysp[2], mysp[3]);
  GM->change_skill(TP, "mage_practice",
                   TP->get_skill("mage_practice")[0]-1, 100, 5);
  return 1;
}

void fix_practice() {

  int *pracs, prac, *plevs, plev, i, lev,llev;

  pracs = TP->get_skill("mage_practice");
  plevs = TP->get_skill("mage_prac_lev");
  if(!pracs)
    prac = 1;
  else
    prac = pracs[0];
  if(!plevs)
    plev = 1;
  else
    plev = plevs[0];
  lev  = TP->query_level();
  llev = TP->query_legend_level();
  GM->change_skill(TP,"mage_practice", 0, 500, 5);
  if(lev + llev > plev) {
    for(i = plev; i < lev + llev; i++) prac += 6;
    GM->change_skill(TP, "mage_practice", prac, 500, 5);
    GM->change_skill(TP, "mage_prac_lev", lev + llev, 100, 5);
  }
  return;
}

fix_practice2()
{
    int *pracs, prac, *plevs, plev, i, lev;

    TP->set_con(TP->query_con());
    if(TP->queryenv("mage_fixed")) 
    {
        return 1;
    }

    pracs=TP->get_skill("mage_practice");
    plevs=TP->get_skill("mage_prac_lev");
    if(!pracs || !plevs) return 0;
    prac=pracs[0];
    plev=plevs[0];
    GM->change_skill(TP,"mage_practice",prac+plev*2,500,5);
    TP->setenv("mage_fixed","yep");
    TP->save_me(1);
    write("Fixed. Type 'practice' to check!\n");
    return 1;
}

int practice(string arg) {

  object tp;
  mixed *spdat;
  string msg;
  int i,j;

  tp = TP;
  fix_practice();
  fix_practice2();

  if(tp->query_guild() != guild) {
    write("You have to enroll in the the Colleg of Magii,\n"+
          "to be able to improve your knowledge here.\n");
    return 1;
  };

  if(!TP->get_skill("mage_practice")) {
    GM->change_skill(TP, "mage_practice", 11, 500, 5);
  }

  if(arg)
    return act_practice(arg);

  msg = "Your library-research reveals tomes to the following fields:\n"+
        "------------------------------------------------------------\n"+
  sprintf(" %-20s   %|20s   %|20s\n",
          "Name of field", "Knowledge", "Time to perform") + "\n";
  for(i = j = 0; i < nr_of_spells; i++) {
    if(tp->query_level() >= spells[2][i]) {
      spdat = tp->get_spell(spells[0][i]);
      if(!spdat)
        spdat = ({ spells[0][i], 0, 100, -2, });
      msg += sprintf(" %-20s   %|20s   %|20s\n", spdat[0],
                     know_level(spdat[1]), time_level(spdat[3]) );
      j++;
    };
  };

  msg += "\nYou have " + (tp->get_skill("mage_practice")[0] - 1) +
         " practice sessions left.\n";

  if (!j) {
    write("Sorry, you can't find anything you're able to " +
          "understand at the moment.\n");
    return 1;
  }
  else
    TP->more_string(msg);

  return 1;
}

int query_mage_guild() { return 1; }

int startroom(string a) {

  if(TP->query_guild() != 5) {
    write("You have to go to your own guild.\n");
    return 1;
  }

  if(!a) {
    write("Where do you want to start?  Church or guild?\n");
    return 1;
  }
  a = lower_case(a);
  switch(a) { 
    case "guild":
      TP->start_in_guild(1);
      write("You will start in the guild from now on.\n");
      TP->save_me(1);
      break;
    case "church":
      TP->start_in_guild(0);
      write("You will start in the church from now on.\n");
      TP->save_me(1);
      break;
    default:
      write("You have to start in the guild or the church!\n");
  }
  return 1;
}
