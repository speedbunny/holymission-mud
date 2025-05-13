/* THE FORGE!  -   Angel, March 1994
 *             -   Adept, February 1996
 *             -   Aryk, March 1996
 *             -   Brainsprain, December, 1997
 * This simple room makes armour and weapons of a standard type
 * for players. To make an item it takes time. This also removes
 * the variation of other Creators weapon shops, making them all
 * standard across the mud.
 *
 *
 */

inherit "/obj/monster";

#define OWNER            (string)this_object()->query_name()
#define CHARISMA         (int)this_player()->query_cha()
#define VALUE_MOD        20
#define COST_MOD         300
#define DIFFICULTY       15   /* thorins difficulty to make armour/weapon */
#define ABILITY          20   /* thorins ability to make armour/weapon    */
#define TIME_OUT         10   /* time in lots of 30 seconds               */
#define CALLOUT_TIME     30
#define CALLOUT_TIME     30
#define MAKE_COMPLEXITY  18
#define MOD              100
#define COUNT_MOD        3
#define WEAPON           "obj/weapon"
#define ARMOUR           "obj/armour"


static object owner_ob;
object the_item;
static string owner_name, owner;
static status Forge, Enchant;

static string customer;       /* The person the OWNER is working for */
static status working;        /* If the OWNER it is working          */
int counter;
status finished;

string name, type;
int ac, wc, weight, value, length;
mixed *items;
status fault;
status wc_flag, ac_flag, start_flag;
status i_made_a_booboo;


void set_owner(string str);
status forge(string str);
status forge_item();
status enchant(string tmp1, string tmp2);
status working();
void make_armour();

status set_forge(status arg)   { return Forge = arg;   }

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
//  set_owner("thorin");
  set_name("thorin");
  set_alias("armourer");
  set_short("Thorin the forger");
  set_level(50);
  add_money(100+random(1000));
  set_hp(10000); 
  set_wc(50);
  set_ac(25);
  set_short("Thorin, the Dwarvish Armourer");
  set_long(
"He is a typical dwarf, standing in leather apron and hard, black boots.  "+
"He is most happy working with metal, forging weapons and armour for the "+
"city garrison and for the adventurers who stay in the city.\n");
  load_chat(20,({
    "Thorin bashes some metal.\n",
      "Thorin looks happily into the forge.\n",
      "Thorin stoaks the forge.\n",
      "Thorin happily works the forge.\n",
      "Thorin asks: Is there anything I can do for you today?\n",
      }));
  load_a_chat(5,({
    "Thorin says: That's not a good idea.\n",
      "Thorin says: If you leave, you will not be harmed.\n",
      }));
  set_forge(1);
  
}
void init() {
  ::init();
  add_action("forge", "make");
  if((string)this_player()->query_real_name() == customer)
    call_out("check_finished_item", 1);
}

void catch_tell(string str) {
  string tmp1, tmp2;

  if(Forge)
    if(sscanf(str, "%s says: forge %s\n", tmp1, tmp2)) {
      forge(tmp2);
    }
}


status working() {
  if(customer) {
    write(OWNER+" says: I'm still busy, come back later.\n");
    return 1;
  }
  return 0;
}

