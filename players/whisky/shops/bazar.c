#define TO this_object()
#define TP this_player()
#define TPN TP->query_name()
#define TPL TP->query_level()
#define TPS TP->query_size()
#define TPM TP->query_money()
#define OBJ "/players/whisky/shops/"
#define ETP environment(TP)
#define shieldpath "/obj/armour"
inherit "room/room";
   int mage,monk;

reset(arg) {
   mage="guild/master"->query_number("mage");
   monk="guild/master"->query_number("monk");
  if (arg) return;

set_light(1);
short_desc= "In a bazar";

long_desc =
  "You are in the aventurers outfitter of Whisky. A friendly shopkeeper\n"+
  "is standing behind a desk waiting for you to buy, or sell weapons armours or\n"+
 "other worthful items. This shop is especially well known for it's\n"+
 "magic armours, excellent weapons and special articles.\n"+
  "The shop is called a bazar as a matter of fact that there are also\n"+
 "drinks, food and special articles to buy. There is a big <sign> hanging\n"+
 "behind the desk showing you the items for sale.\n";
dest_dir = ({ "/players/whisky/seaworld/room/shop_entry","south" });
items = ({ "desk", "A beautiful brown oak-desk",
        "shopkeeper", "A friendly young man waiting behind the desk",
      "sign", "A big iron-sign with something written on it" });
}


init() {
  ::init();

  add_action("read","read");
  add_action("read","list");
  add_action("value","value");
  add_action("ar_val","weight");
  add_action("buy","buy");
  add_action("sell","sell");
  }


