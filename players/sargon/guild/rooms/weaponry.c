#include "/players/sargon/define.h"

inherit "room/room";
    int w1,w2,w3,w4,w5;

reset(arg) {
  w1=0;w2=0;w3=0;w4=0;w5=0;
  if (arg) return;
    set_light(1);
    short_desc="Erik the Red's Weaponry.";
    long_desc="You stand in the weaponry of Erik The Red!\n"+
              "This is the shop where the deadliest fighters buy their\n"+
              "weapons, knowing of the excellent quality and low \n"+
              "price. There are two huge furnace fires burning along\n"+
              "the northern wall. The air is sooty and smoky. The \n"+
              "fires are heating various pieces of metal, which are\n"+
              "being forged into swordblades & axe-heads. An assistant\n"+ 
              "is staying behind a big SIGN, read the sign to get\n"+ 
              "more information.\n";
    dest_dir= ({
              "/players/sargon/guild/rooms/hall2", "south",
              });
    items=({
          "sign","   ============================================= \n"+
                 "   =          Erik the Red's Weaponry          = \n"+
                 "   ============================================= \n"+
                 "   =                                           = \n"+
                 "   =  1.) A MANGLER               10000 coins  = \n"+
                 "   =  2.) A SILVER BROADSWORD      6000 coins  = \n"+
                 "   =  3.) A WAR AXE                4000 coins  = \n"+
                 "   =  4.) A HEAVY MACE             2000 coins  = \n"+
                 "   =  5.) A SHORTSWORD              800 coins  = \n"+
                 "   =                                           = \n"+
                 "   ============================================= \n", 
          "furnace","A large heater used for melting metal",       
          "air","dark and polluted with soot and thick smoke",
          "fire","hot flame being used to forge weapons",
          "metals","Being forged into deadly weapons",
                 });
                                                    
  }

init() {
  AA("buy","buy");
  AA("read","read");
  ::init();
  }
  read(str) {
    if (str!="sign") return;
    write(
                 "   ============================================= \n"+
                 "   =           Erik The Red's Weaponry         = \n"+
                 "   ============================================= \n"+
                 "   =                                           = \n"+
                 "   =  1.) A MANGLER               10000 coins  = \n"+
                 "   =  2.) A SILVER BROADSWORD      6000 coins  = \n"+
                 "   =  3.) A WAR AXE                4000 coins  = \n"+
                 "   =  4.) A HEAVY MACE             2000 coins  = \n"+
                 "   =  5.) A SHORTSWORD              800 coins  = \n"+
                 "   =                                           = \n"+
                 "   ============================================= \n");

     say(TPN+" reads the sign.\n");
   return 1;                                                 
  }

  buy(str) {
    object dummy,assi;
    int wc,value,weight;
    string short,long,alias,name,type;

    if (!str) {
      write("The Erik looks confused and abit annoyed.\n");
    return 1;
    }
    else if (str=="mangler" || str=="1") {
      if (w1 > 2) {
        write("Erik The Red says: Sorry,but we are sold out.\n");
      return 1;
       }
      wc=19;
      value=5000;
      weight=2;
      short="A mangler";
      long= "This weapon is a huge sword of 1.3 meters in length,\n"+
            "yet it weighs almost nothing. The blade is long and\n"+ 
            "made of many jagged edges or teeth which gives this\n"+  
            "sword a high tissue damage rating.\n\n";
      alias="sword";
      name= "mangler";
      w1++;
    }
    else if (str=="broadsword" || str=="2") {
      if (w2 > 4) {
        write("The Erik says: Sorry, but we are sold out.\n");
       return 1;
      }
      wc=18;
      value=3000;
      weight=2;
      short= "A silver broadsword";
      long=  "A large silver sword 1.2 meters in length, yet light\n"+
             "enough to weild in one hand. Many warriors consider silver\n"+
             "broadswords to be one of the finest weapons ever crafted.\n\n";
      alias= "sword";
      name=  "broardsword";
      w2++;
    }
    else if (str=="axe" || str=="3") {
      if (w3 >6) {
        write("The Erik says: Sorry, but we ran out of that.\n");
       return 1;
      }
      wc=15;
      value=2000;
      weight=3;
      short= "a war axe";
      long=  "This is a large two headed axe. Its shaft is nearly\n"+
             "one meter in length and weighs only a few pounds. The\n"+
             "head is made of top quality elven steel.\n\n";
      alias= "axe";
      name=  "axe";
      w3++;
    }
    else if (str=="mace" || str=="4") {
      if (w4 >8) {
        write("The Erik says: Sorry, but we ran out.\n");
      return 1;
      }
      wc=13;
      value=500;
      weight=4;
      short= "A heavy Mace";
      long=  "This heavy mace is a little over half a meter in\n"+
             "length, and weighs about a pound or two. This blunt\n"+
             "weapon looks like in can do some serious damage to\n"+
             "ones body.\n\n";
      alias= "mace";
      name=  "mace";
      w4++;
    }
    else if (str=="shortsword" || str=="5") {
      if (w5 > 10) {
        write("The assistant says: Sorry, but we are sold out.\n");
       return 1;
      }
      wc=13;
      value=400;
      weight=1;
      short= "A shortsword";
      long=  "This weapon looks like an oversized, three-pronged\n"+
             "dagger. It's excellent for countering the massive\n"+
             "attacks of bladed weapons. And slashing the bellies of enemies \n\n";
      alias= "sword";
      name=  "shortsword";
      w5++;
    }
    else {
    write("The Erik screams: We don't sell that! Does this look like K-Mart?\n");
    return 1;
    }
    if (TP->query_money() < (value*2)) {
       write("Erik shrugs helplessly: Sorry, but that would\n"+
       "cost you "+(value*2)+" coins which you don't have.\n");
     }
    else {
    dummy=CO("/players/sargon/guild/obj/wield.c");
    dummy->set_name(name);
    dummy->set_alias(alias);
    dummy->set_short(short);
    dummy->set_long(long);
    dummy->set_value(value);
    dummy->set_weight(weight);
    dummy->set_class(wc);   
    write("The Erik hands you "+short+".\n"+
    "The Erik The Red cackles: go kill 'em.\n");
    TR(dummy,TP);
    TP->add_money(-2*value);
    return 1;
   }
  return 1;
 }