status forge(string str) {
  int i;
  if(!Forge) return 0;
  if(working()) return 1;
  
  name = 0;
  wc = 0;
  type = 0;
  weight = 0;
  value = 0;
  length = 0;
  ac = 0;
  customer = 0;
  the_item = 0;
  fault = 0;
  wc_flag = 0;
  ac_flag = 0;
  i_made_a_booboo = 0;
  
  items = ({
    /* NAME             WC         TYPE          WT      VALUE  LENGTH */
    
    "sickle",            9,       "edged",      4,        400,      24,
    "dagger",            8,       "edged",      4,        275,      15,
    "dirk",              8,       "edged",      4,        400,      12,
    "knife",             6,       "edged",      4,        90,       12,
    "scimitar",         10,       "edged",      5,        520,      36,
    "broadsword",       12,       "edged",      5,        1100,     42,
    "falchion",         12,       "edged",      5,        1100,     42,
    "khopesh",          11,       "edged",      5,        770,      42,
    "longsword",        13,       "edged",      6,        1500,     42,
    "shortsword",       10,       "edged",      5,        520,      24,
    "rapier",           12,       "pointed",    5,        1100,     48,
    "sabre",            10,       "edged",      5,        520,      45,
    "cutlass",          11,       "edged",      5,        770,      36,
    "halberd",          13,       "pointed",    6,        1500,     60,
    "pike",             12,       "pointed",    5,        1100,     60,
    "lance",            10,       "pointed",    5,        520,      150,
    "ranseur",          11,       "pointed",    5,        770,      96,
    "spear",            10,       "pointed",    5,        520,      70,
    "trident",          10,       "pointed",    5,        520,      50,
    "club",              9,       "blunt",      4,        400,      36,
    "flail",            10,       "blunt",      5,        520,      48,
    "hammer",           11,       "blunt",      5,        770,      24,
    "war hammer",       11,       "blunt",      5,        770,      30,
    "staff",            12,       "blunt",      5,        1100,     80,
    "rod",              12,       "blunt",      5,        1100,     80,
    "mace",             12,       "blunt",      5,        1100,     36,
    "battle axe",       12,       "edged",      5,        1100,     48,
    "hand axe",          8,       "edged",      4,        275,      24,
    "axe",              10,       "edged",      5,        520,      30,
    "twohandedsword",   14,       "edged",      7,        1600,     72,
    "bastardsword",     13,       "edged",      6,        1500,     54,
    "morning star",      9,       "blunt",      4,        400,      24,
    "morningstar",       9,       "blunt",      4,        400,      24,
    "claymore",         14,       "blunt",      7,        1600,     72
  });
  if(member_array(lower_case(str), items) > -1) {
    i = member_array(lower_case(str), items);
    name   = items[i];
    wc     = items[i + 1];
    type   = items[i + 2];
    weight = items[i + 3];
    value  = items[i + 4];
    length = items[i + 5];
    wc_flag = 1;
  }
  
  else {
    items = ({      "armour",      3,        "armour",      5,         800,
                    "chainmail",   3,        "armour",      5,         800,
                    "platemail",   4,        "armour",      6,        1600,
                    "fieldplate",  4,        "armour",      5,        2500,
                    "fullplate",   4,        "armour",      5,        2500,
                    "shield",      1,        "shield",      3,         200,
                    "boots",       1,        "boots",       2,         200,
                    "gauntlets",   1,        "gloves",      1,         300,
                    "helm",        1,        "helm",        1,         300,
                    "helmet",      1,        "helm",        1,         300
    });
    if(member_array(lower_case(str), items) > -1) {
      i = member_array(lower_case(str), items);
      name   = items[i];
      ac     = items[i + 1];
      type   = items[i + 2];
      weight = items[i + 3];
      value  = items[i + 4];
      ac_flag = 1;
    }
    else {
      write(OWNER+" says: I can't make a "+str+".\n");
      return 1;
    }
  }
  
  if(random(VALUE_MOD) > random(CHARISMA))
    value += random(value/4);
  else
    value -= random(value/3);
  write(OWNER+" haggles with you over the price of the "+name+".\n");
  if(this_player()->query_money() < value) {
    write(OWNER+" says: But you don't have "+
	  value+" coins!\n");
    return 1;
  }
  
  write(OWNER+" takes "+value+
        " coins from you for the "+name+"\n");
  this_player()->add_money(-value);
  
  tell_room(environment(), OWNER+" says: It'll take a while to make it.\n"+
	    OWNER+" says: Come back later.\n");
  
  customer = (string)this_player()->query_real_name();
  finished = 0;  /* just started */
  /* obj = clone_object(FILE);
     move_object(obj, this_player());
     */
  this_object()->
  start_making(name, type, weight, value, wc, ac, wc_flag, ac_flag, length);
  /* forge_item(); */
  return 1;
}


void check_finished_item() {
  object obj;
  
  if(present(name, this_object())) {
    obj = present(name, this_object());
    tell_room(environment(), OWNER+" says: Hullo "+this_player()->query_name()+
	      ", I've finished your");
    if (wc)
      tell_room(environment(), " weapon.\n");
    else if(ac)
      tell_room(environment(), " armour.\n");
    else
      tell_room(environment(), " item.\n");
    
    move_object(obj, this_player());
    customer = 0;
    name = 0;
    finished = 0;
    i_made_a_booboo = 0;
    remove_call_out("start_making");
    remove_call_out("finish_making");
    return;
  }
  if(finished) {
    tell_room(environment(), OWNER+" says: I'm sorry "+customer+", but "+
	      "someone stole your "+name+" from me.\n\t\tPerhaps I can make another "+
	      "one for you?\n");
    finished = 0;  /* can make another one now */
    return;
  }
  tell_room(environment(), OWNER+" exclaims: I haven't finished the "+name+
	    " yet! Come back later!\n");
}

