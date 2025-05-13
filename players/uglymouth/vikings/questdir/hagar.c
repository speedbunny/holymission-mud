/* the viking boss can end the quest if he gets the medallion */
inherit "obj/monster";
int busy_catching;
string name;

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("high Lord Hagar of the Vikings");
      set_alt_name("high lord hagar");
      set_alias("hagar");
      set_short("High Lord Hagar of the Vikings");
      set_long("High Lord Hagar is the leader of several clans of Vikings. \n"
             + "He is a man who knows he's in command and is willing to prove it \n"
             + "to anyone who doesn't believe it. He is the one who decides who \n"
             + "is allowed to join his ranks and who becomes bear food. \n");
      set_level(20);
      set_race("human");
      set_gender(1);
      }
   }

int catch_tell(string str) {
   if(busy_catching) return 0;
   if(sscanf(str,"%s arrives",name)==1) {
      call_out("arrival_text",2);
      return 1;
      }
   return 1;
   }

void arrival_text() {
      if(!present("the village medallion of symria",this_player())) {
         write("High Lord Hagar shouts: Who let this scum in? Get it out of here! \n");
         return;
         }
      write("High Lord Hagar says: Well, well, what have we here? \n"
          + "High Lord Hagar examines you carefully. \n"
          + "High Lord Hagar says: You might make a good Viking, " + capitalize(name) + ". \n"
          + "I will make you one, if you give me a token of your first successful conquest. \n");
      return;
      }

end_quest() {
object medal;
   medal=present("the village medallion of symria");
   if(medal->query_parts_done()!=2) {
      write("High Lord Hagar turns red in anger. \n"
          + "High Lord Hagar shouts: You have not conducted this expedition in a proper way! \n"
          + "High Lord Hagar give you back the medallion. \n");
      transfer(medal,this_player());
      return;
      }
   if(creator(medal)!="uglymouth") {
      write("High Lord Hagar carefully examines the medallion and then crushes it in his hand. \n"
          + "High Lord Hagar says: Cheating is not a Viking's way to do things! \n");
      log_file("QUESTS.CHEAT",this_player()->query_real_name()+" "+filename(medal)+" "+ctime(time())+"\n");
      destruct(medal);
      return;
      }
   write("High Lord Hagar carefully examines the medallion and bursts out in laughter. \n"
       + "High Lord Hagar says: Well done, " + this_player()->query_short_name() + ". You just showed to have \n"
       + "the Viking Spirit by completing this expedition. Let me therefore declare you: \n"
       + "A Viking of my Clan! \n");
   this_player()->set_quest("viking");
   log_file("uglymouth.quest",this_player()->query_real_name() + " " + ctime(time()) + "\n");
   if(!(this_player()->query_immortal())) {
      shout(" High Lord Hagar of the Vikings has accepted " + this_player()->query_short_name() + " in his clan. \nBeware everyone!! \n");
      }
   this_player()->set_pretitle("Viking");
   this_player()->set_title("of Hagar's Clan");
   this_object()->load_chat(30,
      ({"All Vikings cheer. \n",
        "The Vikings do the 'wave'. \n",
        "Everyone toasts to your good luck. \n",
        "Hagar smiles happily. \n",
        }));
   destruct(medal);
   return;
   }
