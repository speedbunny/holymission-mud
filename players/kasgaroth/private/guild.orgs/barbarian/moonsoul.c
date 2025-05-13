#include "lw.h"

#define C    capitalize
#define GM   "guild/master"
#define CS   "guild/master"->change_skill
#define QN   query_name()
#define QRN  query_real_name()
#define QL   query_level()
#define TP   this_player()
#define E    environment()
#define ENV  environment
#define EQPR (string)environment()->query_pronoun()
#define EQPO (string)environment()->query_possessive()
#define EQOB (string)environment()->query_objective()
#define EGS  environment()->get_skill
#define EQE  environment()->queryenv
#define ESE  environment()->setenv
#define EQN  (string)environment()->query_name()
#define CHK_SP(x) if((int)environment()->query_sp() < x)\
	{ write("You are too braindead to do that.\n"); return 1; }\
	else environment()->restore_spell_points(-x)
#define EQM  environment()->query_melee()
#define CHK_GH if(E->query_ghost()) return 0
#define NF   notify_fail

object shadow,next_throw,next_throw_ob,comb_soul;

void de_equip();
void send_mess(string str);
void tell_all_but(object ob, string msg);
string wrap(int i);
string parse_string(string str);
string get_word(string str);

int id(string str) {
  return str=="barbariansoul";
}

int get() {
  return 1;
}

int drop() {
  return 1;
}

string extra_look() {
  string tmp;
  CHK_GH;
  tmp=(string)EQE("TATTOO");
  return lw(C(EQPR) + " has a bold tattoo " + (tmp ? "of " + tmp + " " : "")
	+ "emblazoned on " + (string)EQPO + " " + (string)EQE("TATTOOPOS")
	+ (EQM || comb_soul ? ".\n" + C(EQPR) + " has a wild look in "
	+ EQPO + " eyes" : ""));
}

void init() {
  if(!pointerp(EGS("barbarian_combat")))
    CS(E, "barbarian_combat", 1, 100, 11);
  if(!pointerp(EGS("barbarian_melee")))
    CS(E, "barbarian_melee", 1, 100, 11);
  if(!pointerp(EGS("barbarian_fortitude")))
    CS(E, "barbarian_fortitude", 1, 100, 11);
  if(!pointerp(EGS("barbarian_speed")))
    CS(E, "barbarian_speed", 1, 100, 11);
  if(!EQE("TATTOOPOS"))
    ESE("TATTOOPOS", "brow");
  if(!shadow) {
    shadow=clone_object("players/moonchild/guild/shadow");
    shadow->start_the_shadow(E);
  }
  if(TP!=E)
    return;
  add_action("change_tattoo", "tattoo");
  add_action("change_tattoo_position", "tattooposition");
  add_action("show_tattoo", "show");
  add_action("prepare_combat", "prepare");
  add_action("initiate_melee", "melee");
  add_action("throw_object", "throw");
  add_action("devour_corpse", "devour");
  add_action("show_skills", "skills");
  add_action("bellow_something", "bellow");
  add_action("send_chatline", "barb");
  add_action("send_chatline", "barb/");
  add_action("barbarian_communication", "grunt");
  add_action("barbarian_communication", "howl");
  add_action("barbarian_communication", "growl");
  add_action("flex_muscles", "flex");
  add_action("beat_chest", "chestbeat");
  add_action("bare_teeth", "bare");
  add_action("communicate", "'", 1);
  add_action("communicate", "say");
  add_action("shout_to_all", "shout");
  add_action("whisper", "whisper");
  add_action("tell_player", "tell");
  add_action("no_standard_spells", "missile");
  add_action("no_standard_spells", "shock");
  add_action("no_standard_spells", "fireball");
  add_action("guild_help", "help");
}

static int change_tattoo(string str) {
  CHK_GH;
  if(!str) {
    string tmp;
    tmp=(string)EQE("TATTOO");
    if(!tmp)
      write("Your tattoo is currently a fairly ordinary one.\n");
    else
      writelw("Your tattoo is of " + tmp + ".\n");
    return 1;
  }
  ESE("TATTOO", str);
  return change_tattoo(0);
}

