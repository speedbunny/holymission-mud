/*
 * Author:      Uglymouth
 * Date:        29-JAN-1994
 * Last update: 01-FEB-1994
 *
 * This is the moneygreedy soul of a merchant.
 */
/* Temporary notebook for ideas:
 * - purse can't be stolen.
 * - moneypurse dropped when dead.
 * - init_purse/save_purse in the guild's 'vault.c/o'
 */
#define  GUILD          12
#define  VAULT          "/players/uglymouth/guild/vault"
#define  TP             this_player()
#define  QN             query_name()
#define  QRN            query_real_name()
#define  QPOS           query_possessive()
#define  QL             query_level()
#define  QM             query_money()
#define  AM             add_money
#define  ENV            environment
#define  IF_GHOST       if(ENV()->query_ghost())

string *soulname;
string cloth;
int money;
int max_money;                
object shadow;

void get_cloth() {
int lvl;
  lvl = ENV()->QL < 30 ? ENV()->QL/5 : 6;
  cloth = ({ "linen", "cotton", "wool", "leather", "velvet", 
    "brocade", "silk" })[lvl];
}

int id(string str) {
  get_cloth();
  soulname = ({ "merchantsoul", "purse", cloth + " purse" });
  return (member_array(soulname) != -1);
}

int get() {
  return 1;
}

int drop() {
  return 1;
}

/* Can contain as much as the player can carry himself. */
int query_max_money() {
  return max_money = (TP->QL + TP->query_str()) * 500;
}

int query_money() {
  return money;
}

void update_purse() {
  get_cloth();
  query_max_money();
}

string short() {
  IF_GHOST return 0;         /* ghost with inventory?? Check on mages. */
  get_cloth();
  return "A "+ cloth +" purse";
}

void long() {
  IF_GHOST return;
  get_cloth();
  write("This is the "+ cloth +" purse of a merchant.\n");
  switch(money) {
    case 0:
      write("The smell of gold is all that's left in it.\n");
    break;
    case 1..((max_money/4)-1):
      write("It contains no more than some loose change.\n");
    break;
    case (max_money/4)..((max_money/2)-1):
      write("A nice tinkling sound suggests quite some wealth.\n");
    break;
    case (max_money/2)..((3*max_money/4)-1):
      write("The shape of coins through the cloth reveals a small treasure.\n");
    break;
    case (3*max_money/4)..(max_money-1):
      write("Its round shape tells that it contains a real treasure.\n");
    break;
    case max_money:
      write("It's so full that it couldn't contain one more coin.\n");
    break;
    default:
      write("It's impossible to determine how much it contains.\n");
    break;
  }
}