read(str) {
  if (str=="sign") {
      write("The sign is devided into 3 colums:\n\n"+
            "column 1 for the <weapons>, column 2 for the <armours>\n"+
        "and column 3 for the <others>. You should read each column\n"+
            "carefully.\n");                                           
      return 1; }
 if (str == "column1" || str=="column 1" || str == "weapons") {

write("------------------------------------------------------\n"+
        "A Faunen Broadsword (8000 coins)                      \n"+
        "An Elfen Longsword (6000 coins)                             \n"+
        "A Platinum Sword (3000 coins)                               \n"+
        "A Hammer (1000 coins)                                       \n"+
        "A Morningstar (500 coins)                                   \n"+
        "A War Axe (100 coins)                                       \n"+
        "A Platinum Knife (50 coins)                                 \n"+
        "A Rabbit Cudgel (25 coins)                               \n"+
        "------------------------------------------------------\n");
   return 1; }

 if(str=="column2"||str=="column 2"||str=="armor"||str=="armors"||str=="armour"
    ||str=="armours") {
write("Well we have several types of armours:\n\n"+
      "We have mails, cloaks, gauntlets, boots\n"+
      "and helmets.\n\n"+                                
      "Now do you want to read what mails we have, then type <read mail>.\n"+
      "Or do you want to read what gauntlets we have type <read gauntlets>.\n"+
      "Or do you want to read what robes we have type <read robe>.\n"+
      "Or do you want to read which shields we have type <read shields>.  \n"+
      "Or do you want to read what boots we have type <read boots>.        \n"+
      "At last if you want to read what helmets we have type <read helmets>.\n");
  return 1; }

if (str=="mail" || str=="mails") {

write("------------------------------------------------------\n\n"+
        "A Platinum Mail (8000 coins)                                \n" +
        "A Black Powermail (4000 coins)                              \n" +
        "A Drakeleather jacket (2000 coins)                          \n" +
        "A Snakeleather jacket (800 coins)                           \n" +
        "An Adventurers jacket (500 coins)                          \n" +
        "A Bisonleather Jacket (250 coins)                           \n" +
        "A Simple Jacket (50 coins)                                  \n" +
       "------------------------------------------------------\n");
  return 1; }

if (str=="cloak" || str=="cloaks" || str=="robe" || str=="robes") {

write("------------------------------------------------------\n"+
        "A Monks Robe (2000 coins)                                   \n" +
        "A Priest Robe (500 coins)                                   \n" +
        "A Simple Raincoat (100 coins)                                \n" +
      "-------------------------------------------------------\n");
  return 1; }

  if (str=="shield" || str=="shields") {

write("------------------------------------------------------\n"+
      "A Shield of Black Power (4000 coins)                    \n"+
      "A Platinum Shield (1000 coins)                         \n"+
      "A Tower Shield (500 coins)                            \n"+
      "A Leather Shield (90 coins)                           \n"+
      "------------------------------------------------------\n");
    return 1;
   }
 if (str=="gauntlet" || str=="gauntlets") {

write("-----------------------------------------------------\n"+
        "Platinum Gauntlets (2000 coins)                              \n" +
        "Power Gloves (400 coins)                                     \n" +
        "A Spiky Glove (50 coins)                                    \n" +
       "------------------------------------------------------\n");

  return 1; }

 if (str=="boot" || str=="boots") {

write("------------------------------------------------------\n"+
        "Goiserer (500 coins)                                        \n" +
        "Platimum Boots (200 coins)                                  \n" +
        "Globetrotters (100 coins)                                   \n" +
      "-------------------------------------------------------\n");

  return 1; }


 if(str=="helmet" || str=="helmets" || str=="hat") {

write("------------------------------------------------------\n"+
        "A Spiked Helmet (1000 coins)                                 \n" +
        "A Platinum Helmet (500 coins)                               \n" +
        "An Adventurer Helmet (200 coins)                            \n"+
        "A Leather Helmet (80 coins)                                  \n" +
      "------------------------------------------------------\n");
  return 1; }

   if (str=="column3" || str=="column 3" || str=="other" || str=="others") {

write("We have several kinds of special items:\n\n"+
      "If you want to read our drinks just type <read drinks>.\n"+
      "If you want to read our food just type <read food>.    \n"+
      "If you want to read our bags just type <read bags>.    \n"+
      "if you want to read our specials just type <read specials>.  \n"+
      "If you want to read our illuminators just type <read illuminators>.\n");
  
  return 1; }

  if (str=="special" || str=="specials") {
write("------------------------------------------------------\n"+
      "A Rope (200 coins)                                    \n"+
      "The Extended Soul (400 coins)                         \n"+
      "(* the crystal is now guildfeature (monk) *)          \n"+
      "------------------------------------------------------\n");
  return 1; }
  if (str=="drink" || str=="drinks" || str=="bottle") {

write("------------------------------------------------------\n"+
        "A Bottle of Whiskey (800 coins)                    \n"+
        "An Energizer (500 coins)                            \n"+
        "A Bottle of Cider (40 coins)                        \n"+
        "A Bottle of Beer (20 coins)                         \n"+
        "A Bottle of Herbs Juice (80 coins)                  \n"+
        "A Bottle of Apple Juice (30 coins)                  \n"+
        "A Bottle of Mountain Water (15 coins)               \n"+
      "------------------------------------------------------\n");

  return 1; }


if (str=="food" || str=="foods" || str=="eat") {

write("------------------------------------------------------\n"+
        "A Muesly Block (1000 coins)                                 \n" +
        "A Chicken from Wienerwald (100 coins)                       \n" +
        "Fish and Chips (50 coins)                                   \n" +
        "Cheese and Ham Sandwich (8 coins)                          \n" +
      "------------------------------------------------------\n");

  return 1; }


  if (str=="bag" || str=="bags" || str=="sack" || str=="sacks") {

write("------------------------------------------------------\n"+
        "A Rucksack (50 coins)                                       \n" +
        "A Big Bag (20 coins)                                        \n" +
        "A Shopping Bag (10 coins)                                   \n" +
      "------------------------------------------------------\n");
  return 1; }

  if (str=="light" || str=="lights" ||
      str=="illuminator" || str=="illuminators") {

write("------------------------------------------------------\n"+
        "A Lantern (100 coins)                                       \n" +
        "A Oil Lamp (50 coins)                                       \n" +
        "A Torch (40 coins)                                          \n" +
     "-------------------------------------------------------\n");


  return 1; }

/*
  else {
   write("Sorry, but we don't have "+(str)+".\n");
  return 1;
*/

 }