static int change_tattoo_position(string str) {
  CHK_GH;
  if(!str) {
    writelw("Your tattoo is currently on your "
	+ (string)EQE("TATTOOPOS") + ".\n");
    return 1;
  }
  ESE("TATTOOPOS", str);
  return change_tattoo_position(0);
}

int show_tattoo(string str) {
  string tmp;
  CHK_GH;
  if(str!="tattoo")
    return 0;
  tmp=(string)EQE("TATTOO");
  if(!tmp)
    write("You don't have a very exciting tattoo to show off.\n");
  else {
    writelw("You show off your tattoo of " + tmp + ".\n");
    say(lw(EQN + " shows off the tattoo of " + tmp + " that is emblazoned on "
	+ EQPO + " " + (string)EQE("TATTOOPOS") + ".\n"));
  }
  return 1;
}

int prepare_combat(string str) {
  if(str!="for barbarian combat")
    return 0;
  CHK_GH;
  if(comb_soul) {
    write("But you already are in barbarian combat!\n");
    return 1;
  }
  if(EQM) {
    write("You can't prepare for barbarian combat while in a melee!\n");
    return 1;
  }
  CHK_SP(40);
  write("You prepare for barbarian combat.\n");
  say(lw(EQN + " suddenly stretches " + EQPO + " body and starts to flex "
	+ EQPO + " muscles. As " + EQPR + " does this, " + EQPR
	+ " lets out a loud howl and " + EQPO
	+ " eyes start to go out of focus. You realise that " + EQN
	+ " is performing the old rituals of barbarian combat.\n"));
  de_equip();
  move_object(comb_soul=clone_object("players/moonchild/guild/combat_soul"), E);
  return 1;
}

int initiate_melee() {
  object tmp;
  CHK_GH;
  if(comb_soul) {
    write("You can't go into a melee while in barbarian combat!\n");
    return 1;
  }
  if(EQM) {
    write("You already are in a melee!\n");
    return 1;
  }
  if(!(tmp=(object)E->query_attack()) || !present(tmp, ENV(E))) {
    write("You're not attacking anything!\n");
    return 1;
  }
  CHK_SP(25);
  write("You lose control of yourself and let a mad rage take over.\n");
  say(lw(EQN + "'s eyes go out of focus and " + EQPR
	+ " seems to lose all control of " + EQOB + "self!\n"));
  de_equip();
  E->start_melee();
  return 1;
}

void de_equip() {
  object *ai;
  int i,j;
  ai=all_inventory(E);
  j=sizeof(ai);
  for(i=0;i<j;i++) {
    if(ai[i]->query_armour() && ai[i]->query_worn()) {
      E->stop_wearing(ai[i], 1);
      if(ai[i]->short() && !ai[i]->query_worn())
	write("You remove " + (string)ai[i]->short() + ".\n");
    }
    if(ai[i]->query_weapon() && ai[i]->query_wielded()) {
      E->stop_wielding(ai[i]);
      if(ai[i]->short())
	write("You stop wielding " + (string)ai[i]->short() + ".\n");
    }
  }
}

int dont_wield(object ob) {
  return EQM || comb_soul;
}

int throw_object(string str) {
  string ob_name,mon_name;
  object tmp;
  if(next_throw)
    return 1;
  if(!str) {
    NF("Throw what?\n");
    return 0;
  }
  if((sscanf(str, "%s at %s", ob_name, mon_name))!=2) {
    if(!(tmp=(object)E->query_attack()) || !present(tmp, ENV(E))) {
      NF("Throw what?\n");
      return 0;
    }
    ob_name=str;
  }
  else {
    tmp=present(mon_name, ENV(E));
    if(!tmp || !living(tmp)) {
      NF("Throw the " + ob_name + " at what?\n");
      return 0;
    }
  }
  if(ENV(E)->query_property("no_fight")) {
    write("It probably wouldn't be an idea to do that here.\n");
    return 1;
  }
  if(!(next_throw=present(ob_name, E))) {
    switch(ob_name[0..0]) {
      case "a":
      case "e":
      case "i":
      case "o":
      case "u":
      case "y":
	NF("You don't have an " + ob_name + " to throw!\n");
	break;
      default:
	NF("You don't have a " + ob_name + " to throw!\n");
	break;
    }
    next_throw=0;
    return 0;
  }
  if(transfer(next_throw, ENV(E))) {
    NF("You can't throw that!\n");
    next_throw=0;
    return 0;
  }
  transfer(next_throw, E);
  next_throw_ob=tmp;
  return 1;
}

