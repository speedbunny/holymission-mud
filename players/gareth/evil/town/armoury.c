#include "/players/gareth/define.h"

inherit "room/room";
    int w1,w2,w3,w4,w5;

reset(arg) {
  w1=0;w2=0;w3=0;w4=0;w5=0;
  if (arg) return;
    set_light(1);
    short_desc="Merimack's armoury.";
    long_desc="This is the armoury of the once great general, Merimack.\n"+
              "This is the place where the greatest drow buy their\n"+
              "armour, knowing of the excellent quality and low \n"+
              "price. There is a huge furnace fire burning along the \n"+
              "wall. The air is blackened with soot and smoke. The\n"+
              "fire is heating various metals, which are being forged\n"+
              "into breastplates and shield handles. An assistant is \n"+
              "staying behind a big SIGN. Just read it to for more\n"+ 
              "information.\n";
    dest_dir= ({
              ETOWN+"tr5", "east",
              });
    items=({
    "drow","An evil old drow waiting to serve you",
          "sign","    =============================================\n"+
                 "    =       General  Merimack's  Armoury        =\n"+
                 "    =============================================\n"+
                 "    =                                           =\n"+
                 "    =  1.  Banded Chain             8000 coins  =\n"+
                 "    =  2.  Ringmail                4000 coins  =\n"+
                 "    =  3.  Mirror Shield            4000 coins  =\n"+
                 "    =  4.  Gauntlets                2000 coins  =\n"+
                 "    =  5.  General's Helmet          800 coins  =\n"+
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
                 "    =       General  Merimack's  Armoury        =\n"+
                 "    =============================================\n"+
                 "    =                                           =\n"+
                 "    =  1.  Banded Chain             8000 coins  =\n"+
                 "    =  2.  Ringmail                 4000 coins  =\n"+
                 "    =  3.  Mirror Shield            4000 coins  =\n"+
                 "    =  4.  Gauntlets                2000 coins  =\n"+
                 "    =  5.  General's Helmet          800 coins  =\n"+
                 "    =                                           =\n"+
                 "    =============================================\n");

     say(TPN+" reads the sign.\n");
   return 1;                                                 
  }

  buy(str) {
    object dummy,assi;
    int ac,value,weight,light;
    string short,long,alias,name,type;

    if (!str) {
      write("The drow looks questionally.\n");
    return 1;
    }
    else if (str=="chain" || str=="1") {
      if (w1 > 2) {
        write("The drow says: Sorry, none in stock.\n");
      return 1;
       }
      ac=4;
      value=4000;
      weight=5;
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
      if (w2 > 4) {
        write("The assistant says: Sorry, none in stock.\n");
       return 1;
      }
      ac=3;
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
      if (w3 >6) {
        write("The assistant says: Sorry, none in stock.\n");
       return 1;
      }
      ac=2;
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
    else if (str=="gauntlets" || str=="4") {
      if (w4 >8) {
        write("The drow says: Sorry, none in stock.\n");
      return 1;
      }
      ac=0;
      value=1000;
      weight=1;
      short= "Gauntlets";
      long=  "Typical armour to protect the hands of the.\n"+
             "wearer. These gloves feel strong yet light \n"+
             "enough to allow movement. \n\n";
      alias= "gloves";
      name=  "gauntelts";
      type= "gloves";

      w4++;
    }
    else if (str=="helmet" || str=="5") {
      if (w5 > 10) {
        write("The drow says: Sorry, we are ran out.\n");
       return 1;
      }
      ac=1;
      value=400;
      weight=3;
      short= "Helmet";
      long=  "These boots are a high quality armour.\n"+
             "Designed by: Sir warlord the great \n\n";
      alias= "helmet";
      name=  "helmet";
      type="helmet";
      w5++;
    }
    else {
      write("The drow says: What?? What you see is what we have\n");
      return 1;
    }
    if (TP->query_money() < (value*2)) {
       write("The drow shrugs angrily: Sorry, but that would\n"+
       "cost you "+(value*2)+" coins which you don't have fool!.\n");
     }
    else {
    dummy=CO("obj/armour");
    dummy->set_name(name);
    dummy->set_alias(alias);
    dummy->set_short(short);
    dummy->set_long(long);
    dummy->set_value(value);
    dummy->set_weight(weight);
    dummy->set_ac(ac);   
    dummy->set_type(type);
    write("The drow tosses you "+short+".\n"+
    "The dark elf grins: come back soon.\n");
    transfer(dummy,TP);
    TP->add_money(-2*value);
    return 1;
   }
  return 1;
 }
