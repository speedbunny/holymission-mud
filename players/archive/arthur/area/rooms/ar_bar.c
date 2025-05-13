/* code by Arthur for Holy Mission-140.78.3.1 last edit 11.11.94 */
#include "/players/arthur/defs/ardefs.h"
#include "room.h"

string seat;
int cost, hp;

ONE_EXIT("/players/arthur/entrance", "east",
        "Sherwood's Bar",
"     You are standing in Sherwood's very famous bar. The bar tenders\n"+
"are just waiting to take your order. The people seem much more hospitable\n"+
"than the ones outside although you think that may be just because they\n"+ 
"have had a little to much to drink. The tables are fairly clean, and there\n"+
"are a few townfolk sitting down, as if they are intrested in talking to \n"+
"someone. A bartender tells you if you want a list of what we have just type\n"+
"'list'.\n",1)

init() {
        add_action("st","sit");
        add_action("li","list");
        add_action("ge","order");
        add_action("ge","buy");
        if(TPN == seat) {seat = "no_one";}
        ::init();
        }
st() {
     if(TPN != "Someone"|| TPN != "someone" && !seat || seat == "no_one") {
     seat = TPN;
     CO(TP(),"move_player","sits down#/players/arthur/area/rooms/sitting");
     return 1;}
     else { write("Sorry, all the seats are full."); return 1;}
}
li() {
     
        if(TP()->query_quests("orc_slayer")== 1) {
write("The bartender whispers to you: Since ya saved all of us, ya get a break\n"+
    "\nORDER NUMBER  NAME                   EFFECTS              Price\n"+  
    "\n   <#1>       ALE                    Intoxication         10\n"+
      "   <#2>       Strong Ale             Intoxication         20\n"+
      "   <#3>       Whisky                 Intox. Healing       30\n"+
      "   <#4>       Strong Whisky          Intox. Healing       40\n"+
      "   <#5>       Minor Healing Potion   Healing. Intox       100\n"+
      "   <#6>       Strong Healing Potion  Healing              200\n");
      return 1;}

else 
write("The bartender tells you: Here's the menu bub, and shows you this:\n"+
    "\nORDER NUMBER  NAME                   EFFECTS              Price\n"+  
    "\n   <#1>       ALE                    Intoxication         20\n"+
      "   <#2>       Strong Ale             Intoxication         40\n"+
      "   <#3>       Whisky                 Intox. Healing       60\n"+
      "   <#4>       Strong Whisky          Intox. Healing       80\n"+
      "   <#5>       Minor Healing Potion   Healing. Intox       200\n"+
      "   <#6>       Strong Healing Potion  Healing              400\n"); 
      return 1;}

ge(str) {
  if(!str)
  {write("which one?"); return 1;}

  if (str =="1") {
  if(!que(20)) {return 1;}
  if(!money(cost)) {return 1;}
  TP()->drink_alcohol(5);
  write("You drink an ALE.\n");
  return 1;}

  if (str =="2") {
  if(!que(40)) {return 1;}
  if(!money(cost)) {return 1;}
  TP()->drink_alcohol(12);
  write("You drink a Strong ALE.\n");
  return 1;}
  
  if (str =="3") {
  if(!que(60)) {return 1;}
  if(!money(cost)) {return 1;}
  TP()->drink_alcohol(10);
  CO(TP(),"heal_self",7);
  write("You drink a shot of Whisky.\n");
  return 1;}
  
  if (str =="4") {
  if(!que(80)) {return 1;}
  if(!money(cost)) {return 1;}
  TP()->drink_alcohol(30);
  CO(TP(),"heal_self",15);
  write("You drink a shot of Strong Whisky.\n");
  return 1;}

  if (str =="5") {
  if(!que(200)) {return 1;}
  if(!money(cost)) {return 1;}
  CO(TP(),"heal_self",50);
  write("You drink a Minor Healing Potion.\n");
  return 1;}

  if (str =="6") {
  cost=1000;
  if(!money(cost)) {return 1;}
  CO(TP(),"heal_self",120);
  write("You drink a Strong Healing Potion.\n");
  return 1;}
  if (str=="7") {
  cost=0;
  CO(TP(),"reduce_hit_point",-100);
  write("You feal blessed by gods!\n");
   return 1;}
   else {
   write("Sorry, use a number between 1-6\n");return 1;}
  }

que(co) {
   if(TP()->query_quests("king_arthur")== 1) {cost=co/2; return 1;}
   else {cost=co; return 1;}
}
money(cost) {
 if(TP()->query_money()<cost) {write("Sorry you don't have enough money"); return 0;}
 else { TP()->add_money(-cost); return 1;}
}
