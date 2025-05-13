inherit "/obj/monster";

#define TP this_player()
#define NUMBER 30  /* number of cakes */
#define PRICE 120   /* price of 1 cake */

int num;

void reset(int arg) {
       ::reset(arg);

      num=num+NUMBER;

   if (arg) return;
    set_name("vilan");
    set_alias("cook");
    set_race("human");
    num=NUMBER;
    set_short("A cook Vilan");
    set_long("A cook Viland. He is good man.\nYou can buy a cake from him.\n");
    set_level(45);
    set_spell_mess1("Vilan throws a hot coals at you.\nPAIN is terrible.\n\n");
    set_spell_mess2("");
    set_chance(13);
    set_spell_dam(150);
    set_al(90);
    set_gender(1);
    set_aggressive(0);
    set_wc(30);
    set_ac(35);
}

int query_property(string str){
 return str=="no_steal";
}

init(){
 ::init();
add_action("buy","buy");
}

int buy(string str){
object cake;

 notify_fail("Buy what from whom?\n");
 if (str=="cake from vilan" || str=="cake"){
   if (TP->query_money()<PRICE){
     write("Vilan grins at you.\n Vilan tells you: You haven't enough money.\n");
     say("Vilan grins at "+TP->query_name()+".\n");
     return 1;
   }
   if (num<1){
    write("Vilan tells you: I am out of cakes. Try later.\n");
    return 1;
   }
   cake=clone_object("/players/goldsun/nottingham/obj/cake");
   if (transfer(cake,TP)!=0){
      write("You can't carry that much.\n");
      return 1;
   }
   write("Vilan gives you a cake.\n");
   write("You pay "+PRICE+" coins.\n");
   TP->add_money(-PRICE);
   say(TP->query_name()+" buys a cake.\n");
   num--;
   return 1;
 }
} 