void dead_purse() {
object newpurse, newcoins;
  newmoney = clone_object("/obj/money");
  newmoney->set_money(money);
  newpurse = clone_object("/obj/container");
  newpurse->set_name("purse");
  newpurse->set_alias(cloth + "purse");
  newpurse->set_short("A torn up "+ cloth +" purse");
  newpurse->set_long("It looks like it once belonged to a merchant.\n");
  newpurse->set_value(5 + random(ENV()->QL));
  newpurse->set_max_weight(newmoney->query_weight());
/* not sure of correct function in container and id of money...
  newpurse->set_only_for("money");
*/
  transfer(newmoney, newpurse);
  move_object(newpurse, present("corpse", ENV(TP));
  money = 0;
  save_purse();
}

void init() {
  if(!shadow && !ENV()->query_immortal()) {     
    /* shadows second_life(), for call to dead_purse */
    shadow = clone_object("players/uglymouth/guild/shadow");
    shadow->shadow_it(ENV());
  }
  money = VAULT->init_purse(ENV()->QRN);
  add_action("money_in", "put");
  add_action("money_out", "get");
  add_action("money_out", "take");
  add_action("purse_contains", "count");
  add_action("save_purse", "quit");
}

int money_in(string str) {
int amount, diff;
string curr, inwhat;  
  if(!str) return 0;
  IF_GHOST return 0;
  if(sscanf(str, "%d %s in %s", amount, curr, inwhat) != 3) return 0;
  if(curr != "coin" && curr != "coins" && !id(inwhat)) return 0;
  if(amount <= 0) {
    write("Mathematics doesn't seem to be one of your best skills...\n");
    return 1;
  }
  if(TP->QM < amount) {
    write("You don't have that much money on you.\n");
    return 1;
  }
  query_max_money();  
  if(diff = money + amount - max_money <= 0) {
    write("You put "+ amount +" "+ amount == 1 ? "coin" : "coins"
      + "into your purse.\n");
    say(TPN +" puts some money in "+ TP->QPOS +" purse.\n");
    money += amount;
    TP->AM(-amount);
    return 1;
  }
  amount -= diff;
  write("You fill your purse to its maximum with "+ amount
    + amount == 1 ? "coin" : "coins" + ".\n"
    + "You put the rest of the money back in your pockets.\n");
  say(TPN +" puts some money in "+ TP->QPOS +" purse.\n");
  money += amount;
  TP->AM(-amount);
  return 1;
}

int money_out(string str) {
int amount, diff;
string curr, inwhat;  
  if(!str) return 0;
  IF_GHOST return 0;
  if(sscanf(str, "%d %s from %s", amount, curr, inwhat) != 3) return 0;
  if(curr != "coin" && curr != "coins" && !id(inwhat)) return 0;
  if(amount <= 0) {
    write("Mathematics doesn't seem to be one of your best skills...\n");
    return 1;
  }
  if(amount > money) {
    write("Your purse doesn't contain that much money.\n");
    return 1;
  }
  if(diff = (TP->QL + TP->query_str()) * 500 - TP->QM - amount >= 0) {
    write("You take "+ amount +" "+ amount == 1 ? "coin" : "coins"
      + "out of your purse.\n");
    say(TPN +" takes some money out of "+ TP->QPOS +" purse.\n");
    money -= amount;
    TP->AM(amount);
    return 1;
  }
  amount += diff;
  write("You take "+ amount +" "+ amount == 1 ? "coin" : "coins" 
    + " out of your purse.\n"
    + "You can't carry more money, so the rest goes back into the purse.\n");
  say(TPN +" takes some money out of "+ TP->QPOS +" purse.\n");
  money -= amount;
  TP->AM(amount);
  return 1;
}

int purse_contains(string str) {
  IF_GHOST return 0;
  if(str != "money in purse" && str != "coins in purse") return 0;
  say(TPN + " greedily counts "+ TP->QPOS +" money.\n");
  write("You accurately count the money in your purse.\n");
  if(money) {
    write("It contains "+ money +" gold "+ money == 1 ? "coin" : "coins" 
      +".\n");
    return 1;
  }
  write("With pain in your heart you notice that it's empty....\n");
  return 1;
}

void save_purse() {
  VAULT->save_purse(ENV()->QRN, money);
}

void guild_changes() {
  tell_object(ENV(),"You take the money from your purse, and tear it up.\n");
  TP->AM(money);
  VAULT->remove_purse(ENV()->QRN);
  shadow->dest_shadow();
}

/* ################# the vault (move to separate file) ###################

#define VAULT   "players/uglymouth/guild/vault"
mixed *purse_list;

int id(string str) {
  return str == "vault";
}

string short() {
  return "The Vault of the Merchants' Guild";
}

void long() {
  write(short() + ".\n\tNo obvious exits.\n");
}

void reset(int arg) {
  if(!arg) return;
  set_light(1);
  restore_object(VAULT);
  if(!purse_list) purse_list = ({ ({ }), ({ }) });
}

void init() {
  add_action("dump_list","dump");
}

int dump_list(string str) {
  if(!this_player()->query_immortal()) return 0;
  int i, sopl;
  sopl = sizeof(purse_list[1]);
  if(!str) {
    for(i=0; i<sopl; i++)
      write(capitalize(purse_list[1][i]) +"\t"+ purse_list[2][i] +"\n");
    return 1;
  }
  int sl, j;
  sl = strlen(str) - 1;
  j = 0;
  for(i=0; i<sopl; i++) {  /* check if bug str[0..n] if n>strlen(str) */
    if(strlen(purse_list[1][i] <= sl+1 && purse_list[1][i][0..sl] == str) {
      write(capitalize(purse_list[1][i]) +"\t"+ purse_list[2][i] +"\n");
      j++;
    }
  }
  if(!j) write("No such merchant is registered here.\n"); 
  return 1;
}

int init_purse(string name) {
  int nr;
  if(nr = member_array(name, purse_list[1]) == -1) return 0;
  return purse_list[2][nr];
}

void save_purse(string name, int value) {
  int nr;
  if(nr = member_array(name, purse_list[1]) != -1) purse_list[2][nr] = value;
  else {
    purse_list[1] += name;
    purse_list[2] += value;
  }
  save_object(VAULT);
}

void remove_purse(string name) {
  int nr;
  nr = member_array(name, purse_list[1]);
  del_array(purse_list, purse_list[1][nr]);
  del_array(purse_list, purse_list[2][nr]);
  save_object(VAULT);
}

############################# end vault edit ############################ */

/* ################## the shadow (move to separate file) ################

#define SOUL    present("merchantsoul", owner)
object owner;

void shadow_it(object ob) {
  owner = ob;
  shadow(owner, 1);
}

dest_shadow() {
  destruct(this_object());
}

int second_life() {
  SOUL->dead_purse();
  return owner->second_life();
}

############################# end shadow edit ########################### */
