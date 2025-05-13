#define TP this_player()
#define TPQN this_player()->query_name()
#define TPQL this_player()->query_level()
object scanee;
object owner,ob;
int trackee,timee,onoff,punched,a;
string track;
 
id(str) { return str=="terminator cpu chip" || str=="cpu chip" || str=="chip" || str=="guild_obj" || str=="ND" || str=="tchip"; }
 
short() { return "Terminator cpu chip"; }
 
long() { write("This kit is proof that you are in the Terminator guild.\n");
         write("Type 'termin' for more info.\n");
    }
 
extra_look() {
  string str;
  str=owner->query_name() + " is a Terminator";
  return str;
}
 
drop() { write("You cannot drop the chip.  It is in your head!\n"); return 1; }
 
get() { return 1; }
 
query_auto_load() { return "/players/silas/private/tchip:"; }
 
init() {
  if(!owner) owner=this_player();
/*
if(TP->query_real_name()=="valchero") {
  write("Hahahahahahahahahahahahaha!!\n");
  write("Thought you could outsmart me eh!\n");
  write("Say bye-bye to terminator guild! *snicker*\n");
  write("The chip falls out of your ear and crumbles into dust!\n");
  destruct(this_object());
  return 1;
}
*/
  add_action("twho","twho");
  add_action("tmess","tmess");
  add_action("chances","chances");
  add_action("termin","termin");
  add_action("gloweye","gloweye");
  if(TPQL >= 20) add_action("recruit","recruit");
  if(TPQL >= 12) add_action("track","track");
  if(TPQL >= 12) add_action("tra","tra");
  if(TPQL >= 3) add_action("emo","emo");
  if(TPQL >= 5) add_action("fixm","fixm");
  if(TPQL >= 10) add_action("fixs","fixs");
  if(TPQL >= 15) add_action("fixc","fixc");
  if(TPQL >= 11) add_action("ppunch","ppunch");
  if(TPQL >= 8) add_action("scan","scan");
  if(TPQL >= 2) add_action("gohome","gohome");
}
 