int devour_corpse() {
  object c;
  if(!(c=present("corpse", E)) && !(c=present("corpse", ENV(E)))) {
    NF("I don't see any corpses here.\n");
    return 0;
  }
  if(!E->eat_food((int)c->query_weight()))
    return 1;
  E->heal_self((int)c->query_weight()*4);
  write("You devour the corpse in one gulp.\n");
  say(lw((EQN + " devours the corpse in one gulp, spilling blood and entrails "
	+ "everywhere. You feel quite disgusted at this frankly rather "
	+ "grisly sight.\n")));
  destruct(c);
  call_out("burp", 4 + random(10), 0);
  return 1;
}

void burp() {
  command("burp", E);
}

void time_guild_soul() {
  int w;
  string thrnm,monnm;
  if(comb_soul)
    comb_soul->heart();
  if(!next_throw || !next_throw_ob || !present(next_throw, E)
	|| !present(next_throw_ob, ENV(E))) {
    next_throw=0;
    return;
  }
  if(next_throw->query_wielded())
    E->stop_wielding();
  if(next_throw->query_worn())
    E->stop_wearing(next_throw, 1);
  w=(int)next_throw->query_weight();
  thrnm=(string)next_throw->QN;
  if(!thrnm)
    thrnm=(string)next_throw->short();
  monnm=(string)next_throw_ob->QN;
  if(random((int)next_throw_ob->query_dex()) > (10 + random(w*4))
	&& !transfer(next_throw, next_throw_ob)) {
    tell_object(E, lw("You throw " + thrnm + " at " + monnm + ", but " +
	monnm + " catches it.\n"));
    tell_object(next_throw_ob, lw(EQN + " throws " + thrnm
	+ " at you, but you catch it.\n"));
    tell_all_but(next_throw_ob, lw(EQN + " throws " + thrnm + " at " + monnm
	+ ", but " + monnm + " catches it.\n"));
    next_throw=0;
    return;
  }
  tell_object(E, lw("You throw " + thrnm + " at " + monnm + ".\n"));
  tell_object(next_throw_ob, lw(EQN + " throws " + thrnm
	+ " at you. Ouch, that hurt!\n"));
  tell_all_but(next_throw_ob, lw(EQN + " throws " + thrnm + " at " + monnm
	+ ".\n"));
  w=w * (1 + (int)EGS("barbarian_combat")[0]/10);
  if(w>100)
    w=100;
  E->add_exp((int)next_throw_ob->hit_player(random(w)));
  transfer(next_throw, ENV(E));
  next_throw=0;
}

void tell_all_but(object ob, string msg) {
  object *to;
  int i;
  to=filter_array(all_inventory(ENV(E)), "tell_all_but_filter", this_object(),
	ob);
  for(i=0;i<sizeof(to);i++)
    tell_object(to[i], msg);
}

int tell_all_but_filter(object ob, object ob2) {
  return ob!=E && ob!=ob2;
}

int show_skills() {
  write("Combat......." + wrap((int)EGS("barbarian_combat")[0]) + " [100]\n"
	+ "Melee........" + wrap((int)EGS("barbarian_melee")[0]) + " [100]\n"
	+ "Fortitude...."
	+ wrap((int)EGS("barbarian_fortitude")[0]) + " [100]\n"
	+ "Speed........" + wrap((int)EGS("barbarian_speed")[0]) + " [100]\n");
  return 1;
}

string wrap(int i) {
  switch(i) {
    case 100:  return "" + i;   break;
    case 0..9: return ".." + i; break;
    default:   return "." + i;  break;
  }
}

