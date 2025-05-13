inherit "room/room";
#include "/players/saffrin/defs.h"

int store;

reset(arg) {

    store = 80;

    set_light(1);
    short_desc= "Yilli's World Famous Brewery";
    long_desc=
        "You are standing in the world famous brewery of Yilli.  "+
        "The brews here are reputed to be outstanding.  You can buy"+
        " various types of brews here, but the selection is limited "+
        "due to Yilli's time frame.  There is a sign hanging on the "+
        "wall with a list of the availible kegs.  Relax and feel "+
        "comfortable here.\n";
    items=({
        "floor","An oak-wooden floor",
        "sign", "There is something written here",
    });
    dest_dir=({ 
        TOWER+"room/hall1", "east",
        TOWER+"room/magebar", "southeast",
    });
    clone_list=({
          1, 1, "yilli", TOWER+"npc/yilli", 0,
    });
    ::reset();
}

init() {

    AA("order","order"); 
    AA("order","buy"); 
    AA("read","read");
    ::init();
}

read(str) {

  if (str=="sign" || str=="menu") {
     ME(
       "############################################################\n"+
       "#              YILLI'S WORLD FAMOUS BREWERY                #\n"+
       "############################################################\n"+
       "# Yilli offers:                                            #\n"+
       "#                                                          #\n"+
       "# Type:                            Cost:                   #\n"+
       "# 1  A keg of honey mead           5000 coins              #\n"+
       "# 2  A keg of chocolate bock       3000 coins              #\n"+
       "# 3  A keg of raspberry stout      2500 coins              #\n"
       "# 4  A keg of pumpkin lager        1500 coins              #\n"+
       "# 5  A keg of crystal ale          1250 coins              #\n"+
       "# 6  A keg of dark cider            750 coins              #\n"+
       "#                                                          #\n"+
       "# You can buy in numbers or in words.  For example, 'buy 1'#\n"+
       "# or 'buy honey mead' to get a keg of brandy of honey mead #\n"+
       "# Happy drinking!!!!!                                      #\n"+
       "############################################################\n");

       if (TPWIZ) {
          ME("Wizinfo: "+store+" kegs left.\n");
       }
  return 1;
  }
}

order(str) {

  string name, short_desc, alt_name, long_desc;
  int value, cost, strength, taps, weight;
  object keg;

  if (!present("yilli",TO)) {
     ME("Sorry, Yilli is on a brew break.  Come back later.\n");
  return 1;
  }

  if (!str) {
      ME("Yilli gives you a puzzled look.\n");
  return 1;
  }

  if (str == "honey mead" || str == "1") {
      short_desc = "A keg of honey mead";
      long_desc = "A keg of Yilli's best honey mead.";
      alt_name = "keg of mead";
      taps = 28;
      value = 2500;
      strength = 30;
      weight = 4;
  }
  else
  if (str == "chocolate bock" || str == "2") {
      short_desc = "A keg of chocolate bock";
      long_desc = "A keg of Yilli's best chocolate bock.";
      alt_name = "keg of bock";
      taps = 16;
      value = 1500;
      strength = 30;
      weight = 2;
  }
  else
  if (str == "raspberry stout" || str=="3") {
      short_desc = "A keg of raspberry stout";
      long_desc = "A keg of Yilli's best raspberry stout.";
      alt_name = "keg of stout";
      taps = 28;
      value = 1250;
      strength = 14;
      weight = 4;
  }
  else
  if (str == "pumpkin lager" || str=="4") {
      short_desc = "A keg of pumpkin lager";
      long_desc = "A keg of Yilli's best pumpkin lager.";
      alt_name = "keg of lager";
      taps = 16;
      value = 750;
      strength = 14;
      weight = 2;
  }
  else
  if (str == "crystal ale" || str=="5") {
      short_desc = "A keg of crystal ale";
      long_desc = "A keg of Yilli's best crystal ale.";
      alt_name = "keg of ale";
      taps = 28;
      value = 625;
      strength = 6;
      weight = 4;
  }
  else 
  if (str == "dark cider" || str=="6") {
      short_desc = "A keg of dark cider";
      long_desc = "A keg of Yilli's best dark cider.";
      alt_name = "keg of cider";
      taps = 16;
      value = 375;
      strength = 6;
      weight = 2;
  }
  else
  {
  ME("Yilli says: I am sorry but we don't carry "+str+" here.\n");
  return 1;
  }
  if (!store) {
      ME("Yilli says: I am sorry but we are all out of kegs at the moment.  Please, come back later.\n");
  return 1;
  }
  else
  if (TP->query_money() < (value*2)) {
      ME("Yilli says: That would cost you "+(value*2)+" coins, which you do not have.\n");
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

    if (transfer(keg,TP)) {
       ME("Yilli says: You cannot carry that much.\n");
    return 1;
    }

    store --;
    ME("Yilli gives you a "+alt_name+" for "+(value*2)+" coins.\n");

    TP->GP(-(2*value));

    return 1;
}
