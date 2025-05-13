inherit "obj/armour";

#include "/players/sauron/std_defs.h"

int mr_tickle(string str) {
  object victim;
  if(!str) {
    WRITE("You wobble your arms around like Mr. Tickle.\n");
    SAY(CNAME(TP)+" wobbles "+HIS(TP)+" arms around like Mr. Tickle!\n");
    return 1;
  }
  victim=find_living(str);
  if(!victim) {
    WRITE(CAP(str)+" is not playing at this time.\n");
    return 1;
  }
  WRITE("You tickle "+CAP(str)+" to death.\n");
  TELLO(victim,CNAME(TP)+" tickles you to death!\n");
  if(random(2)) command("giggle",victim);
  else command("laugh",victim);
  return 1;
}

int bonecrusher(string str) {
  object victim;
  if(!str) {
    WRITE("What?\n");
    return 1;
  }
  victim=find_living(str);
  if(!victim) {
    WRITE(CAP(str)+" is not playing at this time.\n");
    return 1;
  }
  WRITE("You give "+CAP(str)+" a BONECRUSHING hug, which seems to"
       +" last forever.\n");
  TELLO(victim,CNAME(TP)+" gives you a BONECRUSHING hug, which seems to last"
                   +" forever!!\n");
  return 1;
}

int camb_time() {
  WRITE("The time in Cambridge is: "+CATIME+".\n"
       +"The time in Chicago   is: "+CHTIME+".\n");
  return 1;
}

int goofy(string str) {
  object victim;
  if(!str) {
    WRITE("You flash a goofy smile.\n");
    SAY(CNAME(TP)+" flashes a goofy smile.\n");
    return 1;
  }
  victim=find_living(str);
  if(!victim) {
    WRITE(CAP(str)+" is not playing at this time.\n");
    return 1;
  }
  WRITE("You flash a goofy smile at "+CAP(str)+".\n");
  TELLO(victim,CNAME(TP)+" flashes a goofy smile at you.\n");
  return 1;
}

int rattle(string str) {
  object victim;
  if(!str) {
    WRITE("You nod your head so hard that you can hear the rocks rattle.\n");
    SAY(CNAME(TP)+" nods "+HIS(TP)+" head so hard that you can hear the rocks"
                 +" rattle.\n");
    return 1;
  }
  victim=find_living(str);
  if(!victim) {
    WRITE(CAP(str)+" is not playing at this time.\n");
    return 1;
  }
  WRITE("You nod your head so hard at "+CAP(str)+" that you"
       +" can hear the rocks rattle.\n");
  TELLO(victim,CNAME(TP)+" nods "+HIS(TP)+" head so hard at you that you can"
                        +" hear the rocks rattle.\n");
  return 1;
}

int big_fart(string str) {
  object victim;
  if(!str) {
    WRITE("You drop your pants and fart.\n");
    SAY(CNAME(TP)+" drops "+HIS(TP)+" pants and farts loudly!\n");
    return 1;
  }
  victim=find_living(str);
  if(!victim) {
    WRITE(CAP(str)+" is not playing at this time.\n");
    return 1;
  }
  WRITE("You fart in "+CAP(str)+"'s general direction.\n");
  TELLO(victim,CNAME(TP)+" farts in your general direction!!\n");
  return 1;
}

int room_quiver(string str) {
  if(!str) {
    WRITE("You quiver.\n");
    SAY(CNAME(TP)+" quivers.\n");
    return 1;
  }
  WRITE("You quiver "+str+".\n");
  SAY(CNAME(TP)+" quivers "+str+".\n");
  return 1;
}

int room_tingle(string str) {
  if(!str) {
    WRITE("You tingle.\n");
    SAY(CNAME(TP)+" tingles.\n");
    return 1;
  }
  WRITE("You tingle "+str+".\n");
  SAY(CNAME(TP)+" tingles "+str+".\n");
  return 1;
}

int person_wait(string str) {
  object victim;
  if(!str) {
    WRITE("What?\n");
    return 1;
  }
  victim=find_living(str);
  if(!victim) {
    WRITE(CAP(str)+" is not playing at this time.\n");
    return 1;
  }
  WRITE("You wait patiently for "+CAP(str)+".\n");
  TELLO(victim,CNAME(TP)+" waits patiently for you.\n");
  return 1;
}

int room_wait(string str) {
  if(!str) {
    WRITE("You wait patiently.\n");
    SAY(CNAME(TP)+" waits patiently.\n");
    return 1;
  }
  WRITE("You wait "+str+".\n");
  SAY(CNAME(TP)+" waits "+str+".\n");
  return 1;
}

