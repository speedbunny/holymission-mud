inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc= "Fragrant Aromas";
  long_desc =
    "You are in the wonderful smelling Fragrant Aromas.  "+
    "This shop is the ultimate perfumery for those with a "+
    "delight for perfumes or colognes.  There are shelves "+
    "lined with small glass bottles.  A desk with a cash box "+
    "on it is in the northeast corner.  Soft, relaxing chimes "+
    "are blowing in the western window.  There is a small,"+
    " wooden sign that hangs above the desk.\n";
  smell = "You smell sandelwood, lavender, and rosehips.";
  items = ({
      "desk", "A large wooden with a cash box on top",
      "window", "A stone window with chimes hanging in it",
      "chimes", "Brass wind chimes shaped like moons",
      "moons", "Small moon shapes",
      "box", "A small cash box made from glass",
      "wall", "Shelves that line the walls",
      "bottles", "Small glass bottles in several colors",
      "shelves", "Wooden shelves filled with glass bottles",
      "sign", "A large wooden sign, maybe you should read it",
  });
  dest_dir = ({
      TOWER+"room/hall2", "east",
  });
  property = ({
      "no_fight" 
  });
  clone_list=({
      1, 1, "wynn", TOWER+"npc/wynn", 0,
  });
  ::reset();
}

init() { 

  ::init();
  AA("order", "order"); 
  AA("order", "buy"); 
  AA("read", "read"); 
}

int read(string str) {

  if(str == "sign" || str == "symbols" || str == "strange sign") {
      ME("*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
      ME("+                Fragrant Aromas                  +\n");
      ME("*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
      ME("+  For Ladies            *  For Men               +\n");
      ME("*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
      ME("+  Romantic Rose         *  Night Waters          +\n");
      ME("*  Tender Moon           +  Cool Fires            *\n");
      ME("+  Fairy's Dust          *  Desert Sands          +\n");
      ME("*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n");
      ME("+     All fragrances cost 100 coins per spray     +\n");
      ME("*               Type: buy <scent>                 *\n");
      ME("+               100% Natural Herbs                +\n");
      ME("*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n\n");
   return 1;
  }
}

int order(string str){

  string name;
  int value;

  value = 100;

  if(!str){
      NF("What scent did you wish?\n");
   return 0; 
  }

  if(call_other(TP, "query_money", 0) < value){
      NF("That would cost you "+value+" which you don't have.\n");
   return 0;     
  }

  if(str == "romantic" || str == "rose" || str == "romantic rose") {
      if (TPSEX== 1) { 
         NF("This scent is not for you.\n");
       return 0; 
      }  
      ME("Wynn gives you a quick spray of Romantic Rose perfume.\n");
      say(call_other(TP, "query_name", 0)+" gets a quick spray of "+
          "Romantic Rose perfume.\n");
      call_other(TP, "add_money", - value);
      TP->set_smell("She smells like a wonderful rose garden.");
   return 1;
  }

  else if (str == "tender" || str == "moon" || str == "tender moon") {
      if(TPSEX== 1){
         NF("This scent is not for you.\n");  
       return 0; 
      }
      ME("Wynn gives you a quick spray of Tender Moon perfume.\n");
      say(call_other(TP, "query_name", 0)+" gets a quick spray "+
                     "of Tender Moon perfume.\n");
      call_other(TP, "add_money", - value);
      TP->set_smell("She smells like cinnamon, cloves, and nutmeg.");
   return 1;
  }

  else if (str == "fairy's" || str == "dust" || str == "fairy's dust") {
      if(TPSEX== 1){
        NF("This scent is not for you.\n");
       return 0; 
      }
      ME("Wynn gives you a quick spray of Fairy's Dust perfume.\n");
      say(call_other(TP, "query_name",0)+" gets a spray of "+
                     "Fairy's Dust perfume.\n");
      call_other(TP, "add_money", - value);
      TP->set_smell("She smells like eucalyptus, primrose, and lavender.");
   return 1;
  }
 
  else if (str == "night" || str == "waters" || str == "night waters") {
      if(TPSEX== 2){
        NF("This scent is not for you.\n");
       return 0; 
      }
      ME("Wynn gives you a quick spray of Night Waters cologne.\n");
      say(call_other(TP, "query_name", 0)+" gets a quick spray of "+
                     "Night Waters cologne.\n");
      call_other(TP, "add_money", - value);
      TP->set_smell("He smells like mint, yarrow, and sage.");
   return 1;
  }

  else if (str == "cool" || str == "fires" || str == "cool fires") {
      if(TPSEX== 2){
        NF("This scent is not for you.\n");
       return 0; 
      }
      ME("Wynn gives you a quick spray of Cool Fires cologne.\n");
      say(call_other(TP, "query_name", 0)+" gets a quick spray of"+
                     " Cool Fires cologne.\n");
      call_other(TP, "add_money", - value);
      TP->set_smell("He smells like orris root, cloves, and sage.");
   return 1;
  } 

  else if (str == "desert" || str == "sands" || str == "desert sands") {
      if(TPSEX== 2){
         NF("This scent is not for you.\n");
       return 0;  
      }
      ME("Wynn gives you a quick spray of Desert Sands colonge.\n");
      say(call_other(TP, "query_name", 0)+" gets a quick spray of "+
                    "Desert Sands cologne.\n");
      call_other(TP, "add_money", - value);
      TP->set_smell("He smells like cinnamon, nutmeg, and vanilla");
   return 1; 
  }
  else
  {
  NF("Wynn does not seem to have that scent.\n");
  NF("Maybe if you ask Saffrin, she will get it for you.\n");
   return 0;
  }
}
