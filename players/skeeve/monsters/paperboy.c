inherit "obj/monster";

#include "/players/skeeve/area.h"
#include "/players/skeeve/code.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("paperboy");
    set_short("The paperboy");
    set_long("The small paperboy sells the newspaper.\n");
    set_race("half-elf");
    set_male();
    set_level(6);
    set_dex(10);
    set_str(5);
    set_al(200);
    set_hp(160);
    set_sp(0);
    set_wc(1);
    set_ac(1);
    set_aggressive(0);
    set_size(2);
    load_chat(5,({
       "The paperboy says: The newspaper!\n",
       "The paperboy says: Who wants to buy a newspaper?\n",
       "The paperboy says: Only 10 coins for a newspaper!\n",
       "The paperboy says: All the news for only 10 coins!\n"
    }) );
  }
  
  WEAPON("danseuse_dagger",this_object());
  
  ARMOUR("trouser suit","trouser_suit",this_object());
  ARMOUR("blue cap","blue_cap",this_object());
  ARMOUR("seven miles boots","seven_miles_boots",this_object());
}

init () {
  ::init();
  add_action("buy","buy");
}

buy(str) {
  int money;
  if (!str || ((str != "paper") && (str != "newspaper"))) return 0;
  if (money = this_player()->query_money() < 10) {
    write("You have not enough money to buy a newspaper.\n");
    return 1;
  }
  write("You buy a newspaper from the paperboy.\n");
  say(capitalize(this_player()->query_name()) + " buys a newspaper from the paperboy.\n");
  transfer(clone_object(OBJECTS+"newspaper"),this_player());
  this_player()->add_money(-10);
  add_money(10);
  return 1;
}