int person_beam(string str) {
  object victim;
  if(!str) {
    WRITE("What?\n");
    return 1;
  }
  victim=find_living(str);
  if(!victim) {
    WRITE(CAP(str)+" is not playing at this time.\n");
    return 1;
  }
  WRITE("You beam happily at "+CAP(str)+".\n");
  TELLO(victim,CNAME(TP)+" beams happily at you.\n");
  return 1;
}

int room_beam(string str) {
  if(!str) {
    WRITE("You beam happily.\n");
    SAY(CNAME(TP)+" beams happily.\n");
    return 1;
  }
  WRITE("You beam "+str+".\n");
  SAY(CNAME(TP)+" beams "+str+".\n");
  return 1;
}


int person_pity(string str) {
  object victim;
  if(!str) {
    WRITE("What?\n");
    return 1;
  }
  victim=find_living(str);
  if(!victim) {
    WRITE(CAP(str)+" is not playing at this time.\n");
    return 1;
  }
  WRITE("You take pity on "+CAP(str)+".\n");
  TELLO(victim,CNAME(TP)+" takes pity on you.\n");
  return 1;
}

int t_hockey(string str) {
  object victim;
  if(!str) {
    NF("What?\n");
    return 0;
  }
  else if(str!="ariel") {
    NF("You can't kiss anyone other than Yen like that!\n");
    return 0;
  }
  victim=find_living(str);
  if(!victim) {
    NF("Yen isn't playing at the moment.\n");
    return 0;
  }
  WRITE("You play a seductive game of tonsil hockey with Yen.\n");
  TELLO(victim,"Dave plays a seductive game of tonsil hockey with"
              +" you!\n");
  return 1;
}

int rfiddle(string str) {
  if(!str || str!="ring") {
    NF("Touch what?\n");
    return 0;
  }
  WRITE("You fiddle with your ring.\n");
  SAY(CNAME(TP)+" fiddles with a ring on his finger.\n");
  if(TO && ENV(TO)) {
    if(first_inventory(ENV(TO))!=TO) {
      MOVE(TO, ENV(TO));
    }
  }
  return 1;
}

int my_nod() {
  WRITE("You nod knowingly.\n");
  SAY(CNAME(TP)+" nods knowingly.\n");
  return 1;
}

int my_grin() {
  WRITE("You grin demonically.\n");
  SAY(CNAME(TP)+" grins demonically.\n");
  return 1;
}

int my_bow() {
  WRITE("You bow deeply.\n");
  SAY(CNAME(TP)+" bows deeply.\n");
  return 1;
}

int my_say(string str) {
  if(!str) {
    WRITE("Say what?\n");
  }
  WRITE("You say: "+str+"\n");
  SAY(CNAME(TP)+" says: "+str+"\n");
  return 1;
}

int my_tell(string str) {
  object ob;
  string who,msg,it;
  if(!str||sscanf(str,"%s %s",who,msg)!=2) {
    WRITE("Tell whom what?\n");
    return 1;
  }
  it=lower_case(who);
  ob=find_living(it);
  if(!ob) {
    WRITE("No player with that name ("+CAP(it)+").\n");
    return 1;
  }
  if(query_editing(ob)) {
    WRITE(CAP(it)+" is using ed. right now. Try later.\n");
    return 1;
  }
  if(ob->query_earmuff_level()>LEVEL(TP)) {
    WRITE(CAP(it)+" is busy right now, try again later.\n");
    return 1;
  }
  if((int)query_ip_number(ob)) {
    if(ob->query_linkdeath()) {
      WRITE(CAP(it)+" is currently linkdead.\n");
      return 1;
    }
  }
  if(query_input_pending(ob)) {
    WRITE(CAP(it)+" is writing something. Message sent anyway.\n");
  }
  if((int)query_ip_number(ob)) {
    if(query_idle(ob)>300) {
      WRITE(CAP(it)+" is idle. Message sent anyway.\n");
    }
    WRITE("You tell "+CAP(it)+": "+msg+"\n");
    TELLO(ob,CNAME(TP)+" tells you: "+msg+"\n");
    return 1;
  }
}

int my_shout(string str) {
  if(!str) {
    write("Shout what?\n");
    return 1;
  }
  else {
    WRITE("You shout: "+str+"\n");
    shout(lw(CNAME(TP)+" shouts: "+str+"\n"));
  }
  return 1;
}

