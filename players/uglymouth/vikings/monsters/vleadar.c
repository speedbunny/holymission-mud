/* viking leadar is the chief of this expedition */
inherit "obj/monster";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("viking leadar");
      set_alt_name("leadar");
      set_alias("viking");
      set_short("Viking Leadar");
      set_long("Viking Leadar is the chief of this camp. He's a man of great power, \n"
             + "both physical as well as intellectual. His red beard glimmers like \n"
             + "the setting sun and his stale blue eyes look straight into your soul. \n"
             + "It's quite obvious he doesn't like foreigners. \n");
      set_level(13);
      set_race("human");
      set_gender(1);
      set_al(-25);

      transfer(clone_object("/players/uglymouth/vikings/items/viksword"),this_object());
      transfer(clone_object("/players/uglymouth/vikings/items/vikhelm"),this_object());
      transfer(clone_object("/players/uglymouth/vikings/items/viktunic"),this_object());

      command("wield sword");
      command("wear helm");
      command("wear tunic");

      }
   }

void init() {
   ::init();
   add_action("give","give");
   add_action("buy","buy");
   }

int give(string str) {
string msg;
int amount;
object voucher;
   if(sscanf(str,"%d coins to viking",amount)!=1 &&
      sscanf(str,"%d coins to viking leadar",amount)!=1) return 0;
   if(this_player()->query_money() < amount) {
      write("You don't have so much money. \n");
      return 1;
      }
   write("You give " + amount + " coins to Viking Leadar. \n");
   say(this_player()->query_name() + " gives " + amount + " coins to Viking Leadar. \n",this_player());
   this_player()->add_money(-amount);
   this_object()->add_money(amount);
   if(this_object()->query_money() < 1000) msg="Viking Leadar says: You're almost there... \n";
   if(this_object()->query_money() < 750) msg="Viking Leadar says: A little more wouldn't hurt for such a favour. \n";
   if(this_object()->query_money() < 500) msg="Viking Leadar looks interested at your purse. \n";
   if(this_object()->query_money() < 250) msg="Viking Leadar holds up his opened hand patiently. \n";
   if(this_object()->query_money() < 100) msg="Viking Leadar suggests that you are much richer than he is. \n";
   if(this_object()->query_money() < 50) msg="Viking Leadar detests your greed. \n";
   if(this_object()->query_money() < 1000) {
      write(msg);
      return 1;
      }
   write("Viking Leadar smiles as he hides away his money. \n"
       + "Viking Leadar tells you: Because you're so kind, I'll let you use my boat. \n"
       + "Viking Leadar gives you a permission voucher. \n");
   voucher=clone_object("/players/uglymouth/vikings/items/voucher");
   voucher->set_alt_name("voucher of " + this_player()->query_real_name());
   voucher->set_long("A voucher that says that " + this_player()->query_short_name() + " has permission to use the vikings' boat. \n");
   transfer(voucher,this_player());
   this_object()->add_money(-this_object()->query_money());
   return 1;
   }

int buy(string str) {
   if(str!="permission" && str!="permission voucher" && str!="voucher") return 0;
   write("Viking Leadar says suggestively: I cannot be bribed by giving me money. \n");
   return 1;
   }