int bellow_something(string str) {
  if(find_call_out("bellow_message")!=-1)
    return 1;
  if(!str) {
    CHK_SP(20);
    shout("You can hear " + EQN + " bellowing and howling at the world!\n");
    write("You bellow and howl at the world!\n");
    return 1;
  }
  CHK_SP(50);
  write("You start to bellow at the top of your voice.\n");
  shout(EQN + " bellows loudly, so loud the whole of Holy Mission can hear.\n");
  call_out("bellow_message", 2, str);
  return 1;
}

void bellow_message(string str) {
  string msg;
  msg=parse_string(str);
  write("You bawl: " + msg + "\n");
  shout(lw(capitalize(EQPR) + " bawls: " + msg + "\n"));
}

int bellow_filter(object ob) {
  return ob!=E && ((int)ob->query_earmuff_level() <= (int)E->QL);
}

int send_chatline(string str) {
  int i;
  object *u;
  if(!str) {
    write("The Barbarians currently logged in to Holy Mission are:\n\n");
    u=sort_array(filter_array(users(), "gd_filter", this_object(), 0),
	"levelsort", this_object());
    for(i=0;i<sizeof(u);i++) {
      int lev;
      lev=(int)u[i]->QL;
      write(((string)u[i]->QRN=="moonchild") ? "[GM] " : lev>29 ? "[Wz] "
	: lev>9 ? "[" + lev + "] " : "[" + lev + "]  ");
      write(u[i]->short() ? (string)u[i]->short() : "["
	+ (string)capitalize(u[i]->QRN) + "]");
      if(u[i]->queryenv("BARB_OFF")) write(" <offline>");
      write("\n");
    }
    write("=-=-=-=-=-=-=-=-=-= There are " + sizeof(u) + " Barbarians currently online =-=-=-=-=-=-=-=-=-=\n");
    return 1;
  }
  if(str=="/off") {
    write("Guild line switched off.\n");
    ESE("BARB_OFF", 1);
    return 1;
  }
  if(str=="/on") {
    write("Guild line switched on.\n");
    E->unsetenv("BARB_OFF");
    return 1;
  }
  if(query_verb()=="barb/")
    send_mess(lw("<= Barbarian => "
	+ capitalize(EQN) + " " + parse_string(str)) + "\n");
  else
    send_mess(lw("<= Barbarian "
	+ capitalize(EQN) + " => " + parse_string(str)) + "\n");
  return 1;
}

void send_mess(string str) {
  int i,j;
  string *mess;
  object *u;
  u=filter_array(users(), "online_filter", this_object());
  for(i=0;i<sizeof(u);i++)
    tell_object(u[i], str);
}

int levelsort(object p1, object p2) {
  if((string)p1->QRN=="moonchild") return 0;
  if((string)p2->QRN=="moonchild") return 1;
  return (int)p1->QL < (int)p2->QL;
}

int gd_filter(object ob) {
  return (int)ob->query_guild()==11;
}

int online_filter(object ob) {
  return (int)ob->query_guild()==11 && !ob->queryenv("BARB_OFF");
}

int barbarian_communication(string str) {
  object ob;
  string qv;
  qv=query_verb();
  if(!str) {
    say(EQN + " " + qv + "s in a most barbaric manner.\n");
    write("You " + qv + " in a most barbaric manner.\n");
    return 1;
  }
  if(ob=present(str, ENV(E))) {
    say(lw(EQN + " " + qv + "s at " + (string)ob->QN
	+ " in a most barbaric manner.\n"));
    writelw("You " + qv + " at " + (string)ob->QN
	+ " in a most barbaric manner.\n");
    tell_object(ob, lw(EQN + " " + qv
	+ "s at you in a most barbaric manner.\n"));
    return 1;
  }
  if(ob=present(explode(str, " ")[0], ENV(E))) {
    say(lw(EQN + " " + qv + "s something incomprehensible at "
	+ (string)ob->QN + ".\n"));
    writelw("You " + qv + ": \"" + parse_string(extract(str, strstr(str, " ")
	+ 1)) + "\" at " + (string)ob->QN + ".\n");
    tell_object(ob, lw(EQN + " " + qv + "s: \"" + parse_string(extract(str,
	strstr(str, " ") + 1)) + "\" at you.\n"));
    return 1;
  }
  say(lw(EQN + " " + qv + "s: " + parse_string(str) + "\n"));
  writelw("You " + qv + ": " + parse_string(str) + "\n");
  return 1;
}