termin(str) {
  if(!str) {
    write("Congrats!  You are a Terminator!\n");
    write("Here is the commands you do to get more info about that guild.\n");
    write("\n");
    write("termin commands   ---  Get of a list of commands you can do by level.\n");
    write("termin cost       ---  Get a quick list of the cost of each command.\n");
    write("termin emotion    ---  Get a list of the terminator emotions.\n");
    write("termin <command>  ---  Get a description of the command and cost\n");
    write("\n");
    return 1;
  }
  if(str=="commands") {
    write("Terminator commands by level:\n\n");
    write(" 1 -- twho, tmess, chances,\n");
    write(" 2 -- gohome\n");
    write(" 3 -- emo\n");
    write(" 4 -- \n");
    write(" 5 -- fixm\n");
    write(" 6 -- \n");
    write(" 7 -- \n");
    write(" 8 -- scan\n");
    write(" 9 -- \n");
    write("10 -- fixs\n");
    write("11 -- ppunch\n");
    write("12 -- track\n");
    write("13 -- \n");
    write("14 -- \n");
    write("15 -- fixc\n");
    write("16 -- \n");
    write("17 -- \n");
    write("18 -- \n");
    write("19 -- \n");
    write("\n");
    return 1;
  }
  if(str=="emotions") {
    write("Here is a list of extra emotions you get:\n\n");
    write("gloweye,\n");
    write("\n");
    return 1;
  }
  if(str == "chances") {
    write("Chances                                     Free\n");
    write("\n");
    write("The command chances will list all of the abilities\n");
    write("that you can do and the percentage amount for each\n");
    write("of them.\n");
    write("\n");
    write("Usage: chances\n");
    write("\n");
    return 1;
  }
  if(str == "emo") {
    write("Emo                                             10 sp\n");
    write("\n");
    write("This command lets you emote things.  Your name\n");
    write("will be prepended.\n");
    write("This ability uses intelligence for chance.\n");
    write("\n");
    write("Usage: emo 'message'  (emotes 'message')\n");
    write("\n");
    return 1;
  }
  if(str == "fixm") {
    write("Fix minor wounds                                15 sp\n");
    write("\n");
    write("You can either fix minor wounds on yourself or fix\n");
    write("another terminator.  Fixes you of 15 hp.\n");
    write("This ability uses constitution for chance.\n");
    write("\n");
    write("Usage: fixm (for yourself)  fixm 'name' (for another terminator)\n");
    write("\n");
    return 1;
  }
  if(str == "fixs") {
    write("Fix serious wounds                              30 sp\n");
    write("\n");
    write("You can either fix serious wounds on yourself or fix\n");
    write("another terminator.  Fixes you of 30 hp.\n");
    write("This ability uses constitution for chance.\n");
    write("\n");
    write("Usage: fixs (for yourself)  fixs 'name' (for another terminator)\n");
    write("\n");
    return 1;
  }
  if(str == "fixc") {
    write("Fix critical wounds                             50 sp\n");
    write("\n");
    write("You can either fix critical woulds on yourself of fix\n");
    write("another terminator.  Fixes you of 50 hp.\n");
    write("This ability uses constitution for chance.\n");
    write("\n");
    write("Usage: fixc (for yourself)  fixc 'name' (for another terminator)\n");
    write("\n");
    return 1;
  }
  if(str == "ppunch") {
    write("Power punch                                     15 sp\n");
    write("\n");
    write("You can power punch your enemy.  If you power punch\n");
    write("a monster that your are not fighting, a fight will\n");
    write("begin between you.\n");
    write("This ability uses strength and dexterity for chance.\n");
    write("\n");
    write("Usage: ppunch (power punch the thing you are fighting)\n");
    write("       ppunch 'name' (power punch 'name')\n");
    write("\n");
    return 1;
  }
  if(str == "scan") {
    write("Scan                                            30 sp\n");
    write("\n");
    write("Scan is used to what the scanee's wc and ac is, and\n");
    write("how many hp the scanee has.\n");
    write("This ability uses intelligence and wisdom for chance.\n");
    write("\n");
    write("Usage: scan 'name'\n");
    write("\n");
    return 1;
  }
  if(str == "tmess") {
    write("Terminator message                              Free\n");
    write("\n");
    write("The terminator message command lets you give a message\n");
    write("to all of the online terminators.\n");
    write("\n");
    write("Usage: tmess 'message'  (sends the 'message')\n");
    write("\n");
    return 1;
  }
  if(str == "twho") {
    write("Terminator who                                   Free\n");
    write("\n");
    write("The terminator who command gives you a list of all\n");
    write("online terminators and their level.\n");
    write("\n");
    write("Usage: twho\n");
    write("\n");
    return 1;
  }
  if(str == "track") {
    write("Track                                           40 sp\n");
    write("\n");
    write("Tracking is a necessity for terminators.  They need\n");
    write("it to move in on their prey.  The command 'tra' is\n");
    write("related to this command, it costs 5 sp to use.\n");
    write("This ability uses wisdom and dexterity for chance.\n");
    write("\n");
    write("Usage: track 'name'  (begins tracking 'name')\n");
    write("       tra  (used to see the track)\n");
    write("\n");
    return 1;
  }
  write("There is no info on that.\n");
  return 1;
}
 
chances() {
  write("Here are your chances for the terminator abilities:\n\n");
  if(TPQL == 1)
    write("No abilities.\n");
  if(TPQL >= 5)
    write("fixm   - " + (TP->query_con() * 4) + "%\n");
  if(TPQL >= 8)
    write("scan   - " + ((TP->query_int() + TP->query_wis()) * 2) + "%\n");
  if(TPQL >= 9)
    write("emo    - " + (TP->query_int() * 4) + "%\n");
  if(TPQL >= 10)
    write("fixs   - " + (TP->query_con() * 4) + "%\n");
  if(TPQL >= 11)
    write("ppunch - " + ((TP->query_str() + TP->query_dex()) * 2) + "%\n");
  if(TPQL >= 12)
    write("track  - " + ((TP->query_wis() + TP->query_dex()) * 2) + "%\n");
  if(TPQL >= 15)
    write("fixc   - " + (TP->query_con() * 4) + "%\n");
  write("\n");
  return 1;
}
 
twho() {
  object uusers,presob;
  int num;
  int levl;
  string level,special;
  object person;
  uusers=users();
  write("Online Terminators:\n\n");
  for (num=sizeof(uusers)-1; num >= 0; num--) {
    presob=present("tchip",uusers[num]);
    if(presob) {
      person=uusers[num];
      levl=uusers[num]->query_level();
      level="["+levl+"]";
      special="";
      if(uusers[num]->query_real_name()=="silas")
        special="    *Head Terminator*";
      if(levl<100) level="[ "+levl+"]";
      if(levl<10) level="[  "+levl+"]";
        if(uusers[num]->query_name())
          write(level + "  " + person->short() + special +"\n");
    }
  }
  write("\n");
  return 1;
}
 
