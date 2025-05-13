#define TP this_player()
#define TPN TP->query_name()
#define TO this_object()

inherit "room/room";
    int w1,w2,w3,w4,w5;

reset(arg) {
  w1=0;w2=0;w3=0;w4=0;w5=0;
  if (arg) return;
    set_light(1);
    short_desc = "In Warlord's Weaponary";
    long_desc="You have entered the weaponary of Sir Warlord. This \n"+
              "is the shop where the mightiest fighters buy their\n"+
              "weapons, knowing of the excellent quality and low \n"+
              "price. An assistent is staying behind a big SIGN, \n"+
              "Just look at it to get more information.\n";
    dest_dir= ({
"players/warlord/rooms/room","east",
              });
    items=({
          "sign","    #############################################\n"+
                 "    #  SIR    WARLORDS               WEAPONARY  #\n"+
                 "    #############################################\n"+
                 "    #                                           #\n"+
                 "    #  1.) A KATANA                10000 coins  #\n"+
                 "    #  2.) A BLACK SCIMITAR         6000 coins  #\n"+
                 "    #  3.) AN ELVEN LONGSWORD       4000 coins  #\n"+
                 "    #  4.) A HEADSMASHER            2000 coins  #\n"+
                 "    #  5.) A BLOODSTRAINED DAGGER    800 coins  #\n"+
                 "    #                                           #\n"+
                 "    #############################################\n" });
                                                    
  }

init() {
  add_action("buy","buy");
  add_action("read","read");
  ::init();
  }
  read(str) {
    if (str!="sign") return;
    write(
                 "    #############################################\n"+
                 "    #  SIR    WARLORDS               WEAPONARY  #\n"+
                 "    #############################################\n"+
                 "    #                                           #\n"+
                 "    #  1.) A KATANA                10000 coins  #\n"+
                 "    #  2.) A BLACK SCIMITAR         6000 coins  #\n"+
                 "    #  3.) AN ELVEN LONGSWORD       4000 coins  #\n"+
                 "    #  4.) A HEADSMASHER            2000 coins  #\n"+
                 "    #  5.) A BLOODSTRAINED DAGGER    800 coins  #\n"+
                 "    #                                           #\n"+
                 "    #############################################\n" );

     say(TPN+" reads the sign.\n");
   return 1;                                                 
  }

  buy(str) {
    object dummy,assi;
    int wc,value,weight;
    string short,long,alias,name,type;

    if (!str) {
      write("The assistant looks questionally.\n");
    return 1;
    }
    else if (str=="katana" || str=="1") {
      if (w1 > 2) {
        write("The assistant says: Sorry,but we are sold out of that.\n");
      return 1;
       }
      wc=18;
      value=5000;
      weight=2;
      short="A katana";
      long= "This katana is a top quality weapon.\n"+
            "Designed by: Sir Warlord the great \n\n";
      alias="sword";
      name= "katana";
      w1++;
    }
    else if (str=="scimitar" || str=="2") {
      if (w2 > 4) {
        write("The assistant says: Sorry,but we are sold out of that.\n");
       return 1;
      }
      wc=16;
      value=3000;
      weight=2;
      short= "A black scimitar";
      long=  "This scimitar is a top quality weapon.\n"+
             "Designed by: Sir Warlord the great \n\n";
      alias= "sword";
      name=  "scimitar";
      w2++;
    }
    else if (str=="longsword" || str=="3") {
      if (w3 >6) {
        write("The assistant says: Sorry, but we are sold out of that.\n");
       return 1;
      }
      wc=15;
      value=2000;
      weight=3;
      short= "An elfen longsword";
      long=  "This longsword is a top quality weapon.\n"+
             "Designed by: Sir Warlord the great \n\n";
      alias= "sword";
      name=  "longsword";
      w3++;
    }
    else if (str=="headsmasher" || str=="4") {
      if (w4 >8) {
        write("The assistant says: Sorry,but we are sold out of that.\n");
      return 1;
      }
      wc=13;
      value=500;
      weight=4;
      short= "A headsmasher";
      long=  "This headsmasher is a top quality weapon.\n"+
             "Designed by: Sir Warlord the great \n\n";
      alias= "smasher";
      name=  "headsmasher";
      w4++;
    }
    else if (str=="dagger" || str=="5") {
      if (w5 > 10) {
        write("The assistant says: Sorry,but we are sold out of that.\n");
       return 1;
      }
      wc=12;
      value=400;
      weight=1;
      short= "A bloodstrained dagger";
      long=  "This dagger is a high quality weapon.\n"+
             "Designed by: Sir warlord the great \n\n";
      alias= "bloodstrained dagger";
      name=  "dagger";
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
    dummy=clone_object("obj/weapon");
    dummy->set_name(name);
    dummy->set_alias(alias);
    dummy->set_short(short);
    dummy->set_long(long);
    dummy->set_value(value);
    dummy->set_weight(weight);
    dummy->set_class(wc);   
    write("The assistant gives you "+short+".\n"+
    "The assistant smiles: Pleasure any time.\n");
    transfer(dummy,this_player());
    this_player()->add_money(-2*value);
    return 1;
   }
  return 1;
 }

    
    
