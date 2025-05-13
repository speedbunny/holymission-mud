/*in progress - need to add items and monsters*/
#include "/players/redsexy/defs.h"

inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The servery of the Mos Eisley Cantina";
  long_desc="The food here smells delicious, and your belly rumbles from "+
            "the delightful aromas!  Whether it is just a quick snack or "+
            "a full meal you desire, it is certain that Manaki can cater for your every "+
            "culinary need. There is a menu here, perhaps you should read it?\n\n ";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/8","west",
           });

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There are so many creatures in here you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "menu","You can probably read it",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
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

  if (str=="menu" || str=="sign") {
     write(
      "*******************************************************\n"+
      "                   THE MOS EISLEY CANTINA              \n"+
      "*******************************************************\n"+
      "Meals now being served:\n\n"+
      "1   Sarlacc Steaklets                  1000 credits \n"+
      "2   Juicy Juri Kebab                    900 credits \n"+
      "3   Whipid Style Wholehog               800 credits \n"+
      "4   Snips Stir Fry                      700 credits \n"+
      "5   Darkside Fries                      600 credits \n"+
      "6   Huttese Cow-in-a-Bun                500 credits \n"+
      "7   Breaded Rancor      	        400 credits \n"+
      "8   Wildveg		                300 credits \n"+
      "9   Seaweed	                        200 credits \n\n"+
      "Please direct any queries about these meals to the      \n"
      "                community board.                        \n"

      );
  return 1;
  }
}


order(str) {

  string name, short_desc,art, mess;
  int strength, heal, has;
  object dummy, ob;

  ob=present("red-credits",TP);
  if(!ob) 
    {write("Malaki says: We only take credits in Mos Eisley.\n");
    return 1;}
  has=ob->query_credits(); 
  if(200>has)
    {write("Malaki says: The cheapest food I sell is 200 credits.\n");
        return 1;
    }

  if (str == "steaklets" || str == "sarlacc" || str == "1") {
  if (1000>has){
      write("Malaki says: The Sarlacc Steaklets cost 1000 credits.\n");
      return 1;
  }
      mess = "Malaki cooks up some tender Sarlacc Steaklets, sizzling \n" +
             "as he serves them.  You savour every mouthful.";
      heal = 400;
      ob->add_credits(-1000);
      strength = 25;
      art ="food";
  }
  else
  if (str == "juri" || str == "kebab" || str == "2") {
  if (900>has){
      write("Malaki says: The Juri Kebab costs 900 credits.\n");
      return 1;
  }
      mess = "The juri kebab is alternate pieces of white and red writeat on a skewer. "+
             "You eagerly scoff this desert delicacy.";
      heal= 350;
      ob->add_credits(-900);
      strength = 20;
      art ="food";
  }
  else
  if (str == "whipid" || str == "wholehog" || str == "3") {
  if (800>has){
      write("Malaki says: The Whipid Wholehog costs 800 credits.\n");
      return 1;
  }
      mess = "This dish turns out to be a crispy skinned whole piglet! Yummy!";
      heal= 300;
      ob->add_credits(-800);      
      strength = 13;
      art ="food";
  }
  else
  if (str == "snips" || str == "shotter" || str=="4") {
  if (700>has){
      write("Malaki says: A Snips Stirfry costs 700 credits.\n");
      return 1;
  }
      mess = "Those Snips sure taste great in Malaki's special stirfry sauce.";
      heal= 250;
      ob->add_credits(-700);
      strength = 10;
      art = "food";
  }
  else
  if (str == "darkside" || str == "fries" || str=="5") {
  if (600>has){
      write("Malaki says: The Darkside Fries costs 600 credits.\n");
      return 1;
  }
      mess = "These fries come smothered in a dark sauce, and you eat the plateful greedily.";
      heal = 200;
      ob->add_credits(-600);
      strength = 8;
      art = "food";
  }
  else
  if (str == "huttese" || str== "cow-in-a-bun" || str == "6") {
  if (500>has){
      write("Malaki says: The Huttese Cow-in-a-bun costs 500 credits.\n");
      return 1;
  }
      mess = "Yummy! The young cow in this bun has served its purpose in the world!";
      heal = 150;
      ob->add_credits(-500);
      strength = 13;
      art = "food";
  }
  else if (str == "rancor" || str == "breaded" || str == "7") {
  if (400>has){
      write("Malaki says: The Breaded Rancor costs 400 credits.\n");
      return 1;
  }
      mess = "These little chunks of breaded rancor make your tastebuds cry out in delight.\n";
      heal = 100;
      ob->add_credits(-400);
      strength = 7;
      art = "food";
  }
  else
  if (str == "wildveg" || str == "8") {
  if (300>has){
      write("Malaki says: Wildveg costs 300 credits.\n");
      return 1;
  }
      mess = "The wildveg are fresh and juicy, making you feel better.\n";
      heal = 50;
      ob->add_credits(-300);
      strength = 3;
      art = "food";
  }
  else
  if (str == "seaweed" || str=="9"){
      mess = "Malaki says: Seaweed is food for the brain.\n"+
             "You feel ready for anything now!\n";
      heal = 200;
      ob->add_credits(-200);
      strength = 25;
      art = "special";
  }
  else
  {
  write("Malaki looks puzzled.\n" +
        "Malaki says: Leave me the receipe on the board and I'll see if I can cook it up.\n");
  return 1;
  }

 if (art=="food") {
      if (!call_other(TP,"eat_food",strength)){
         write("Malaki says: Yer fat enough already pal\n");
         say(TPQN+" shouldn't really eat anymore...\n");
      return 1;
      }
  }
 if (art=="soft") {
      if (!call_other(TP,"drink_soft",strength)){
         write("Malaki says: Get outta here ya pansy!\n");
      return 1;
      }
  }

  write("You pay for your meal.\n");


  if(art=="special") TP->restore_spell_points(heal);
  else 
    TP->heal_self(heal);
    write(mess + "\n");
    
  
  return 1;
}
