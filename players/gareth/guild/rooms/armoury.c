#include "/players/gareth/define.h"

inherit "room/room";
    int w1,w2,w3,w4,w5;

reset(arg) {
  w1=0;w2=0;w3=0;w4=0;w5=0;
  if (arg) return;
    set_light(1);
    short_desc="Sledge's armoury.";
    long_desc="This is the armoury of the once great general, Sledge.\n"+
              "This is the place where the greatest fighters buy their\n"+
              "armour, knowing of the excellent quality and low \n"+
              "price. There is a huge furnace fire burning along the \n"+
              "wall. The air is blackened with soot and smoke. The\n"+
              "fire is heating various metals, which are being forged\n"+
              "into breastplates and shield handles. An assistant is \n"+
              "staying behind a big SIGN. Just read it to for more\n"+ 
              "information.\n";
    dest_dir= ({
              "/players/gareth/guild/rooms/hall", "north",
              });
    items=({
    "sledge","An old fighter waiting to serve you",
          "sign","    =============================================\n"+
                 "    =         General  Sledge's  Armoury        =\n"+
                 "    =============================================\n"+
                 "    =                                           =\n"+
                 "    =  1.  Banded Chain             8000 coins  =\n"+
                 "    =  2.  Ringmail                 4000 coins  =\n"+
                 "    =  3.  Mirror Shield            4000 coins  =\n"+
                 "    =  4.  Silver Gloves            2000 coins  =\n"+
                 "    =  5.  A Madman's Helmet         800 coins  =\n"+
                 "    =                                           =\n"+
                 "    =============================================\n" });
                                                    
  }

init() {
  add_action("buy","buy");
  add_action("read","read");
  ::init();
  }
  read(str) {
    if (str!="sign") return;
    write(
                 "    =============================================\n"+
                 "    =         General  Sledge's  Armoury        =\n"+
                 "    =============================================\n"+
                 "    =                                           =\n"+
                 "    =  1.  Banded Chain             8000 coins  =\n"+
                 "    =  2.  Ringmail                 4000 coins  =\n"+
                 "    =  3.  Mirror Shield            4000 coins  =\n"+
                 "    =  4.  Silver Gloves            2000 coins  =\n"+
                 "    =  5.  A Madman's Helmet         800 coins  =\n"+
                 "    =                                           =\n"+
                 "    =============================================\n");

     say(TPN+" reads the sign.\n");
   return 1;                                                 
  }

  buy(str) {
    object dummy,assi;
    int ac,value,weight,light;
    string short,long,alias,name,type;

  /* Gareth while I find this quite humorous you really can't lock peple out
      of a guild shop no matter how annoying they may be
      Haplo 4-21-96  
    if (TP->query_real_name() == "cyclop") {
       write("We Don't serve people like you! - go away jerkoff !\n");
    return 1;
    }

  */
    if (!str) {
      write("Sledge looks puzzled.\n");
    return 1;
    }
    else if (str=="chain" || str=="1") {
      if (w1 > 10) {
        write("Sledge says: Sorry, none in stock.\n");
      return 1;
       }
      ac=5;
      value=4000;
      weight=3;
      short="Banded chain";
      long= "A suit of Banded chain. This armour is made of\n"+
            "overlapping helical metal strips sewn to the back\n"+
            "of chainmail. This armour protects all the vulnerable\n"+
            "areas. \n\n";
      alias="chain";
      name= "banded chain";
      type="armour";
      w1++;
    }
    else if (str=="ringmail" || str=="2") {
      if (w2 > 10) {
        write("The assistant says: Sorry, none in stock.\n");
       return 1;
      }
      ac=4;
      value=2000;
      weight=4;
      short= "Ringmail";
      long=  "A suit of ringmail, cousin to chainmail; in which\n"+
             "metal rings are sewn into leather backing instead\n"+
             "of being interlaced.\n\n";
      alias= "mail";
      name=  "ringmail";
      type= "armour";
      w2++;
    }
    else if (str=="shield" || str=="3") {
      if (w3 > 10) {
        write("The assistant says: Sorry, none in stock.\n");
       return 1;
      }
      ac=3;
      value=2000;
      weight=3;
      short= "Mirror Shield";
      long=  "A highly polished shield of adamantite. It \n"+
             "gleams in the light. It's light but strong; it \n"+
             "can defend from any frontal and flank attacks.\n\n";
      alias= "shield";
      name=  "shield";
      type="shield";
      w3++;
    }
    else if (str=="gloves" || str=="4") {
      if (w4 > 10) {
        write("Sledge says: Sorry, none in stock.\n");
      return 1;
      }
      ac=0;
      value=1000;
      weight=1;
      short= "Gauntlets";
      long=  "Typical armour to protect the hands of the.\n"+
             "wearer. These gloves feel strong yet light \n"+
             "enough to allow movement. \n\n";
      alias= "gauntlets";
      name=  "gloves";
      type= "gloves";

      w4++;
    }
    else if (str=="helmet" || str=="5") {
      if (w5 > 10) {
        write("Sledge says: Sorry, we are ran out.\n");
       return 1;
      }
      ac=1;
      value=400;
      weight=3;
      short= "Helmet";
      long=  "This helmet is high quality armour. It provides A great\n"+
             "deal of protection. and really good for doing head buts!\n\n";
      alias= "helm";
      name=  "helmet";
      type="helmet";
      w5++;
    }
    else {
      write("Sledge says: What?? What you see is what we have\n");
      return 1;
    }
    if (TP->query_money() < (value*2)) {
       write("Sledge shrugs angrily: Sorry, but that would\n"+
       "cost you "+(value*2)+" coins which you don't have fool!.\n");
     }
    else {
    dummy=CO(PG+"guild/obj/wear");
    dummy->set_name(name);
    dummy->set_alias(alias);
    dummy->set_short(short);
    dummy->set_long(long);
    dummy->set_value(value);
    dummy->set_weight(weight);
    dummy->set_ac(ac);   
    dummy->set_type(type);
    write("Sledge tosses you "+short+".\n"+
    "The Fighter grins: come back soon.\n");
    TR(dummy,TP);
    TP->add_money(-2*value);
    return 1;
   }
  return 1;
 }