buy(str) {
  int has, wc,cost,weight;
string short,long,id,id2;
  object dummy;
  object armour;
  int arm,al,level;
  

  cost=0; 

  if (!str) return 0;


  if (str=="broadsword" || str=="faunen broadsword") {
    wc = 15;
    cost = 4000;
    short = "The Faunen Broadsword";
    long = "A big long two-armed sword... full of mighty power.\n";
    id= "sword";
    id2 = "broadsword";
    level = 12;
    al = 0;
    weight= 2;
  }
  
  if (str=="elfen longsword") {
    wc= 14;
    cost = 3000;
    short = "An Elfen Longsword";
    long = "A mighty weapon specially against hard enemies.\n";
    id = "longsword";
    id2 = "elfen longsword";
    level = 11;
    al = 0;
    weight = 2;
  }

  if (str=="sword" || str=="platinum sword") {
    wc = 13;
    cost = 1500;
    short = "A Platinum Sword";
    long = "A weapon which is one of the fines workmanship you ever have seen.\n";
    id = "sword";
    id2 = "platinum sword";
    level = 10;
    al = 0;
    weight = 3;
   }

  if (str=="hammer") {
    wc = 12;
    cost = 500;
    short = "A big Hammer";
    long = "A weapon which will do a very hard damage to all your enemies.\n";
    id = "hammer";
    id2 = "big hammer";
    level = 8;
    weight = 2;
  }

  if (str=="morningstar") {
    wc = 10;
    cost = 250;
    short = "A Morningstar";
    long = "A simple morningstar, but a very good weapon.\n";
    id = "morningstar";
    level = 6;
    weight = 3;
  }

  if (str=="axe" || str=="war axe") {
    wc = 8;
    cost = 50;
    short = "A War Axe";
    long = "You see very good weapon.\n";
    id = "axe";
    id2 = "war axe";
    level = 4;
    weight = 2;
  }

  if (str=="knife" || str=="platinum knife") {
    wc = 6;
    cost = 25;
    short = "A Platinum Knife";
    long = "You see a sharp knife made from platinum.\n";
    id = "knife";
    id2 = "platinum knife";
    level = 2;
    weight = 1;
  }

  if (str=="cudgel" || str=="rabbit cudgel") {
    wc = 6;
    cost = 12;
    short = "A Rabbit Cudgel";
    long = "You see a cheap weapon for very small enemies.\n";
    id = "cudgel";
    id2 = "rabbit cudgel";
    level = 1;
    weight = 1;
  }

  if (str=="mail") {
    write("The shopkeeper says: Which one would you like the\n"+
           "platinum or the Powermail.\n");
    return 1;
  }

  if (str=="platinum mail") {
    wc = 3;
    short = "A Platinum Mail";
    long = "A strong protection mail against strong enemies.\n";
    cost=4000;
    id = "armour";
    id2 = "mail";
    weight = 2;
    arm = 1;
  }

  if (str=="powermail" || str=="black powermail") {
    wc = 3;
    cost = 2000;
    short = "A Black Powermail";
   long = "This strange shimmering was made by the smith of dark power.\n";
    id = "armour";
    id2 = "powermail";
    weight = 3;
    arm = 1;
  }

  if (str=="jacket") {
    write("The shopkeeper says: Which one would you like,\n"+
           "the drakeleather, the snakeleather, the adventurers,\n"+
            "or the Bisonleather jacket.\n");
    return 1;
  }

  if (str=="drakeleather" || str=="drakeleather jacket") {
    wc = 2;
    cost = 1000;
    short = "A Drakeleather Jacket";
    long = "A beautiful jacket made from drakeskin.\n";
    id = "armour";
    id2 = "jacket";
    weight = 2;
    arm = 1;
  }

  if (str=="snakeleather" || str=="snakeleather jacket") {
    wc = 2;
    cost = 400;
    short = "A Snakeleather Jacket";
    long = "A light jacket made from drakeskin.\n";
    id = "armour";
    id2 = "jacket";
    weight = 2;
    arm = 1;
  }

  if (str=="adventurers" || str=="adventurers jacket") {
    wc = 1;
    cost = 250;
    short = "An Adventureres Jacket";
    long = "The famous adventurers jacket.\n";
    id = "armour";
    id2 = "jacket";
    weight = 1;
    arm = 1;
  }

  if (str=="bisonleather" || str=="bisonleather jacket") {
    wc = 1;
    cost = 125;
    short = "A Bisonleather Jacket";
    long = "A heavy brown leather jacket.\n";
    id = "armour";
    id2 = "jacket";
    weight = 2;
    arm = 1;
  }

  if (str=="simple jacket") {
    wc = 1;
    cost = 25;
    short = "A Simple Jacket";
    long = "A nice, simple jacket";
    id = "armour";
    id2 = "jacket";
    weight = 2;
    arm = 1;
  }

  if (str=="robe") {
    write("The shopkeeper says: Which one would you like to buy,\n"+
          "the monks or the Priest robe.\n");
    return 1;
  }

  if (str=="monks robe") {
    wc = 0;
    cost = 1000;
    short = "A Monks Robe";
    long = "A black robe with a strange protection.\n";
    id = "cloak";
    id2 = "robe";
    weight = 1;
    arm = 1;
  }

  if (str=="priest robe") {
    wc = 0;
    cost = 250;
    short = "A Priest Robe";
    long = "A simple black priest robe.\n";
    id = "cloak";
    id2 = "robe";
    weight = 1;
    arm = 1;
  }

  if (str=="raincoat" || str=="simple raincoat") {
    wc = 0;
    cost = 50;
    short = "A Simple Raincoat";
    long = "A nice blue raincoat.\n";
    id = "cloak";
    id2 = "raincoat";
    weight = 2;
    arm = 1;
  }

  if (str=="gauntlets" || str=="gauntlets" || str=="platinum gauntlets") {
    wc = 0;
    cost = 1000;
    short = "Platinum Gauntlets";
    long = "Beautiful gauntlets with some strange protection power.\n";
    id = "glove";
    id2 = "gauntlets";
    weight = 1;
    arm = 1;
  }
  
  if (str=="gloves" || str=="power gloves") {
    wc = 1;
    cost = 200;
    short = "Power Gloves";
    long = "A glove with some strange protection power.\n";
    id = "glove";
    id2 = "gloves";
    weight = 1;
    arm = 1;
  }

  if (str=="glove" || str=="spiky glove") {
    wc = 1;
    cost = 50;
    short = "A Spiky Glove";
    long = "The famous glove with the dangerous iron spikes.\n";
    id = "glove";
    weight = 2;
    arm = 1;
  }

  if (str=="goiserer") {
    wc = 1;
    cost = 250;
    short = "A pair of Goiserer";
    long = "Heavy mountain boots.\n";
    id = "boot";
    id2 = "goiserer";
    weight = 1;
    arm = 1;
  }

  if (str=="boots" || str=="platinum boots") {
    wc = 1;
    cost = 100;
    short = "Platinum Boots";
    long = "Pretty platinum boots.\n";
    id = "boot";
    id2 = "boots";
    weight = 1;
    arm = 1;
  }

  if (str=="globetrotters") {
    wc = 1;
    cost = 50;
    short = "A pair of Globetrotters";
    long = "Really fine leather shoes.\n";
    id = "boot";
    id2 = "globetrotters";
    weight = 2;
    arm = 1;
  }


  if (str=="helmet") {
    write("The shopkeeper says: Would you like the Magic Helmet,\n"+
           "the platinum, the adventurer or the Leather Helmet.\n");
    return 1;
  }

  if (str=="spiked helmet") {
    wc = 1;
    cost = 500;
    short = "A Spiky Helmet";
    long = "A helmet with some strange protection power.\n";
    id = "helmet";
    id2 = "spiky helmet";
    weight = 1;
    arm = 1;
  }

  if (str=="platinum helmet") {
    wc = 1;
    cost = 250;
    short = "A Platinum Helmet";
    long = "A beautiful platinum Helmet";
    id = "helmet";
    id2 = "platinum helmet";
    weight = 1;
    arm = 1;
  }

  if (str=="adventurer helmet") {
    wc = 1;
    cost = 100;
    short = "An Adventurer helmet";
    long = "The famous adventurer helmet.\n";
    id = "helmet";
    id2 = "adventurer helmet";
    weight = 1;
    arm = 1;
  }

  if (str=="leather helmet") {
    wc = 1;
    cost = 40;
    short = "A Leather Helmet";
    long = "A simple leather helmet, not very exclusive.\n";
    id = "helmet";
    id2 = "Leather Helmet";
    weight = 2;
    arm = 1;
  }

  if (str=="shield") {
    write("The Shopkeeper says: Which shield would you like,\n"+
         "the Shield of Brightness, the platinum, the leather,\n"+
          "or the Tower Shield.\n");

    return 1;
  }

  if (str=="shield of black power" || str=="shield black power") {
    wc = 1;
    cost = 1000;
    short = "A Shield of Black Power";
    long = "A shield whitch dark protection power.\n";
    id = "shield";
    id2 = "shield of black power";
    weight = 1;
    arm = 1;
  }

  if (str=="platinum shield") {
    wc = 1;
    cost = 500;
    short = "A Platinum Shield";
    long = "A really beautiful platinum shield";
    id = "shield";
    id2 = "platinum shield";
    weight = 2;
    arm = 2;
  }

  if (str=="tower shield") {
    wc = 1;
    cost = 250;
    short = "A Tower Shield";
    long = "The shield of dark power.\n";
    id = "shield";
    id2 = "tower shield";
    weight = 2;
    arm = 1;
  }

  if (str=="leather shield") {
    wc = 1;
    cost = 45;
    short = "A Leather Shield";
    long = "A simple leather shield.\n";
    id = "shield";
    id2 = "leather shield";
    weight = 3;
    arm = 1;
  }

  if (str=="rucksack") {
    if (TPM < 50) {
      write("The shopkeeper says: Sorry, but you don't have enough funds...\n");
      return 1; 
    }
    write("You buy a rucksack.\n");
    say(TPN+ " buys a rucksack.\n");
    dummy=clone_object(OBJ+"rucksack");
    if (transfer(dummy,TP )) move_object(dummy, ETP);
    TP->add_money(-50);
    return 1;
  }

  if (str=="big bag") {
    if(TPM < 20) {
      write("The shopkeeper says: Sorry, but you don't have enough funds..\n");
      return 1;
    }
    write("The shopkeeper gives you a big bag.\n");
    say(TPN+ " buys a big bag.\n");
    dummy=clone_object(OBJ+"big_bag");
    if (transfer(dummy,TP)) move_object(dummy,ETP);
    TP->add_money(-20);
    return 1;
  }

  if (str=="shopping bag") {
    if(TPM < 10) {
      write("The shopkeeper says: Sorry, but you don't have enough funds..\n");
      return 1;
    }
    write("The shopkeeper gives you a shopping bag.\n");
    say(TPN+ " buys a shopping bag:\n");
    dummy=clone_object(OBJ+"shopping_bag");
    if (transfer(dummy,TP)) move_object(dummy, ETP);
    TP->add_money(-10);
    return 1;
  }

  if (str=="lantern") {
  if(TPM < 100) {
      write("The shopkeeper says: Sorry, but you don't have enough funds..\n");
      return 1;
    }
    write("The shopkeeper gives you a lantern.\n");
    say(TPN+" buys a lantern.\n");
    dummy=clone_object(OBJ+"lantern");
    if (transfer(dummy, TP)) move_object(dummy, ETP);
    TP->add_money(-100);
    return 1;
  }

  if (str=="torch") {
    if(TPM < 40) {
      write("The shopkeeper says: Sorry, but you don't have enough funds..\n");
      return 1;
    }
    write("The shopkeeper gives you a torch.\n");
    say(TPN+" buys a torch.\n");
    dummy=clone_object(OBJ+"torch");
    if (transfer(dummy,TP)) move_object(dummy, ETP);
    TP->add_money(-40);
    return 1;
  }

  if (str=="lamp" || str=="oil lamp") {
  if (TPM < 60) {
      write("The shopkeeper says: Sorry but you don't have enough funds..\n");
      return 1;
    }
    write("The shopkeeper gives you an: oil lamp.\n");
    say(TPN+" buys an oil lamp.\n");
    dummy=clone_object(OBJ+"lamp");
    if (transfer(dummy, TP)) move_object(dummy, ETP);
    TP->add_money(-60);
    return 1;
  }
 if (str=="soul" || str=="extended soul") {
  if (TPM < 400) {
   write("The shopkeeper says: Sorry but this magical item has its price.\n");
   return 1;
   }
  write("The shopkeeper gives you an extended soul.\n");
 write("The shopkeeper says: Hmmmm just type help exsoul to see the use of it.\n");
    say(TPN+" buys an extended soul.\n");
   dummy=clone_object("tools/exsoul/exsoul");
  if (transfer(dummy, TP)) move_object(dummy, ETP);
   TP->add_money(-400);
  return 1;
   }
  if (str=="bottle") {
    write("The shopkeeper says: Which one would you like,\n"+
           "the bottle of whisky, a bottle of apple juice,\n"+
           "cider or beer.\n");
    return 1;
  }

 if (str=="whiskey" || str=="bottle of whiskey" || str=="bottle whiskey") {
    if(TPM < 800) {
      write("The shopkeeper says: Sorry, but you don't have enough funds..\n");
      return 1;
    }
  write("The shopkeeper gives you a bottle of whiskey.\n");
  say(TPN+" buys a bottle of whiskey.\n");
  dummy=clone_object(OBJ+"whiskey");
    if (transfer(dummy, TP)) move_object(dummy, ETP);
    TP->add_money(-800);
    return 1;
  }
  if (str=="herbs" || str=="herbs juice" || str=="bottle of herbs juice") {
    if (TPM < 80) {
  write("The shopkeeper says: Sorry, but you don't have such lots of money.\n");
    return 1;
   }
  write("The shopkeeper says: My are you thirsty!!!!!\n"+
       "The shopkeeper gives you a bottle of herbs juice.\n");
   say(TPN+" buys a bottle of herbs juice.\n");
   dummy=clone_object(OBJ+"citone");
   if (transfer(dummy, TP)) move_object(dummy, ETP);
   TP->add_money(-80);
   return 1;
  }
  if (str=="juice" || str=="apple juice" || str=="bottle of apple juice") {
     if (TPM < 30) {
     write("The shopkeeper says: Sorry, better go and earn 30 coins.\n");
     return 1;
    }
   write("The shopkeeper gives you a bottle of apple juice.\n");
   say(TPN+" buys a bottle of apple juice.\n");
   dummy=clone_object(OBJ+"apple_juice");
   if (transfer(dummy,TP)) move_object(dummy, ETP);
   TP->add_money(-30);
   return 1;
  }
  if (str=="water" || str=="mountain water" || str=="bottle of mountain water"){

   if (TPM < 15) {
   write("The shopkeeper burst into tears.\n\n"+
         "The shopkeeper sniffs and says: Hmm sorry, but you have less funds.\n");
   return 1;
  }
  write("The shopkeeper says: Well thirsty ?????\n"+             
        "The shopkeeper gives you a bottle of mountain water.\n");
  say(TPN+" buys a bottle of mountain water.\n");
  dummy=clone_object(OBJ+"water");
  if (transfer(dummy,TP)) move_object(dummy, ETP);
  TP->add_money(-15);
  return 1;
 }


  if (str=="energizer") {
    if (TPM < 500) {
      write("The shopkeeper says: Sorry, but you don't have enough funds..\n");
      return 1;
    }
    write("The shopkeeper gives you an energizer.\n");
    say(TPN+" buys an energizer.\n");
    dummy=clone_object(OBJ+"energizer");
    if (transfer(dummy, TP)) move_object(dummy, ETP);
    TP->add_money(-500);
    return 1;
  }

  if (str=="cider") {
    if (TPM < 40) {
      write("The shopkeeper says: Sorry, but you don't have enough funds..\n");
      return 1;
    }
    write("The shopkeeper gives you a bottle of cider.\n");
    say(TPN+" buys a bottle of cider.\n");
    dummy=clone_object(OBJ+"cider");
    if (transfer(dummy, TP)) move_object(dummy, ETP);
    TP->add_money(-40);
    return 1;
  }


  if (str=="beer" || str=="bottle of beer" || str=="bottle beer") {
    if (TPM < 20) {
      write("The shopkeeper says: Sorry, but you don't have enough funds..\n");
      return 1;
    }
    write("The shopkeeper gives you a bottle of beer.\n");
    say(TPN+" buys a bottle of beer.\n");
    dummy=clone_object(OBJ+"beer");
    if (transfer(dummy, TP)) move_object(dummy, ETP);
    TP->add_money(-25);
    return 1;
  }

  if (str=="muesly" || str=="block" || str=="muesly block") {
    if (TPM < 1000) {
      write("The shopkeeper says: Sorry, but you don't have enough funds..\n");
      return 1;
    }
  write("The shopkeeper gives you a muesly block.\n");
    say(TPN+" buys a muesly block.\n");
  dummy=clone_object(OBJ+"muesly_block");
    if (transfer(dummy, TP)) move_object(dummy, ETP);
    TP->add_money(-1000);
    return 1;
  }

  if (str=="chicken" || str=="chicken from wienerwald") {
    if (TPM < 100) {
      write("The shopkeeper says hungry: "+
	    "Sorry, but you don't have enough funds..\n");
      return 1; 
    }
  write("The shopkeeper gives you a roast chicken from wienerwald.\n");
    say(TPN+" buys a original chicken from wienerwald.\n");
    dummy=clone_object(OBJ+"chicken");
    if (transfer(dummy, TP)) move_object(dummy, ETP);
    TP->add_money(-100);
    return 1;
  }

  if (str=="chips" || str=="fish" || str=="fish and chips") {
    if (TPM < 50) {
      write("The shopkeeper says: Sorry, but you don't have enough funds..\n");
      return 1;
    }
    write("You buy fish and chips.\n");
    say(TPN+" buys fish and chips.\n");
    dummy=clone_object(OBJ+"fish_and_chips");
    if (transfer(dummy, this_player())) move_object(dummy, ETP);
    TP->add_money(-50);
    return 1; 
  }
  if (str=="rope" || str=="a rope") {
    if (TPM < 200) {
      write("The shopkeeper says: Sorry, but you don't have enough funds..\n");
      return 1;
  }
    write("You buy a rope.\n");
    say(TPN+" buys a rope.\n");
    dummy=clone_object(OBJ+"rope");
    if (transfer(dummy, TP)) move_object(dummy, ETP);
    TP->add_money(-200);
    return 1;
  }

  if (str=="sandwich" || str=="cheese and ham sandwich") {
    if (TPM < 8) {
      write("The shopkeeper says: Sorry, but you don't have enough funds..\n");
      return 1;
    }
    write("The shopkeeper gives you a cheese and ham sandwich.\n");
    say(TPN+" buys a cheese and ham sandwich.\n");
    dummy=clone_object(OBJ+"sandwich");
    if (transfer(dummy, TP)) move_object(dummy, ETP);
    TP->add_money(-8);
    return 1;
  }

  if (TPM < 2*cost) {
    write("The shopkeeper says: Sorry you don't have "+2*cost+" coins.\n");
    return 1;
  }

  if(!cost) {
    write("The shopkeeper says: Sorry but we don't have that item, but.\n"+
        "if you really like it please sent a mail to my boss Whisky,\n"+
           "maybe we can manage that.\n");
    return 1;
  }

  write("The shopkeeper gives you "+short+".\n");
  TP->add_money(-2*cost);

  if (arm > 0) {
    if (arm==2) {
      armour=clone_object(shieldpath);
    } else { armour=clone_object("obj/armour"); }

    armour->set_name(str);
    armour->set_ac(wc);    
    armour->set_weight(weight);
    armour->set_short(short);   
    armour->set_long(long);
    armour->set_size(TPS);
    armour->set_value(cost);    
    armour->set_type(id);

    if(al) {   armour->set_arm_light(al); }
    if (id) { armour->set_alias(id2); }      

    arm=0;

    if (transfer(armour, TP)) move_object(armour, ETP);
    return 1;
  } else { 

    dummy = clone_object("/players/whisky/genobj/real_weap");
    dummy->set_name(short);              
    dummy->set_long(long);
    dummy->set_class(wc);              
    dummy->set_level(level);
    dummy->set_use(1500);
    dummy->set_weight(weight);         
    dummy->set_value(cost);            
    dummy->set_alt_name(id);           
    if (id) {
      dummy->set_alias(id2);
    }

    if (transfer(dummy, TP)) move_object(dummy, ETP);
    write("The shopkeeper says: Always at your service.\n");
    return 1;
  }
}


