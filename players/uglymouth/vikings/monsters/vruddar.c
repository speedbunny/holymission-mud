inherit "obj/monster";
object arm;
int at_home,busy_catching;

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("viking Ruddar");
      set_alt_name("viking ruddar");
      set_alias("viking");
      set_short("Viking Ruddar");
      set_long("Viking Ruddar is a tough looking viking and a dedicated sailor. \n"
             + "His weather-worn body is dressed in ditto sailor`s clothes. \n"
             + "As first mate of the dragonship Ruddar is held in high esteem \n"
             + "by his comrades. And it shows: he is not a guy that likes to take \n"
             + "orders from others than his captain. \n");
      set_level(15);
      set_race("human");
      set_gender(1);
      set_al(-50);

      if(!present("longknife")) {
         arm=clone_object("/players/uglymouth/vikings/items/longknife");
         arm->set_long("A very sharp longknife. \n");
         transfer(arm,this_object());
         command("wield longknife");
         }

      if(!present("clan cape")) {
         arm=clone_object("/players/uglymouth/vikings/items/viktunic");
         arm->set_name("clan cape");
         arm->set_alias("cape");
         arm->set_short("A red and white cape");
         transfer(arm,this_object());
         command("wear cape");
         }

      }
   }


int catch_tell(string str) {
string name,cmd,sex;
string date,words1,words2,words3,*leavecmds;
int day;
object ob,medal;
   if(busy_catching) return 0;
   if(sscanf(str,"%s arrives",name)==1) {
      ob=find_object("/players/uglymouth/vikings/ship");
      if(ob->query_location()==0) at_home=0;
      return 1;
      }
   if(sscanf(str,"%s says: %s",name,cmd)!=2 &&
      sscanf(str,"%s tells you: %s",name,cmd)!=2) {
      return 1;
      }
   busy_catching=1;
   if(this_player()->query_quests("viking")) {
      tell_object(this_player(),"Viking Ruddar tells you: I already gave you a free ride once. \n"
         + "I don't intend to make that a habit. Get off my ship! \n");
      busy_catching=0;
      return 1;
      }
   if(at_home==1) {
      tell_room(environment(this_object()),"Viking Ruddar says: But we're already home. Let's feast before leaving again. \n");
      busy_catching=0;
      return 1;
      }
   date=ctime(time());
   sscanf(date,"%s %s %d %s",words1,words2,day,words3);
   leavecmds=({"all aboard","home we go","ride the sea","break up camp",
      "back voyage","ride the waves","leave the bay",
      "gather the loot","hoist the flag","at the oars"});
   if(day > 29) day=day-30;
   if(day > 19) day=day-20;
   if(day > 9)  day=day-10;
   if(cmd!=leavecmds[day] + "\n") {
      write("Viking Ruddar says: Don't bother me with that crap! \n");
      busy_catching=0;
      return 1;
      }
   medal=present("the village medallion of symria",this_player());
   if(!medal || medal->query_parts_done()!=1) {
      write("You're not a viking. I don't take orders from you! \n");
      busy_catching=0;
      return 1;
      }
   sex = "Sir";
   if(this_player()->query_gender()==2) sex = "Ma'm";
   tell_room(environment(this_object()),"Viking Ruddar says: Aye aye, " + sex + ", we'll leave right away. \n"
      + "Viking Ruddar starts giving commands. \n"
      + "You see the vikings break up their camp and come aboard. \n"
      + "The sails are set and the ship leaves the coast. \n"
      + "After a safe journey, the ship throws out the anchor in a very cold harbour. \n"
      + "You disembark from the ship. \n");
   ("/players/uglymouth/vikings/ship")->sail_away();
   this_player()->move_player("the ship#players/uglymouth/vikings/vikpier");
   medal->set_parts_done();
   at_home=1;
   busy_catching=0;
   return 1;
   }
