/* viking luckar knows how to gamble */
inherit "obj/monster";
object arm;
int i;

void reset(int arg) {
   ::reset(arg);
      if(!present("mead")) {
         for(i=0;i<5;i++) {
            arm=clone_object("/players/uglymouth/vikings/items/mead");
            transfer(arm,this_object());
            }
         }

   if(!arg) {
      set_name("viking luckar");
      set_alt_name("luckar");
      set_alias("viking");
      set_short("Viking Luckar");
      set_long("Viking Luckar is a lucky man. Yoy can see it in his eyes. \n"
             + "Although he looks like he has had a good feast, he is still \n"
             + "quite sober. But not so sober he could handle loaded dice \n"
             + "without you noticing it. And his dark face looks quite honest. \n");
      set_level(6);
      set_al(-15);
      set_race("human");
      set_gender(1);

      transfer(clone_object("/players/uglymouth/vikings/items/vikaxe"),this_object());
      transfer(clone_object("/players/uglymouth/vikings/items/viktunic"),this_object());
      command("wield axe");
      command("wear tunic");

      load_chat(20,
               ({"Viking Luckar says: Is there someone who wants to gamble? \n",
                 "Viking Luckar says: I only take weapons and armour as worthy bets. \n",
                  "Viking Luckar says: Put your bet in the tree stump. \n",
                  "Viking Luckar says: Triple Ace is my favorite game. \n",
                  "Viking Luckar says: I bet a mug of our devine mead that you can't beat me. \n", }));
      }
   }

