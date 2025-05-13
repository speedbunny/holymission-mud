/* to invoke the aid of the viking gods */
inherit "obj/treasure";

reset(arg) {
   ::reset(arg);

   if(!arg) {
      set_name("ravenhelp");
      set_short(0);
      set_weight(0);
      }
   }

void init() {
   ::init();
   add_action("call_raven","call");
   }

int call_raven(string str) {
string date,words1,words2,words3,*sailcmds;
int day;
object vik,mead;
   if(str!="raven" && str!="the raven") return 0;
   set_short("Odin's raven Hugin and Munin");
   set_long("A pitch black raven is sitting on each shoulder. \n"
      + "They seem to be intelligent. \n");
   write("With loud wing flapping two pitch black raven fly down and land on your shoulders. \n");
   say("With loud wing flapping two pitch black raven fly down and land on " + this_player()->query_name() + "'s shoulders. \n",this_player());

   if(present("high lord hagar",environment(this_player()))) {
      if(!(this_player()->query_quests("viking"))) {
         write("Hugin whispers into your left ear: Give the village medallion to Hagar as a \n"
             + "token of your conquest. \n"
             + "Munin whispers into your right ear: That will bring you into his favour and \n"
             + "then your quest will be completed. \n");
         write("The raven scream once and disappear in the sky. \n");
         say("The raven whisper something into " + this_player()->query_possessive() + " ears. \n"
           + "They scream once and disappear in the sky. \n",this_player());
         destruct(this_object());
         return 1;
         }
      write("Hugin whispers into your left ear: Ready to go back home? \n"
          + "Munin whispers into your right ear: We will take you there. Hold on. \n"
          + "The raven each take you at a shoulder and lift you up high into the air. \n"
          + "After a while they descend and put you back on the ground. \n");
      this_player()->move_player("into the air#players/uglymouth/vikings/rock");
      write("The raven scream once and disappear in the sky. \n");
      say("Two raven scream once and fly away from " + this_player()->query_short_name() + "'s shoulders. \n",this_player());
      destruct(this_object());
      return 1;
      }
   if(present("viking ruddar",environment(this_player()))) {
      write("Hugin whispers into your left ear: We'll give you an easy trip to the \n"
          + "homelands of the Vikings. \n"
          + "Munin whispers something into the ear of Viking Ruddar. \n");
      vik=present("viking ruddar",environment(this_player()));
      date=ctime(time());
      sscanf(date,"%s %s %d %s",words1,words2,day,words3);
      if(day > 29) day=day-30;
      if(day > 19) day=day-20;
      if(day >  9) day=day-10;
      sailcmds=({"all aboard","home we go","ride the sea",
                 "break up camp","back voyage","ride the waves",
                 "leave the bay","gather the loot","hoist the flag",
                 "at the oars"});
      write("The raven scream once and disappear into the sky. \n");
      say("The raven whisper something into Viking Ruddar's ear. \n"
        + "Then they scream once and disappear into the sky. \n",this_player());
      tell_object(vik,"Odin says: " +sailcmds[day]+ "\n");
      destruct(this_object());
      return 1;
      }
   if(present("viking leadar",environment(this_player()))) {
      write("Hugin whispers into your left ear: We'll convince him to let you use his boat. \n"
          + "Munin whispers something into Viking Leadar's ear. \n"
          + "Viking Leadar says: Here do you have my permission to use the rowing boat. \n");
      vik=clone_object("/players/uglymouth/vikings/items/voucher");
      vik->set_alt_name("voucher of " + this_player()->query_real_name());
      vik->set_long("A voucher thats says that " + this_player()->query_short_name() + " has permission to use the vikings' boat. \n");
      transfer(vik,this_player());
      write("The raven scream once and disappear into the sky. \n");
      say("Viking Leadar gives a permission voucher to " +this_player()->query_name() + ". \n"
        + "The rave scream once and disappear in the sky. \n",this_player());
      destruct(this_object());
      return 1;
      }
   if(present("viking keepar",environment(this_player()))) {
      write("Hugin whispers into your left ear: We'll take you directly to the boss of \n"
          + "this expedition. \n"
          + "Munin whispers something into the ear of Viking Keepar. \n"
          + "Viking Keepar smiles as he opens the entrance of the big tent to show you in. \n");
      write("The raven scream once and disappear in the sky. \n");
      say("One raven whispers something into the ear of Viking Keepar. \n"
        + "Then the raven scream once and disappear into the sky. \n",this_player());
      this_player()->move_player("into the big tent#players/uglymouth/vikings/tent1");
      destruct(this_object());
      return 1;
      }
   if(present("viking luckar",environment(this_player()))) {
      write("Hugin whispers into your left ear: These Vikings brew the best mead in the world. \n"
          + "Munin whispers into your right ear: Here, taste it... \n");
      vik=present("viking luckar",environment(this_player()));
      mead=present("mead",vik);
      if(mead) {
         write("Viking Luckar gives you a mug of mead. \n");
         say("Viking Luckar gives " + this_player()->query_short_name() + " a mug of mead. \n",this_player());
         transfer(mead,this_player());
         write("The raven scream once and disappear into the sky. \n");
         say("The raven scream once and disappear in the sky. \n",this_player());
         destruct(this_object());
         return 1;
         }
   mead=clone_object("/players/uglymouth/vikings/items/mead");
   transfer(mead,this_player());
   write("Suddenly a mug of mead appears into your hand. \n");
   write("The raven scream once and disappear into the sky. \n");
   say("The raven scream once and disappear into the sky. \n",this_player());
      destruct(this_object());
      return 1;
      }
   write("Hugin whispers into your left ear: Why did you call us when there's no need? \n"
        + "Munin whispers into your right ear: Now you've wasted your chance for devine help. \n"
       + "The raven scream once and disappear in the sky. \n");
   say("The raven whisper something into " + this_player()->query_possessive() + " ears. \n"
     + "The raven scream once and disappear in the sky. \n",this_player());
   destruct(this_object());
   return 1;
   }

drop() {
   return 1;
   }
