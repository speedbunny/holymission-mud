

  /*fixed by haplo on 3-22-95*/
#define TP  this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()
#define TPM TP->query_money()

inherit "room/room";
#include "../island.h"
    
    object cider,apple,plum,brandy,keg;
    object cat;
    int value;

 
void reset(int arg) 
{
   
    if (!cat)
   {
       cat = clone_object("/players/whisky/hole/monster/cat");
       move_object(cat,this_object());
     }
     ::reset ( arg );
     
     if ( !arg ) {
     
     
     set_light( 1 );
     short_desc = "In a cavern";
     long_desc = BS(
         "You are inside of a warm cave in the volcano. It's very hot "+
         "but friendly here. The walls of black stone have some "+
         "torches attached to the walls. You see many little "+
         "footsteps leading to the east. There is a BOTTLE and a SIGN "+
         "fixed to the wall and you see a wooden counter to "+
         "the north.");
              
           
      items = ({
            "cave","The cave leads back to the east",
            "stones","Big black stones lying on the ground",
            "stone","There are a lot of stones lying around",
            "torches","They are lighted and fixed to the walls",
            "torch","There are lots of torches fixed to the walls",
            "walls","The walls are dark and made of black stones",
            "ground","The ground is full of dark stones",
            "footsteps","You see a lot of tiny gnomish footsteps, leading east",
            "volcano","Well you are just inside the volcano",
            "bottle","It's looks like an empty whiskey-bottle",
            "sign","A big iron sign, maybe you should read it",
            "desc","A big oak-wooden desc"
               });
            
      dest_dir = ({
            PATH+"gnome15","east"          
               });
               
          }
        }

     init() {
       add_action("do_buy","buy");
       add_action("do_read","read");
       ::init();
     }
  
  do_buy(arg) {

   if (!arg) 
      return;
      
   if ((arg=="cider" || arg=="apple cider") ) {
      value=8;
            
      if (TP->query_money()<value) {
          write("Carola says: YouDon'tHaveEnoughGoldCoins !\n");
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
          write("Carola says: YouCan'tCarryThatMuch.\n");
          return 1;
      }
      write("Carola gives you an apple cider.\n");
      say(TPN+" buys a cider.\n");
      TP->add_money(-value);

      }
     
     else if ((arg=="brandy" || arg=="plum brandy") ) {
      value=80;
      
      if (TP->query_money()<value) {
          write("Carola says: YouDon'tHaveEnoughGoldCoins !\n");
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
         write("Carola says: YouCan'tCarryThatMuch.\n");
         return 1;
      }
      write("Carola gives you a plum brandy.\n");
      say(TPN+" buys a plum brandy.\n");
      TP->add_money(-value);

      }
      
      else if ((arg=="apple") ) {
      value=5;
      
      if (TP->query_money()<value) {
          write("Carola says: YouDon'tHaveEnoughGoldCoins !\n");
          return 1;
        }
      apple=clone_object("obj/food");
      apple->set_name("apple");
      apple->set_short("A red apple");
      apple->set_long("A sweet red apple.\n");
      apple->set_eating_mess(" eats a sweet red apple.\n");
      apple->set_eater_mess("Mmmm that apple tastes sweet.\n");
      apple->set_value(2);
      apple->set_strength(2);
      apple->set_weight(1);
      if (transfer(apple,TP)) {
          write("Carola says: YouCan'tCarryThatMuch.\n");
      return 1;
      }
  
      write("Carola gives you an apple.\n");
      say(TPN+" buys an apple.\n");
      TP->add_money(-value);

      
      }
      
      else if ((arg=="plum") ) {
      value=50;
      
      if (TP->query_money()<value) {
          write("Carola says: YouDon'tHaveEnoughGoldCoins !\n");
         
          return 1;
        }
      plum=clone_object("obj/food");
      plum->set_name("plum");
      plum->set_short("A blue plum");
      plum->set_long("A sweet blue plum.\n");
      plum->set_eating_mess(" eats a sweet blue plum.\n");
      plum->set_eater_mess("Mmmm that plum tastes sweet.\n");
      plum->set_value(25);
      plum->set_strength(20);
      plum->set_weight(1);
      if (transfer(plum,TP)) {
          write("Carola says: YouCan'tCarryThatMuch.\n");
          }
         }
         
      else if ((arg=="keg" || arg=="a keg") ) {
      
      if (TP->query_money()<400) {
          write("Carola says: YouDon'tHaveEnoughGoldCoins !\n");
          
          return 1;
        }
     
       keg=clone_object("/players/whisky/magic/keg");
       keg->set_name("keg");
       keg->set_alias("enzian");
       keg->set_alt_name("keg of enzian");
       keg->set_short("A keg of enzian");
       keg->set_long("A big keg of enzian");  
       keg->set_value(200);
       keg->set_taps(20);
       keg->set_weight(4);
       keg->set_strength(8);
       keg->set_consumer_mess("You tap from your keg of enzian !");
       keg->set_cosuming_mess(" taps from a keg of enzian.");
  
      if (transfer(keg,this_player())) {
         write("Carola says: YouCan'tCarryThatMuch.\n");
         
        return 1;
       }      
     
      write("Carola gives you a keg.\n");
      say(TPN+" buys a keg.\n");
      TP->add_money(-2000);
       return 1;
      }
      
      else {
      write("Carola shrugs helplessly.\n");
      say("Carola shrugs helplessly.\n");
      return 1;
      }
   return 1;
   }
                     
     do_read(arg) {
     
     if (arg!="sign") return;
     
     write(
           "###############################################\n\n"+
           "Cider          1 Bottle          8   gold coins\n"+
           "Brandy         1 Bottle          80  gold coins\n"+
           "Apple          1 Piece           5   gold coins\n"+
           "Plum           1 Piece           50  gold coins\n"+
           "A keg (enzian) 1 Piece          400  gold coins\n\n"+
           "###############################################\n\n");
           
    return 1;
    
    }
    
        
      
      
      
      
      
      