tmess(str) {
  object uusers,presob;
  int num;
  if(!str || str=="" || str==" ") {
    write("Terminator mess what?\n");
    return 1;
  }
  uusers=users();
  for (num=sizeof(uusers)-1; num >= 0; num--) {
    presob=present("tchip",uusers[num]);
    if(presob) {
      tell_object(uusers[num],"<* " + TPQN + " *> : " + str + "\n");
    }
  }
  return 1;
}
 
gloweye(str) {
  object ob;
  if(!str) {
    write("You stare at everybody with your glowing red eyes.\n");
    say(TPQN + " stares at everybody with glowing red eyes.\n");
    return 1;
  }
  ob=present(lower_case(str),environment(this_player()));
  if(!ob) {
    write(capitalize(str) + " is not here.\n");
    return 1;
  }
  write("You stare at " + capitalize(str) + " with your glowing red eyes.\n");
  say(TPQN + " stares at " + capitalize(str) + " with glowing red eyes.\n");
  return 1;
}
 
recruit(str) {
  object ob,guildob;
  if(!str) { write("Recruit who\n"); return 1; }
  ob=present(lower_case(str),environment(this_player()));
  if(!ob) {
    write(capitalize(str) + " is not here.\n");
    return 1;
  }
  if(!interactive(ob)) {
    write(capitalize(str) + " is not a player.\n");
    return 1;
  }
  write("You recruit " + capitalize(str) + ".\n");
  tell_object(ob,owner->query_name() + " recruits you into the Terminator guild.\n");
  privateob=clone_object("players/silas/guild/tchip");
  move_object(guildob,ob);
  tell_object(ob,"You recieve your Terminator cpu chip.\n");
  return 1;
}
 
track(str) {
  a = 100 - (TP->query_dex() * 4);
  if(!str) { write("Track who?\n"); return 1; }
  if(trackee) {
    write("You stop tracking " + ob->query_name() + ".\n");
    remove_call_out("byetrack");
  }
  ob=present(lower_case(str),environment(this_player()));
  if(!ob) {
    write(capitalize(str) + " is not here!\n");
    return 1;
  }
  if(TP->query_spell_point()<40) {
    write("You don't have enough spell points.\n");
    return 1;
  }
 
  TP->restore_spell_points(-40);
  write("You begin tracking " + capitalize(str) + ".\n");
  write("Type 'tra' to see where " + capitalize(str) + " is.\n");
  call_out("byetrack",600);
  track=str;
  trackee=1;
  return 1;
}
 
tra() {
  int items;
  object inven;
  if(!trackee) {
    write("You aren't tracking anybody.\n");
    return 1;
  }
  if(find_living(track)) {
    items= -1;
    write("You use you terminator skill of tracking and sense:\n\n");
    write(environment(ob)->short()+"\n");
    write("\n");
    inven=first_inventory(environment(ob));
    write("And sense the following objects with " + ob->query_name() + ":\n");
    while(inven) {
      if(inven->short() && inven!=ob) {
        write("- "+inven->short()+"\n");
        items+=1;
      }
      inven=next_inventory(inven);
    }
    if(items<0) write("Nothing.\n");
    write("\n");
    return 1;
  }
  write("The thing you must have been tracking must have died or quit.\n");
  trackee=0;
  return 1;
}
 
byetrack() {
  tell_object(owner,"You lose " + ob->query_name() + "'s track.\n");
  trackee=0;
  return 1;
}
 
emo(str) {
  a = 100 - (TP->query_int() * 4);
  if(!str) { write("Emote what?\n"); return 1; }
  if(TP->query_spell_point()<10) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  if(random(100) > a) {
    TP->restore_spell_points(-10);
    write("You emote: " + str + "\n");
    say("->" + TPQN + str + "\n");
    return 1;
  }
  TP->restore_spell_points(-5);
  write("You fail.\n");
  return 1;
}
 
fixm(str) {
  object obj;
  a = 100 - (TP->query_con() * 4);
  if(TP->query_spell_point()<15) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  if(random(100) > a) {
    TP->restore_spell_points(-15);
    if(!str) {
      write("You fix some minor wounds on yourself.\n");
      say(TPQN + " looks a little better.\n");
      TP->heal_self(15);
      TP->restore_spell_points(-15);
      return 1;
    }
    obj=present(lower_case(str),environment(TP));
    if(!obj) {
      write(capitalize(str) + " is not here.\n");
      return 1;
    }
    if(!interactive(obj)) {
      write("It must be a player.\n");
      return 1;
    }
    if(!present("tchip",obj)) {
      write("You can only fix other Terminators.\n");
      return 1;
    }
    write("You fix some of " + capitalize(str) + "'s minor wounds.\n");
    say(TPQN+" fixes some of " + capitalize(str) + "'s minor wounds.\n");
    obj->heal_self(15);
    return 1;
  }
  TP->restore_spell_points(-8);
  write("You failed.\n");
  return 1;
}
 