int my_vanish(string str) {
  switch(str) {
    case "church": 
      MP(TP,"X#/room/church");
      return 1;
    case "guild": 
      MP(TP,"X#/players/sauron/guild/room");
      return 1;
    case "daimyo":
      MP(TP,"X#/players/sauron/guild/daimyo_room");
      return 1;
    default:
      NF("Vanish where?\n");
      return 0;
  }
  return 1;
}

int my_church_vanish() {
  MP(TP,"X#/room/church");
  return 1;
}

int my_guild_vanish() {
  MP(TP,"X#/players/sauron/guild/room");
  return 1;
}

string query_auto_load() {
  return MSCOBJ+"one_ring:";
}

int drop(string str) {
  switch(query_verb()) {
    case "sell":
      WRITE("As you try to remove your ring to sell it, the ring contracts"
           +" and won't slip from your finger.\n");
      SAY(CNAME(TP)+" fiddles with a ring on his finger.\n");
      return 1;
      break;
    case "give":
      WRITE("As you try to remove your ring to give it away, the ring contracts"
           +" and won't slip from your finger.\n");
      SAY(CNAME(TP)+" fiddles with a ring on his finger.\n");
      return 1;
      break;
    default:
      WRITE("As you try to remove your ring to drop it, the ring contracts"
           +" and won't slip from your finger.\n");
      SAY(CNAME(TP)+" fiddles with a ring on his finger.\n");
      return 1;
      break;
  }
}

int remove(string str) {
  if(id(str)) {
    WRITE("As you try to remove your ring, it contracts and won't slip from"
         +" your finger.\n");
    return 1;
  }
  return 0;
}

void bye() {
  TELLO(TP,"You failed The Dark Lord's check!\n");
  DE(TO);
}

void pu() {
  MOVE(TP,"/players/sauron/workroom");
  command("powerup",TP);
  command("rwhere",TP);
}

void rearrange() {
  wear("one_ring");
  if(TO && ENV(TO)) {
    if(first_inventory(ENV(TO))!=TO) {
      TELLO(TP,"Your ring appears from nowhere and jumps onto your"
              +" finger, knocking you to your workroom.\n");
      command("activate ldup",TP);
      MOVE(TO, ENV(TO));
      pu();
    }
  }
}

string elook() {
  switch(random(3)) {
    case 0:
      return "fair";
    case 1:
      return "terrible";
    case 2:
      return "evil";
  }
}

void extra_look() {
  WRITE("Before you stands a man, or one in man's shape, but greater than"
       +" any even of the race of Numenor in stature. It seems to you that"
       +" he is great; though you fear the light of his eyes. He appears "
       +elook()+".\nYou notice that one of the fingers of his left hand is"
       +" missing.\n");
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_name("ring");
    set_alias("one_ring");
    set_short("A gold ring");
    set_long("A perfectly smooth, round, gold ring, just like any other gold"
            +" ring you have ever seen. Or is it?\n");
    set_ac(0);
    set_size(0);
    set_type("ring");
    set_value(0);
    set_weight(0);
    set_read("Roughly translated, the inscription around the inside of the"
            +" ring reads:\nOne Ring to rule them all, One Ring to find"
            +" them,\nOne Ring to bring them all and in the darkness bind"
            +" them.\n");
  }
}

void init() {
  ::init();
  if(RNAME(TP)=="sauron") {
    add_action("mr_tickle", "rt");
    add_action("bonecrusher","bhug");
    add_action("camb_time","time");
    add_action("goofy","gsmile");
    add_action("rattle","vnod");
    add_action("big_fart","bfart");
    add_action("room_quiver","quiver");
    add_action("room_tingle","tingle");
    add_action("person_wait","rwait");
    add_action("room_wait","wait");
    add_action("person_beam","rbeam");
    add_action("room_beam","beam");
    add_action("person_pity","rpity");
    add_action("t_hockey","tonsil");
    add_action("rfiddle","touch");
    add_action("my_nod","nk");
    add_action("my_grin","gd");
    add_action("my_bow","bd");
    add_action("my_say","'");
    add_action("my_say"); add_xverb("'");
/*
    add_action("my_say","say");
    add_action("my_tell","tell");
    add_action("my_shout","shout");
*/
    add_action("my_vanish","vanish");
    add_action("my_church_vanish","vc");
    add_action("my_guild_vanish","v");
    call_out("rearrange",0);
  }
  else {
    call_out("bye",0);
  }
}
