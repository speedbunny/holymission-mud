inherit "room/room";
#include "/players/redsexy/defs.h"

reset(arg) {
  set_light(1);
  short_desc="The main bar of the Mos Eisley Cantina";
  long_desc="At last you have found the place to get served around here!  The selection "+
            "of cocktails and beverages from around the realms is immense, never before "+
            "have you had such a choice - but then again, Wuntar is renowned for his "+
            "drinks being the best. Perhaps you should read the menu?\n\n ";

  dest_dir=({"/players/redsexy/jedi/areas/cantina/3","north",
             "/players/redsexy/jedi/areas/cantina/2","northwest",
             "/players/redsexy/jedi/areas/cantina/4","northeast",
             "/players/redsexy/jedi/areas/cantina/7","west",
             "/players/redsexy/jedi/areas/cantina/9","east",
           });

  items=({"bar","This is the Mos Eisley Cantina, and it is packed",
          "creatures","There are so many creatures in here you can barely move",
          "races","Rodians, Quarrens, Wookies, Twi'leks, Whipids - just to name a few!",
          "music","It sounds like a Jizz-wailer band, but you can't place who they are",
          "desert","Forget about it!  RELAX....",
          "menu", "A wooden sign hangs on the wall with a list of cocktails",
          "drinks", "Many of the creatures are drinking colorful drinks",
          "beverages", "Many of the creatures are drinking colorful drinks",
          "cocktails", "Wuntar is the best cocktail maker ever",
          "wuntar", "Wuntar is a surly man, who always looks busy and has a permanent " +
                    "frown on his face.  Such is the tedium of being the best cocktail " +
                    "mixer in Mos Eisley"
         });

  ::reset(arg);
 
}
init() {

    add_action("order","order"); 
    add_action("order","buy"); 
    add_action("read","read"); 
    ::init();
}

read(str) {

  if (str=="menu" || str=="sign") {
     write(
      "*******************************************************\n"+
      "                   THE MOS EISLEY CANTINA              \n"+
      "*******************************************************\n"+
      "Cocktails now being served:\n\n"+
      "1   Sarlacc Spice                          1000 credits \n"+
      "2   Juri Juice                              900 credits \n"+
      "3   Whipid Baldy                            800 credits \n"+
      "4   Snips Shotter                           700 credits \n"+
      "5   Dark Dreamer                            600 credits \n"+
      "6   Huttese Sparkler                        500 credits \n"+
      "7   Rancor's Revenge                        400 credits \n"+
      "8   Droopy McCool's                         300 credits \n"+
      "9   Jedi Generation                         200 credits \n\n"+
      "Please direct any queries about these concoctions to the\n"
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
    {write("Wuntar says: We only take credits in Mos Eisley.\n");
    return 1;}
  has=ob->query_credits(); 
  if(200>has)
    {write("Wuntar says: The cheapest drink I sell is 200 credits.\n");
        return 1;
    }

  if (str == "spice" || str == "sarlacc" || str == "1") {
  if (1000>has){
      write("Wuntar says: The Sarlacc Spice costs 1000 credits.\n");
      return 1;
  }
      mess = "Wuntar gives you a Sarlacc Spice, the delicacy of the desert...\n" +
             "It goes down so smoothly, you declare that he is a genius";
      heal = 400;
      ob->add_credits(-1000);
      strength = 25;
      art ="alko";
  }
  else
  if (str == "juri" || str == "juice" || str == "2") {
  if (900>has){
      write("Wuntar says: The Juri Juice costs 900 credits.\n");
      return 1;
  }
      mess = "The juri juice is the bar speciality, Wuntar mixes it "+
             "expertly, and you knock it down in one.";
      heal= 350;
      ob->add_credits(-900);
      strength = 25;
      art ="alko";
  }
  else
  if (str == "whipid" || str == "baldy" || str == "3") {
  if (800>has){
      write("Wuntar says: The Whipid Baldy costs 800 credits.\n");
      return 1;
  }
      mess = "You knock back the red and green concoction and feel kinda dizzy.";
      heal= 300;
      ob->add_credits(-800);      
      strength = 25;
      art ="alko";
  }
  else
  if (str == "snips" || str == "shotter" || str=="4") {
  if (700>has){
      write("Wuntar says: A Snips Shotter costs 700 credits.\n");
      return 1;
  }
      mess = "A single shot of the Snip's favourite liquor puts you back on form.";
      heal= 250;
      ob->add_credits(-700);
      strength = 25;
      art = "alko";
  }
  else
  if (str == "dark" || str == "dreamer" || str=="5") {
  if (600>has){
      write("Wuntar says: A Dark Dreamer costs 600 credits.\n");
      return 1;
  }
      mess = "You drink a creamy Dark Dreamer, and feel kinda mellow for a while..";
      heal = 200;
      ob->add_credits(-600);
      strength = 25;
      art = "alko";
  }
  else
  if (str == "huttese" || str== "sparkler" || str == "6") {
  if (500>has){
      write("Wuntar says: The Huttese Sparkler costs 500 credits.\n");
      return 1;
  }
      mess = "The bubbles explode on your tounge as you drink the sparkler.";
      heal = 150;
      ob->add_credits(-500);
      strength = 25;
      art = "alko";
  }
  else if (str == "rancors" || str == "revenge" || str == "7") {
  if (400>has){
      write("Wuntar says: The Rancor's Revenge costs 400 credits.\n");
      return 1;
  }
      mess = "Sheesh! Your stomach cries out in pain, and your senses call out for more..\n";
      heal = 100;
      ob->add_credits(-400);
      strength = 25;
      art = "alko";
  }
  else
  if (str == "droopy" || str == "mccools" || str == "8") {
  if (300>has){
      write("Wuntar says: A Droopy McCool's costs 300 credits.\n");
      return 1;
  }
      mess = "The band don't only have good taste in music, this drink is FAB!\n";
      heal = 50;
      ob->add_credits(-300);
      strength = 25;
      art = "alko";
  }
  else
  if (str == "jedi" || str == "generation" || str=="9"){
      mess = "Wuntar says: The Jedi Generation is the only non alcoholic drink I serve.\n"+
             "You feel ready for anything now!\n";
      heal = 200;
      ob->add_credits(-200);
      strength = 25;
      art = "special";
  }
  else
  {
  write("Wuntar looks puzzled.\n" +
        "Wuntar says: Leave me the receipe on the board and I'll see if I can mix it.\n");
  return 1;
  }

  if (art=="alko" || art=="boost") {
  if (!call_other(TP, "drink_alcohol", strength)) {
      write("Wuntar says: Get some food, sober up, and come back quickly, OK?\n");
     return 1;
     }
  }
  else
  if (art=="soft") {
      if (!call_other(TP,"drink_soft",strength)){
         write("Wuntar says: Get outta here ya pansy!\n");
      return 1;
      }
  }

  write("You pay for your cocktail.\n");


  if(art=="special") TP->restore_spell_points(heal);
  else 
    TP->heal_self(heal);
    write(mess + "\n");
    
  if(strength==50) say("Wuntar whispers to you"+ TP->query_name() +" is totally slaughtered." +
      "start tickling them for a laugh...\n");
  return 1;
}

   
