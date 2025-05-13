#define TP this_player()
#define TPN TP->query_name()
#define TPM TP->query_money()

id(str) {
  return str=="bar";
  }
  
short() {
  return "The bar";
  }


object cider,apple,plum,brandy;
int value;
  
buy(arg) {

   if (!arg) 
      return;
      
   if ((arg=="cider" || arg=="apple cider")  && (TPM>8)) {
      value=8;
            
      if (TP->query_money()<value) {
          write("Michelle says: You don't have enough gold coins !\n");
          return 1;
        }
    
      cider=clone_object("obj/alco_drink");
      cider->set_name("cider");
      cider->set_alias("apple cider");
      cider->set_short("An apple cider");
      cider->set_long("A bottle of apple cider.\n");
      cider->set_drinking_mess(" h{fver en cider.\n");
      cider->set_value(4);
      cider->set_strength(2);
      cider->set_weight(1);
      if (transfer(cider,TP)) {
          write("Michelle says: You can't carry that much.\n");
      return 1;
      }
      move_object(cider,TP);  
      write("Michelle gives you an apple cider.\n");
      say(TPN+" buys a cider.\n");
      TP->add_money(-value);

      }
     
     else if ((arg=="brandy" || arg=="plum brandy")  && (TPM>80)) {
      value=80;
      
      if (TP->query_money()<value) {
          write("Michelle says: You don't have enough gold coins !\n");
          return 1;
        }
      brandy=clone_object("obj/alco_drink");
      brandy->set_name("brandy");
      brandy->set_alias("plum brandy");
      brandy->set_short("A plum brandy");
      brandy->set_long("A bottle of plum brandy.\n");
      brandy->set_drinking_mess("Burp.\n");
      brandy->set_value(40);
      brandy->set_strength(20);
      brandy->set_weight(1);
      if (transfer(brandy,TP)) {
          write("Michelle says: You can't carry that much.\n");
      return 1;
      }
      move_object(brandy,TP);    
      write("Michelle gives you a plum brandy.\n");
      say(TPN+" buys a plum brandy.\n");
      TP->add_money(-value);

      }
      
      else if ((arg=="apple") && (TPM>5)) {
      value=5;
      
      if (TP->query_money()<value) {
          write("Michelle says: You don't have enough gold coins !\n");
          return 1;
        }
      apple=clone_object("obj/food");
      apple->set_name("apple");
      apple->set_short("A red apple");
      apple->set_long("A sweet red apple.\n");
      apple->set_eater_mess(" eats a sweet red apple.\n");
      apple->set_eating_mess("Mmmm that apple tastes sweet.\n");
      apple->set_value(2);
      apple->set_strength(2);
      apple->set_weight(1);
      if (transfer(apple,TP)) {
          write("Michelle says: You can't carry that much.\n");
      return 1;
      }
      move_object(apple,TP);  
  
      write("Michelle gives you an apple.\n");
      say(TPN+" buys an apple.\n");
      TP->add_money(-value);

      
      }
      
      else if ((arg=="plum") && (TPM>50)) {
      value=50;
      
      if (TP->query_money()<value) {
          write("Michelle says: You don't have enough gold coins !\n");
          return 1;
        }
      plum=clone_object("obj/food");
      plum->set_name("plum");
      plum->set_short("A blue plum");
      plum->set_long("A sweet blue plum.\n");
      plum->set_eater_mess(" eats a sweet blue plum.\n");
      plum->set_eating_mess("Mmmm that plum tastes sweet.\n");
      plum->set_value(25);
      plum->set_strength(20);
      plum->set_weight(1);
      if (transfer(plum,TP)) {
          write("Michelle says: You can't carry that much.\n");
      return 1;
      }
      move_object(plum,TP);  
  
      write("Michelle gives you a plum.\n");
      say(TPN+" buys a plum.\n");
      TP->add_money(-value);

      }
      
      else {
      write("Michelle shrugs helplessly.\n");
      say("Michelle shrugs helplessly.\n");
      return 1;
      }
   return 1;
   }
                     
     read(arg) {
     
     if (arg!="sign") return;
     
     write(
           "+++++++++++++++++++++++++++++++++++++++++++++++\n"+
           "Cider          1 Bottle          8   gold coins\n"+
           "Brandy         1 Bottle          80  gold coins\n"+
           "Apple          1 Piece           5   gold coins\n"+
           "Plum           1 Piece           50  gold coins\n"+
           "+++++++++++++++++++++++++++++++++++++++++++++++\n\n");
           
    return 1;
    
    }
    
        
      
      
      
      
      
      
