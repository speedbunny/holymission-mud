inherit "/room/room";

int store;

void reset(int arg) {

store = 80;

  if (arg) return;

  set_light(1);

  short_desc="The Mountain Brewery";

  long_desc="You have entered Bob's Mountain Brewery.  Only the finest " +
            "liquor is sold here.  There is a sign on the wall which " +
            "declaims the varieties of nectar sold here.\n";

  items=({"sign","You could read it",
        });

  dest_dir=({"/players/emerald/good/shops/shop_street4","south",
           });

  clone_list=({
    1,1,"bob","obj/monster", ({
      "set_name","bob",
      "set_race","human",
      "set_short","Bob, the brewmaster",
      "set_long","Bob is the Brewmaster of the Mountain Brewery.\n",
      "set_level",60,
      "set_wc",20,
      "set_ac",20,
    }),
  });

   ::reset();


}

void init() {
  ::init();
  add_action("_order","order");
  add_action("_order","buy");
  add_action("_read","read");
}
_read(str) {
  if (str=="sign") {
    write("Mountain Brewery.\n\n" +
          "This is the famous Mountain Brewery!\n" +
          "We sell kegs here!  The kegs are listed below.\n\n" +
          "1.  5 gl. Keg of Rum       :   600 coins\n"+
          "2. 10 gl. Keg of Rum       :  1200 coins\n"+
          "3.  5 gl. Keg of Jack      :  4000 coins\n"+
          "4. 10 gl. Keg of Jack      :  8000 coins\n\n"+
          "Just type in 'buy small jack' or 'buy small rum' for the\n" +
          "5 gl. kegs, or 'buy large jack', or 'buy large rum' for 10gls.\n"+
          "You can also buy in numbers.\n");
    if(this_player()->query_wizard()) {
       write("Wizinfo: "+store+" kegs left.\n");
    }

    return 1;
  }
}

_order(str) {
  string name, short_desc, alt_name, long_desc;
  int value, cost, strength, taps, weight;
  object keg;

  if (!present("bob",this_object())) {
    write("Sorry, Bob is not here at the moment.  Come back later.\n");
    return 1;
  }


  switch(str) {
    case "1" :
    case "small rum" :
    case "small keg of rum" :
      short_desc = "A small keg of rum";
      long_desc = "A small keg of Mountain rum.";
      alt_name = "keg of rum";
      taps = 12;
      value = 600;
      strength = 10;
      weight = 2;
      break;
    case "2" :
    case "large rum" :
    case "large keg of rum" :
      short_desc = "A large keg of rum";
      long_desc = "A large keg of Mountain rum.";
      alt_name="keg of rum";
      taps = 28;
      value = 1200;
      strength = 10;
      weight = 4;
      break;
    case "3" :
    case "small jack" :
    case "small keg of jack" :
      short_desc = "A small keg of Jack Daniel's";
      long_desc = "A small keg of Mountain Jack.";
      alt_name = "keg of jack";
      taps = 12;
      value = 4000;
      strength = 30;
      weight = 2;
      break;
    case "4" :
    case "large jack" :
    case "large keg of jack" :
      short_desc = "A large keg of Jack Daniel's";
      long_desc = "A large keg of Mountain Jack.";
      alt_name = "keg of jack";
      taps = 28;
      value = 8000;
      strength = 30;
      weight = 4;
      break;
    default :
      write("Bob says: I'm sorry, we don't sell "+str+" here.\n");
      return 1;
    }

  if (!store) {
    write("Bob says: I am sorry but we are all out of kegs at the moment."+
          "  Please, come back later.\n");
        return 1;
  }
  if(this_player()->query_money() < (value)) {
    write("Bob says: That would cost you "+(value)+" coins, which you "+
         "do not have.\n");
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
    write("Bob says: You cannot carry that much.\n");
    return 1;
  }
  store --;
  write("Bob gives you a "+alt_name+" for "+value+" coins.\n");
  this_player()->add_money(-value);
  return 1;
}
