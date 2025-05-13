
/*recoded for use in the samurai guild by tatsuo*/
inherit "room/room";
   object hekayashi;
   int store;
 
reset(arg) {
  store = 80;
  
   if (!hekayashi) {
      hekayashi=clone_object("players/tatsuo/guild/npc/hekayashi");
      move_object(hekayashi,this_object());
      tell_room(environment(hekayashi),"Hekayashi enters.\n");
      }

  if (arg) return;
  set_light(1);
  short_desc= "In the Sake shop";
  long_desc=
    "You have entered Aragoya Hekayashi's Sake shop. It is a relaxed shop where\n"+
    "battle weary samurai come to heal and relax. There are many windows letting\n"+
    "in large amounts of light give the shop a cheery warm glow. The room has a\n"+
    "counter with polished wooden finish. There are several rattan couches with\n"+
    "blue pillows on them. You feel refreshed walking into the shop.\n"+
    "There is a sign hanging on the wall.\n";
        
        items=({
        "floor","The floor is made of rare teak wood",
        "windows","There are many windows letting in the bright sun light",
        "sign","The sign has strange oriental letters on it",
        "counter","The counter is made of fine polished teak",
        "couches","The couches are made of wicker woven in a strong manner",
        "pillows","The pillows are made of fine blue silk",
        "silk","This is valuable oriental silk spun by the special sik-worm",
                });

    dest_dir=({ 
      "players/dancer/guild/tower/hall2","south" });
  
}
 
init() {
    add_action("order","order"); 
    add_action("order","buy"); 
    add_action("read","read");
   ::init();
}
read(str) {
 if (str=="sign" || str=="menu") {
write(
     "#######################################################\n"+
     "                 HEKAYASHI'S SAKE SHOP                   \n"+
     "#######################################################\n"+
     "We offer:\n\n"+
     "Nr: Sort:                                    Cost:       \n"+
     "1  A big Keg of Ishikawan Brandy             5000 coins \n"+
     "2  A small Keg of Ishikawan Brandy           3000 coins\n"+
      "3  A big Keg of Samurai Whisky              2500 coins \n"+
     "4  A small Keg of Samurai Whisky             1500 coins \n"+
      "5  A big Keg of Nipon Rum                   1250 coins \n"+
      "6 A small Keg of Nipon Rum                   750 coins \n"+
      "To buy a keg order by number.\n"+
      "For example 'buy 1'\n");
     
     if (this_player()->query_wizard()) {
       write("Wizinfo: "+store+" kegs left.\n");
       }
   
  return 1;
  }
}

order(str)
{
 string name, short_desc, alt_name, long_desc;
 int value, cost, strength, taps, weight;
 object keg;
 
 if (!present("hekayashi",this_object())) {
    write("Sorry, Hekayashi is taking a break, try later.\n");
    return 1;
    }
     
 if (!str) {
  write("You might feel the chaos in this world..order what??\n");
  return 1;
}
  if (str == "big brandy" || str == "1") {
  short_desc = "A keg of brandy";
  long_desc = "A big keg of best brandy.";
  alt_name = "keg of brandy";
  taps = 28;
  value = 2500;
  strength = 30;
  weight = 4;
  
}
  else if (str == "small brandy" || str == "2") {
  short_desc = "A keg of brandy";
  long_desc = "A small keg of best brandy.";
  alt_name = "keg of brandy";
  taps = 16;
  value = 1500;
  strength = 30;
  weight = 2;
 
}
  else if (str == "big whiskey" || str=="3") {
  short_desc = "A keg of whiskey";
  long_desc = "A big keg of best whiskey.";
  alt_name = "keg of whiskey";
  taps = 28;
  value = 1250;
  strength = 14;
  weight = 4;
  }
  
  else if (str == "small whiskey" || str=="4") {
  short_desc = "A keg of whiskey";
  long_desc = "A small keg of best whiskey.";
  alt_name = "keg of whiskey";
  taps = 16;
  value = 750;
  strength = 14;
  weight = 2;
  
}
  else if (str == "big rum" || str=="5") {
  short_desc = "A keg of rum";
  long_desc = "A big keg of best rum.";
  alt_name = "keg of rum";
  taps = 28;
  value = 625;
  strength = 6;
  weight = 4;
  
}

 else if (str == "small rum" || str=="6") {
  alt_name = "keg of rum";
  short_desc = "A keg of rum";
  long_desc = "A small keg of best rum.";
  taps = 16;
  value = 375;
  strength = 6;
  weight = 2;
  
}
   
else {
    write("Hekayashi says: Sorry but we don't sell "+str+" here.\n");
    return 1;
  }
 
  if (!store) {
     write("Hekayashi says: Sorry but we are out of kegs at the moment, please try later.\n");
     return 1;
    }
  else if (this_player()->query_money() < (value*2)) {
    write("Hekayashi says: That would cost you "+(value*2)+" coins, which youdon't have.\n");
    return 1;
  }
  
  keg=clone_object("obj/keg");
  keg->set_name("keg");
  keg->set_alias(name);
  keg->set_alt_name(alt_name);
  keg->set_short(short_desc);
  keg->set_long(long_desc);  
  keg->set_value(value);
  keg->set_taps(taps);
  keg->set_weight(weight);
  keg->set_strength(strength);
  keg->set_consumer_mess("You tap from your "+alt_name+" SMOOOTHHHH !");
  keg->set_cosuming_mess(" taps from a "+alt_name+".");
  
  if (transfer(keg,this_player())) {
     write("Hekayashi says: You can't carry that much.\n");
     return 1;
     }
  store --;
 write("Hekayashi gives you a "+alt_name+" for "+(value*2)+" coins.\n");
  
  this_player()->add_money(-(2*value));
  
 return 1;
 
 }
    
