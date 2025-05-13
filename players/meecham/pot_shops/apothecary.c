// Coded by Meecham 1/96

// I know it is possible if the shop resets while the alchemist is out
// getting ingredients for there to be more than (num) potions of one
// type (never more than (num + 10) tho) 

inherit "room/room";
#define cap capitalize
#define CO clone_object
#define TO this_object()
#define MO move_object
#define TP this_player()
#define NAME(x) x->query_name()
#define CHECK_FOR_ALCHEMIST;\
{\
  if(!present("alchemist",TO))\
    return (0);\
} 

static mapping potions;
static int tm;
string assist_with, alch_name, alch_file;
status waiting;

void reset(status arg) {
  if(potions)
    walk_mapping(potions,"reset_potions");
  if(arg) return;
  set_light(1);
  if (alch_file)
    clone_list = ({ 1, 1, "alchemist", alch_file, 0 });
  short_desc = "Apothecary";
  long_desc =
    "You are in an apothecary.  This is where retired master alchemists\n\
still dabble in potion making.  There is a sign on the wall listing what\n\
potions are currently available and if an alchemist is here, they will be\n\
more than happy to accomodate you.\n";
  items = ({ "sign","Try reading it", });
  ::reset(arg);
}

void init() {
  ::init();
  add_action("display_sign","read");
  add_action("try_to_buy","buy");
  add_action("help_alchemist1","assist");
}

void add_potion(string pot_name, string pot_file, int cost, int num) {

  if (!potions) potions = ([ ]);
// num is deliberately used twice in the mapping, its the only
// way to keep track of the original number of potions to be returned
// at each reset
  potions += ([ pot_name: num; cost; pot_file; num ]);
}

void set_alch_file(string file) {
 alch_file = file;
}

void set_alch_name(string name) {
 alch_name = name;
}

status display_sign(string str) {
  if (!str || str !="sign") return (0);
  printf("\n");
  printf("Potions\t\t\t\tCost\n\n");
  walk_mapping(potions,"display_potions");
  return (1);
}

status check_valid(string str);

status try_to_buy(string str) {
  object potion;

  CHECK_FOR_ALCHEMIST;
  if (!check_valid(str)) {
    printf("%s says: I'm sorry, I don't make that.\n",cap(alch_name));
    say(NAME(TP) + " attempts to buy a potion of " + str + ", but fails.\n");
    return (1);
  }
  if (!potions[str,0]) {
    printf("%s says: I'm sorry, I don't have any of those left.\n",       cap(alch_name));
    say(NAME(TP) + " attempts to buy a potion of " + str + " but " +
           cap(alch_name) + " has run out.\n");
    return (1);
  }
  if(TP->query_money() < potions[str,1]) {
    printf("%s says: I'm sorry, but I must charge %d coins for that.\n",
          cap(alch_name),potions[str,1]);
    say(NAME(TP) + " attempts to buy a potion of " + str + " but hasn't the \n\
               funds.\n");
    return (1);
  }
  TP->add_money(-potions[str,1]);
  potions[str,0]--;
  potion = CO(potions[str,2]);
  printf("You buy a potion of %s.\n",str);
  say(NAME(TP) + " buys a potion of " + str + ".\n");
  if (transfer(potion,TP)) {
    printf("%s sees that you cannot carry more and places the potion\n\on the floor.\n",
           cap(alch_name));
    say(cap(alch_name) + " places a potion on the floor.\n");
    MO(potion,TO);
  }
  return (1);
}

void display_potions(string key) {
  if(strlen(key) < 9)
    printf(cap(key)+"\t\t\t ["+potions[key,0]+"]\t"+potions[key,1]+" coins\n");
  else if (strlen(key) < 17)
    printf(cap(key)+"\t\t ["+potions[key,0]+"]\t"+potions[key,1]+" coins\n");
  else
    printf(cap(key)+"\t ["+potions[key,0]+"]\t"+potions[key,1]+" coins\n");
}

void reset_potions(string key) {
  if(potions[key,0] < potions[key,3])
    potions[key,0] = potions[key,3];
} 

void add_potions(string key,int num_added) {
  potions[key,0] += num_added;
}

status help_alchemist1(string str) {

  CHECK_FOR_ALCHEMIST;
  if(!str || str != alch_name) return (0);
  if (waiting) {
    tell_room(TO,cap(alch_name) + " says: I'm sorry " + NAME(TP) + " but \
              my apprentice is already\n\
              off collecting ingredients for another customer.\n");
    return (1);
  }
  if (tm)
    if(tm+300 > time()) {
      tell_room(TO,cap(alch_name) + " says: I am too tired to make potions \
                right now.\n");
      return (1);
    }
  printf("%s says: Which potion would you like to help me make?\n",
         cap(alch_name));
  input_to("help_alchemist2");
  return (1);
}

status help_alchemist2(string str) {
  if (!check_valid(str)) {
    printf("%s says sadly: I don't know how to make that.\n", cap(alch_name));
    say(NAME(TP) + " is unable to assist " + cap(alch_name) + " in making \
            potions of " + str + ".\n");
    return (1);
  }
  if (potions[str,0]) {
    printf("%s says: I don't need help with that right now.\n", cap(alch_name));
    say(cap(alch_name) + " declines the offer of " + NAME(TP) + ".\n");
    return (1);
  }
  assist_with = str;
  printf("%s says: I need 10000 coins for supplies...\n", cap(alch_name));
  printf("%s says: Will you give them to me? (<yes> <no>)\n", cap(alch_name));
  say(cap(alch_name) + " attempts to strike a deal with " + NAME(TP) + ".\n");
  input_to("help_alchemist3");
}

status help_alchemist3(string str) {
  if(str !="yes") {
    printf("%s says: Fine, be that way!\n", cap(alch_name));
    say(NAME(TP) + " refuses to assist " + cap(alch_name) + ".\n");
    return (1);  }  if(TP->query_money() < 10000) {
    printf("%s scoffs: You don't have enough money to assist me.\n",
            cap(alch_name));
    say(NAME(TP) + " offends Alcides.\n");
    return (1);
  }
  TP->add_money(-10000);
  tell_room(TO, cap(alch_name) + " sends his apprentice to purchase \ingredients.\n");
  call_out("app_returns",60);
  waiting = 1;
  return (1);
}

status app_returns() {
  tm = time();
  tell_room(TO,"The apprentice returns with the ingredients and " +
    cap(alch_name) + "\nimmediately goes to work.\n");
  tell_room(TO,"Only seconds later, " + cap(alch_name) + " smiles happily.\n");
  tell_room(TO,cap(alch_name) + " says: Finished!\n");
  add_potions(assist_with,random(5)+6);
  waiting = 0;
  return (1);
}

status check_valid(string str) {
  if (!member(potions,str)) return (0);
  return (1);
}