sell(item) {
      object ob;

      if(!item)
         return 0;

      if (item == "all") {
         object next;

      ob = first_inventory(this_player());

      while(ob) {
      next = next_inventory(ob);
      if (!ob->drop() && ob->query_value()) {
      write(ob->short() + ":\t");
  do_sell(ob);
 }

  ob = next;
 }

  write("Yep.\n");
  return 1;
 }

     ob = present(item, TP);       

     if (!ob)
     ob = present(item,TO);

     if (!ob) {
     write("The shopkeeper says: sorry but we don't buy that.\n");
  return 1;
  }

  do_sell(ob);
  return 1;
 }

  do_sell(ob) {
    int value, do_destroy;
  value = ob->query_value();


    if (environment(ob) == TP) {
    int weight;

    if (call_other(ob,"drop",0)) {
    write("You can't drop that.\n");
    return 1;

  }

    weight = call_other(ob, "query_weight",0);
    TP->add_weight(-weight);
}
    if (!value) {
    write("The shopkeeper says: Sorry, this item has no value, but\n"+
          "ok I'll give you one coin.\n");
    value = 1;
}

    if (value >= 8000) {
    write("The shopkeeper says: Well I can give you only 1500 coins.\n");
    value = 1500;
                   }
    else if (value >= 4000) {
    write("The shopkeeper says: Well I can give you only 1200 coins.\n");
    value = 1200;
                  }
    else if (value >= 1000) {
    write("The shopkeeper says: Well I can give you only 1000 coins.\n");
    value = 1000;
                   }

    write("The shopkeeper gives you ");write(value);write(" coins.\n");
    say(TP->query_name()+" sells a "+call_other(ob,"short",0)+ ".\n");

    destruct(ob);
    TP->add_money(value);
  return 1;
 }

  value(item) {
  int value;
   object ob; 
    if(!item)
      return 0;

    if(!(ob = present(item,TP))) {
      say("The shopkeeper says: Sorry, but you haven't got such an item\n"); 
      return 1;
    }

    if(!(value = ob->query_value())) {
      write("The shopkeeper says: That item has no value.\n");
      return 1;
    }
    write("The Shopkeeper says: You would get ");
    write(value);write(" coins.\n");
    return 1;
  }

