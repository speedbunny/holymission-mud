#define TP this_player()
#define TPN TP->query_name()
#define TO this_object()

inherit "room/room";
    int w1,w2,w3,w4,w5;

reset(arg) {
  w1=0;w2=0;w3=0;w4=0;w5=0;
  if (arg) return;
    set_light(1);
    short_desc = "In Warlord's Armoury";
    long_desc="You have entered the armoury of Sir Warlord. This \n"+
              "is the shop where the mightiest fighters buy their\n"+
              "armour, knowing of the excellent quality and low \n"+
              "price. An assistant is staying behind a big SIGN. \n"+
              "Just look at it to get more information.\n";
    dest_dir= ({
"players/warlord/rooms/room","south",
              });
    items=({
    "assistant","An eager old man waiting to serve you",
          "sign","    *********************************************\n"+
                 "    *  SIR    WARLORDS               Armoury    *\n"+
                 "    *********************************************\n"+
                 "    *                                           *\n"+
                 "    *  1.) Fightermail              8000 coins  *\n"+
                 "    *  2.) Fighter chain            4000 coins  *\n"+
                 "    *  3.) Silver Shield            4000 coins  *\n"+
                 "    *  4.) Gloves of fighters       2000 coins  *\n"+
                 "    *  5.) Fighter Boots             800 coins  *\n"+
                 "    *                                           *\n"+
                 "    *********************************************\n" });
                                                    
  }

init() {
  add_action("buy","buy");
  add_action("read","read");
  ::init();
  }
  read(str) {
    if (str!="sign") return;
    write(
                 "    *********************************************\n"+
                 "    *  Sir    Warlord's              Armoury    *\n"+
                 "    *********************************************\n"+
                 "    *                                           *\n"+
                 "    *  1.) Fightermail              8000 coins  *\n"+
                 "    *  2.) Fighter Chain            4000 coins  *\n"+
                 "    *  3.) Silver Shield            4000 coins  *\n"+
                 "    *  4.) Gloves of fighters       2000 coins  *\n"+
                 "    *  5.) Fighters boots            800 coins  *\n"+
                 "    *                                           *\n"+
                 "    *********************************************\n");

     say(TPN+" reads the sign.\n");
   return 1;                                                 
  }

  buy(str) {
    object dummy,assi;
    int ac,value,weight,light;
    string short,long,alias,name,type;

    if (!str) {
      write("The assistant looks questionally.\n");
    return 1;
    }
    else if (str=="fightermail" || str=="1") {
      if (w1 > 2) {
        write("The assistant says: Sorry,but we are sold out of that.\n");
      return 1;
       }
      ac=3;
      value=4000;
      weight=5;
      short="fightermail";
      long= "This fightermail is ideal for those brave at heart.\n"+
            "Designed by: Sir Warlord the great \n\n";
      alias="mail";
      name= "fightermail";
      type="armour";
      w1++;
    }
    else if (str=="chain" || str=="2") {
      if (w2 > 4) {
        write("The assistant says: Sorry,but we are sold out of that.\n");
       return 1;
      }
      ac=2;
      value=2000;
      weight=4;
      short= "Fighter chain";
      long=  "This chain is a top quality armour.\n"+
             "Designed by: Sir Warlord the great \n\n";
      alias= "chain";
      name=  "chain";
      type="armour";
      w2++;
    }
    else if (str=="shield" || str=="3") {
      if (w3 >6) {
        write("The assistant says: Sorry, but we are sold out of that.\n");
       return 1;
      }
      ac=1;
      value=2000;
      weight=2;
      short="Silver Shield";
      long=  "This shield is a top quality armour.\n"+
             "Designed by: Sir Warlord the great \n\n";
      alias= "shield";
      name=  "shield";
      type="shield";
      w3++;
    }
    else if (str=="gloves" || str=="4") {
      if (w4 >8) {
        write("The assistant says: Sorry,but we are sold out of that.\n");
      return 1;
      }
      ac=0;
      value=1000;
      weight=1;
      short= "Gloves of Fighters";
      long=  "These gloves are a top quality armour.\n"+
             "Designed by: Sir Warlord the great \n\n";
      alias= "gloves";
      name=  "gloves";
      type= "gloves";

      w4++;
    }
    else if (str=="boots" || str=="5") {
      if (w5 > 10) {
        write("The assistant says: Sorry,but we are sold out of that.\n");
       return 1;
      }
      ac=1;
      value=400;
      weight=3;
      short= "Fighters boots";
      long=  "These boots are a high quality armour.\n"+
             "Designed by: Sir warlord the great \n\n";
      alias= "boots";
      name=  "boots";
      type="boot";
      w5++;
    }
    /* Matt 2-13-94: If string doesn't match, don't proceed */
    else {
      write("The assistant says: We don't have that item.\n");
      return 1;
    }
    if (TP->query_money() < (value*2)) {
       write("The assistant shrugs helplessly: Sorry, but that would\n"+
       "cost you "+(value*2)+" coins which you don't have.\n");
     }
    else {
    dummy=clone_object("obj/armour");
    dummy->set_name(name);
    dummy->set_alias(alias);
    dummy->set_short(short);
    dummy->set_long(long);
    dummy->set_value(value);
    dummy->set_weight(weight);
    dummy->set_ac(ac);   
    dummy->set_type(type);
    write("The assistant gives you "+short+".\n"+
    "The assistant smiles: Pleasure any time.\n");
    transfer(dummy,this_player());
    this_player()->add_money(-2*value);
    return 1;
   }
  return 1;
 }

    
    
