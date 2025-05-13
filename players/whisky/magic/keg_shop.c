
inherit "room/room";
   object teela;
   int store;
 
reset(arg) {
  store = 80;
  
   if (!teela) {
      teela=clone_object("players/whisky/magic/teela");
      move_object(teela,this_object());
      tell_room(environment(teela),"Teela arrives.\n");
      }

  if (arg) return;
  set_light(1);
  short_desc= "In the keg shop";
  long_desc=
    "You are standing in the famous brewery of Teela. You can buy\n"+
    "many kinds of kegs here, but the selection is limited. There\n"+
    "is a sign hanging on the wall. Just type 'read sign' to see\n"+
    "what Teela's brewery got.\n";
        
        items=({
        "floor","An oak-wooden floor",
                });

    dest_dir=({ 
      "players/llort/guild/tower/hall2","south" });
  
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
     "                    TEELA'S BREWERY                      \n"+
     "#######################################################\n"+
     "We offer:\n\n"+
     "Nr: Sort:                                    Cost:       \n"+
     "1  A big Keg of Brandy                       5000 coins \n"+
     "2  A small Keg of Brandy                     3000 coins \n"+
     "3  A big Keg of Whiskey                      2500 coins \n"+
     "4  A small Keg of Whiskey                    1500 coins \n"+
     "5  A big Keg of Rum                          1250 coins \n"+
     "6  A small Keg of Rum                         750 coins \n"+
     "You can buy in numbers or in letters. For example 'buy 1'\n"+
     "or 'buy big brandy' to get a big keg of brandy.\n");
     
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
 
 if (!present("teela",this_object())) {
    write("Sorry, Teela is having a break, try later.\n");
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
    write("Teela says: Sorry but we don't sell "+str+" here.\n");
    return 1;
  }
 
  if (!store) {
     write("Teela says: Sorry but we are out of kegs at the moment, please try later.\n");
     return 1;
    }
  else if (this_player()->query_money() < (value*2)) {
    write("Teela says: That would cost you "+(value*2)+" coins, which you don't have.\n");
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
     write("Teela says: You can't carry that much.\n");
     return 1;
     }
  store --;
  write("Teela gives you a "+alt_name+" for "+(value*2)+" coins.\n");
  
  this_player()->add_money(-(2*value));
  
 return 1;
 
 }
    