status start_making(string name, string type,
                    int weight,  int value,
                    int wc,      int ac,
                    status wc_flag, status ac_flag, int length) {
  int chance_to_make, chance_to_fail, difference;
  string tmp1, tmp2;
  
  if(wc_flag) {
    the_item = clone_object(WEAPON);
    chance_to_make = (int)environment()->query_level();
  }
  else {
    the_item = clone_object(ARMOUR);
    chance_to_make = (int)environment()->query_level();
    
  }
  
  if(chance_to_make) chance_to_make = random(chance_to_make);
  chance_to_fail = 1;
  difference = chance_to_fail - chance_to_make;
  
  if(chance_to_make < chance_to_fail) {
    weight += random(weight / 2);
    value -= random(value/4);
    if(wc_flag)
      wc -= random(wc/3);
    if(ac_flag && ac > 1)
      ac -= 1;
    i_made_a_booboo = 0;
  }
  
  the_item -> set_name(name);
  the_item -> set_weight(weight);
  the_item -> set_value(value);
  if(ac)
    the_item -> set_ac(ac);
  if(wc) {
    the_item -> set_class(wc);
    /* the_item -> set_length(length);  */
  }
  if(sscanf(name, "%ssword", tmp1))
    the_item -> set_alias("sword");
  /*  the_item -> set_type(type);  NOT IN YET */
  
  if(type == "boots" || type == "gloves") {
    the_item -> set_short("pair of "+name);
    if(i_made_a_booboo)
      the_item -> set_long("A badly crafted pair of metal "+name+", made by "+
			   customer+".\n");
    else
      the_item -> set_long("A finely designed pair of metal "+name+", made by "+
			   
			   customer+".\n");
  }
  else if(type == "helm" || type == "helmet") {
    the_item -> set_short(name);
    if(i_made_a_booboo)
      the_item->set_long("A poorly crafted "+name+" made by "+customer+".\n");
    else
      the_item->set_long("A finely crafted "+name+" made by "+customer+".\n");
  }
  
  else if(type == "shield") {
    the_item -> set_short("shield");
    if(i_made_a_booboo)
      the_item -> set_long("A badly designed shield, made by "+
			   customer+".\n");
    else
      the_item -> set_long("A finely designed shield, made by "+
			   customer+".\n");
  }
  
  else {
    
    if(ac_flag) {
      the_item -> set_short("suit of "+name);
      if(i_made_a_booboo) {
        the_item -> set_long("A badly designed suit of "+name+", made by "+
			     customer+".\n");
      }
      else
        the_item -> set_long("A finely designed suit of "+name+", made by "+
			     customer+".\n");
    }
    
    else {
      the_item -> set_short(name);
      if(i_made_a_booboo)
        the_item -> set_long("A badly crafted "+name+", made by "+
			     customer+".\n");
      else
        the_item -> set_long("A finely crafted "+name+", made by "+
			     customer+".\n");
    }
  }
  
  if(i_made_a_booboo) {
    if(wc) the_item -> hit_weapon(MOD * difference);
    else the_item -> hit_armour(MOD * difference);
    if(!the_item) {
      remove_call_out("start_making");
      remove_call_out("finish_making");
      return 1;
    }
  }
  
  call_out("finish_making", ac);
  return 1;
}

status finish_making() {
  if(counter < COUNT_MOD) {
    if(environment()->query_attack()) {
      write(
	    "Thorin discontinue's forging of the "+(string)the_item->query_name()+
	    " to join the melee.\n");
      destruct(the_item);
      return 1;
    }
    say(
	"Thorin continue's to forge a "+(string)the_item->query_name()+".\n");
    counter += 1;
    if(ac_flag)
      call_out("finish_making", 60 + (int)the_item->query_ac());
    else
      call_out("finish_making", 60 + (int)the_item->query_wc());
    return 1;
  }
  move_object(the_item, this_object());
  call_out("check_finished_item",1);
  return 1;
}
