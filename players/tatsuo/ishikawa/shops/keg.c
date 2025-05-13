
inherit "room/room";
   object sunaki;
   int store;
 
reset(arg) {
  store = 80;
  
   if (!sunaki) {
	sunaki =clone_object("players/tatsuo/guild/npc/sunaki");
      move_object(sunaki,this_object());
      tell_room(environment(sunaki),"Sunaki arrives.\n");
      }

  if (arg) return;
  set_light(1);
  short_desc= "The Sake Shop";
  long_desc=
    "This is the popular Sake shop of the samurai's. It is where you will find\n"+
    "many samurai at all hours of the day relaxing and healing. You can see this\n"+
    "is a well stocked shop by the full shelves. The walls are made of wood and\n"+
    "there is a counter behind which Sunaki is standing. There are rattan couches\n"+
    "with soft blue pillows and wooden tables with carvings etched into it. You \n"+
    "feel a relaxed atmosphere and are instantly refreshed just ny entering here.\n"+
    "There are several windows lighting this place and giving it a warm cheery glow\n";
        
        items=({
        "floor","An oak-wooden floor",
	"walls","The walls are made of wood",
	"wall","The wall is made of wood",
	"shelf","The shelves are filled with kegs of all sorts",
	"shelves","The shelves have lots of kegs",
	"pillow","There are two of them they are made of blue silk",
	"pillows","There are two pillows made of blue silk",
	"silk","The blue silk is fine and smooth very expensive, but very comfortable",
		});

    dest_dir=({ 
"players/tatsuo/guild/stair3b","west",
	"players/tatsuo/guild/conf_room","north",
  
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
     "                   ISHIKAWAN SAKE SHOP                   \n"+
     "#######################################################\n"+
     "We offer:\n\n"+
     "Nr: Sort:                                    Cost:       \n"+
     "2  A big Keg of Ishikawan Brandy             5000 coins \n"+
     "1 A small Keg of Ishikawan Brandy            3000 coins \n"+
     "3  A big Keg of Whiskey                      2500 coins \n"+
     "4  A small Keg of Whiskey                    1500 coins \n"+
     "5  A big Keg of Samurai Rum                  1250 coins \n"+
     "6  A small Keg of Samurai Rum                 750 coins \n"+
     "You can buy in numbers or in letters. For example 'buy 1'\n"+
     "or 'buy big brandy' to get a big keg of ishikawan brandy.\n");
     
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
 
 if (!present("sunaki",this_object())) {
    write("Sorry, Sunaki is having a break, try later.\n");
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
  taps = 30;
  value = 2500;
  strength = 30;
  weight = 4;
  
}
  else if (str == "small brandy" || str == "2") {
  short_desc = "A keg of brandy";
  long_desc = "A small keg of best brandy.";
  alt_name = "keg of brandy";
  taps = 20;
  value = 1500;
  strength = 30;
  weight = 2;
 
}
  else if (str == "big whiskey" || str=="3") {
  short_desc = "A keg of whiskey";
  long_desc = "A big keg of best whiskey.";
  alt_name = "keg of whiskey";
  taps =35;
  value = 1250;
 strength = 20;
  weight = 4;
  }
  
  else if (str == "small whiskey" || str=="4") {
  short_desc = "A keg of whiskey";
  long_desc = "A small keg of best whiskey.";
  alt_name = "keg of whiskey";
  taps = 20;
  value = 750;
  strength = 20;
  weight = 2;
  
}
  else if (str == "big rum" || str=="5") {
  short_desc = "A keg of rum";
  long_desc = "A big keg of best rum.";
  alt_name = "keg of rum";
  taps = 35;
  value = 625;
  strength = 10;
  weight = 4;
  
}

 else if (str == "small rum" || str=="6") {
  alt_name = "keg of rum";
  short_desc = "A keg of rum";
  long_desc = "A small keg of best rum.";
  taps = 20;
  value = 375;
  strength = 10;
  weight = 2;
  
}
   
else {
    write("Sunaki says: Sorry but we don't sell "+str+" here.\n");
    return 1;
  }
 
  if (!store) {
     write("Sunaki says: Sorry but we are out of kegs at the moment, please try later.\n");
     return 1;
    }
  else if (this_player()->query_money() < (value*2)) {
    write("Sunaki says: That would cost you "+(value*2)+" coins, which you don't have.\n");
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
     write("Sunaki says: You can't carry that much.\n");
     return 1;
     }
  store --;
  write("Sunaki gives you a "+alt_name+" for "+(value*2)+" coins.\n");
  
  this_player()->add_money(-(2*value));
  
 return 1;
 
 }
    