string parse_string(string str) {
  mixed *parse;
  string tmp;
  int i,j,type;
  parse=({ ({}), ({}) });
  type=(str[i..i]>="A" && str[i..i]<="Z") || (str[i..i]>="a" && str[i..i]<="z");
  if(!type)
    parse[1]+=({ "" });
  j=strlen(str);
  tmp="";
  for(i=0;i<j;i++) {
    if(type==((str[i..i]>="A" && str[i..i]<="Z")
	|| (str[i..i]>="a" && str[i..i]<="z")))
      tmp+=str[i..i];
    else {
      parse[type]+=({ tmp });
      type=!type;
      tmp=str[i..i];
    }
  }
  parse[type]+=({ tmp });
  if(sizeof(parse[0]) < sizeof(parse[1]))
    parse[0]+=({ "" });
  else
    if(sizeof(parse[1]) < sizeof(parse[0]))
      parse[1]+=({ "" });
  tmp="";
  j=sizeof(parse[0]);
  for(i=0;i<j;i++)
    tmp+=get_word(parse[1][i]) + parse[0][i];
  return tmp;
}

string get_word(string str) {
  switch(str) {
    case "I":    return "Me";   break;
    case "i":    return "me";   break;
    case "Am":   return "Is";   break;
    case "am":   return "is";   break;
    case "m":    return "s";    break;
    case "ve":   return "s";    break;
    case "My":   return "Me";   break;
    case "my":   return "me";   break;
    default:     return str;    break;
  }
}
  
int flex_muscles() {
  write("You flex your muscles.\n");
  say(EQN + " flexes " + EQPO + " muscles.\n");
  return 1;
}

int beat_chest() {
  write("You beat your hands on your chest and let out a bloodcurdling howl!\n");
  say(EQN + " beats " + EQPO + " hands on " + EQPO
	+ " chest and lets out a bloodcurdling howl!\n");
  return 1;
}

int bare_teeth() {
  write("You bare your teeth and look ready to eat someone alive!\n");
  say(EQN + " bares " + EQPO + " teeth and looks ready to eat you alive!\n");
  return 1;
}

int communicate(string str) {
  string verb, said;
  verb=query_verb();
  if(!str)
    str="";
  if(verb[0..0]=="'")
    str=extract(verb, 1) + " " + str;
  said=parse_string(str) + "\n";
  say(lw(EQN + " says: " + said));
  writelw("You say: " + said);
  return 1;
}

int shout_to_all(string str) {
  if(!str) {
    NF("Shout what ?\n");
    return 0;
  }
  return (int)E->shout_to_all(parse_string(str));
}

int whisper(string str) {
  string *tmp;
  tmp=explode(str, " ");
  if(sizeof(tmp)<2) {
    NF("Whisper what ?\n");
    return 0;
  }
  return (int)E->whisper(tmp[0] + " "
	+ parse_string(implode(tmp[1..sizeof(tmp)-1], " ")));
}

int tell_player(string str) {
  string *tmp;
  tmp=explode(str, " ");
  if(sizeof(tmp)<2) {
    NF("Tell what ?\n");
    return 0;
  }
  return (int)E->tell_player(tmp[0] + " "
	+ parse_string(implode(tmp[1..sizeof(tmp)-1], " ")));
}

int no_standard_spells() {
  write("Barbarians cannot cast " + query_verb() + ".\n");
  return 1;
}

int guild_help(string str) {
  if(!str || strstr(str, " ")!=-1)
    return 0;
  if(str=="levels") {
    GM->list_levels(11, (int)E->query_gender());
    return 1;
  }
  if(str=="guild") {
    this_player()->more_string(read_file("/players/moonchild/guild/help"));
    return 1;
  }
}

void guild_changes() {
  object ob;
  while(ob=present("combat_soul", E))
    destruct(ob);
  shadow->remove_the_shadow();
}
