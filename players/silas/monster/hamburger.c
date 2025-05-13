
inherit"obj/monster";
reset(arg) {
object coins;
string chat_str;
::reset(arg);
if(arg) return;
if(!chat_str) {
chat_str = allocate(2);
chat_str[0] = "HEE HEE!\n";
chat_str[1] = "Sizzle, sizzle!\n";
  }
set_name("hamburger");
set_short("Sentient hamburger");
set_long(
"This hamburger looks just like any other hamburger except that it rolls \n"
+ "around with a will of its own. Strange giggling sounds which emanate from\n"
+ "this strange burger make you think twice about eating it.\n");
set_level(6);
set_race("hamburger");
load_chat(60,chat_str);
coins = clone_object("obj/money");
coins->set_money(300);
transfer(coins,this_object());
}