fixs(str) {
  object obj;
  a = 100 - (TP->query_con() * 4);
  if(TP->query_spell_point()<30) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  if(random(100) > a) {
    TP->restore_spell_points(-30);
    if(!str) {
      write("You fix some serious wounds on yourself.\n");
      say(TPQN + " looks a better.\n");
      TP->heal_self(30);
      TP->restore_spell_points(-30);
      return 1;
    }
    obj=present(lower_case(str),environment(TP));
    if(!obj) {
      write(capitalize(str) + " is not here.\n");
      return 1;
    }
    if(!interactive(obj)) {
      write("It must be a player.\n");
      return 1;
    }
    if(!present("tchip",obj)) {
      write("You can only fix other Terminators.\n");
      return 1;
    }
    write("You fix some of " + capitalize(str) + "'s serious wounds.\n");
    say(TPQN+" fixes some of " + capitalize(str) + "'s serious wounds.\n");
    obj->heal_self(30);
    return 1;
  }
  TP->restore_spell_points(-15);
  write("You failed.\n");
  return 1;
}
 
fixc(str) {
  object obj;
  a = 100 - (TP->query_con() * 4);
  if(TP->query_spell_point()<50) {
      write("You don't have enough spell points.\n");
      return 1;
  }
  if(random(100) > a) {
    TP->restore_spell_points(-50);
    if(!str) {
      write("You fix some critical wounds on yourself.\n");
      say(TPQN + " looks alot better.\n");
      TP->heal_self(50);
      TP->restore_spell_points(-50);
      return 1;
    }
    obj=present(lower_case(str),environment(TP));
    if(!obj) {
      write(capitalize(str) + " is not here.\n");
      return 1;
    }
    if(!interactive(obj)) {
      write("It must be a player.\n");
      return 1;
    }
    if(!present("tchip",obj)) {
      write("You can only fix other Terminators.\n");
      return 1;
    }
    write("You fix some of " + capitalize(str) + "'s critical wounds.\n");
    say(TPQN+" fixes some of " + capitalize(str) + "'s critical wounds.\n");
    obj->heal_self(50);
    return 1;
  }
  TP->restore_spell_points(-25);
  write("You failed.\n");
  return 1;
}
 
ppunch(str) {
  object pers;
  a = 100 - (TP->query_str() + TP->query_dex()) * 2;
  if(TP->query_spell_point()<15) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  if(punched) {
    write("You hand hurts right now.\n");
    return 1;
  }
  if(!str)
    pers=TP->query_attack();
  else
    pers=present(lower_case(str),environment(TP));
  if(!pers || !living(pers)) {
    write("Power punch who?\n");
    return 1;
  }
  if(random(100) > a) {
    TP->restore_spell_points(-15);
    pers->hit_player(20);
    write("You power punch " + capitalize(str) + ".\n");
    say(TPQN + " power punches " + capitalize(str) + ".\n");
    if(!TP->query_attack()) {
      pers->attacked_by(TP);
    }
    punched=1;
    call_out("ppun",4);
    return 1;
  }
  TP->restore_spell_points(-8);
  write("You failed.\n");
  return 1;
}
 
ppun() {
  punched=0;
  return 1;
}
 
scan(str) {
  object scanee;
  a = 100 - (TP->query_int() + TP->query_wis()) * 2;
  if(!str) { write("Scan who?\n"); return 1; }
  if(TP->query_spell_point()<30) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  scanee=present(lower_case(str),environment(TP));
  if(!scanee) {
    write(capitalize(str) + " is not here.\n");
    return 1;
  }
  if(scanee->query_name()==owner->query_name()) {
    write("You can't scan yourself!\n");
    return 1;
  }
  if(random(100) > a) {
    TP->restore_spell_points(-30);
    write("A little red beam comes from your eye as you scan " + capitalize(str) + ".\n");
    say("A red light comes from " + TPQN + "'s eye and onto " + capitalize(str) + ".\n");
    write("You receive this information:\n\n");
    write("HP - " + scanee->query_hp() + "\n");
    write("WC - " + scanee->query_wc() + "\n");
    write("AC - " + scanee->query_ac() + "\n");
    write("\n");
    return 1;
  }
  TP->restore_spell_points(-15);
  write("You failed.\n");
  return 1;
}
 
 
gohome() {
  if(this_player()->query_spell_point() < 50) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  TP->restore_spell_points(-50);
  write("You speak a word and you leave in a flash of light.\n");
  TP->move_player("leaves in a flash of light#players/frostgiant/termin/hq");
  return 1;
}
