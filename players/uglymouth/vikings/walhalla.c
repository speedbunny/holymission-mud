/* 24-SEP-93 Galadriel: sytax error, brackets added line 15 */
/* the viking gods' home */
inherit "room/room";
string hero;
int busy,level;
int ft;
int *loki_done;

void reset(int arg) {
object odin,thor,loki,mjol,ob;
   odin = present("odin");
   if(odin) /* G: dunno what you want but added this line to make it load */
   if(!odin->query_hero()) {
      ob = first_inventory(this_object());
      while(ob) {
         if(ob->query_name() == "ruby" || ob->query_name() == "emerald"
            || ob->query_name() == "sapphire") destruct(ob); /* brackets ;) */
         ob = next_inventory(this_object());
         }
      }
   if(arg) return 0;
   loki_done=allocate(6);

   set_light(1);
   short_desc="WALHALLA";
   long_desc="You stand on a huge wooden floor. The ceiling is beyond your "
           + "vision. Then you see that what you first held for mountains "
           + "are in fact giants beyond belief. And what you're standing on "
           + "is not a floor, but the table of these Gods, as you begin to "
           + "recognize several items as being mugs and dishes.\n";
   items=({"gods","The dreaded gods of the vikings: Odin, Thor and Loki",
           "table","The huge table the gods hold their feasts on. Are you on the menu?",
           "items","Mugs, dishes, knives and other eating equipment, all of divine size",
           "mugs","One mug with steaming mead for each God. A servant refills them whenever \n"
                + "a God empties his mug",
           "dishes","Filled with devine food. You can't help noticing it's stew",
           "food","It probably tasts devine. Maybe you dare to try some?",
           "stew","It reminds you of your youth. You remember you preferred other food",
           "equipment","The main thing you notice is that the Gods love spices",
           "spices","Salt and pepper, in great quantities",
           "salt","Devine salt. You notice a mouse nibbling from it",
           "mouse","The mouse curses Odin. Odin kills it",
           "pepper","Very hot pepper. Anyone would sneeze if inhaled",
           "knives","They're quite big, but incredibly sharp and very well balanced\n"
              + "for throwing",
           });
   smell="Your nose is filled with the most divine scents you've ever smelled. \n";
   property = ({ "no_fight", "no_teleport" });

   move_object(clone_object("/players/uglymouth/vikings/monsters/odin"),this_object());
   move_object(clone_object("/players/uglymouth/vikings/monsters/thor"),this_object());
   move_object(clone_object("/players/uglymouth/vikings/monsters/loki"),this_object());
   move_object(clone_object("/players/uglymouth/vikings/items/mjolnir"),this_object());
   }

void init() {
   ::init();
   add_action("rude_leave","quit");
   add_action("eat_it","eat");
   add_action("empty_it","empty");
   add_action("empty_it","drink");
   add_action("throw_it","throw");
   add_action("curse","curse");
   add_action("search","search");
   add_action("get_it","get");
   add_action("get_it","take");
   add_action("blow_it","blow");
   }

int rude_leave() {
int i;
object odin;
   write("The Vikings Gods frown on your rude attempt to leave their presence. \n"
       + "You are magically transferred somewhere... \n\n");
   this_player()->move_player("X#players/uglymouth/vikings/infjungle1");
   level=0;
   busy=0;
   for(i=0;i<6;i++) {
      loki_done[i]=0;
      }
   odin = present("odin");
   odin->hero_left();
   return 1;
   }

int eat_it(string str) {
string godname;
object target,odin;
   if(busy!=0) {
      write("You're busy doing other things right now. \n");
      return 1;
      }
   if(!str) return 0;
   if(str=="food") {
      write("Whose food do you want to eat? \n");
      return 1;
      }
   if(sscanf(str,"food of %s",godname)!=1) {
      if(sscanf(str,"%s's food",godname)!=1) {
         return 0;
         }
      }
   if(godname!="odin" && godname!="thor" && godname!="loki") {
      write("This God does not have a plate on this table. \n");
      return 1;
      }
      if(ft!=0) {
         loki_done[0]=0;
         ft=0;
         }
   if(loki_done[0]==1) {
      write("The gods know this trick and don't fall for it again. \n");
      return 1;
      }
   busy=1;
   write("You eat some food from " + capitalize(godname) + "'s plate. It tastes divine. \n");
   target=present(godname);
   target->irritated(level);
   if(godname=="loki") {
      level++;
      loki_done[0]=1;
      }
   if(level==6) {
      odin=present("odin");
      odin->end_test();
      }
   return 1;
   }

int empty_it(string str) {
string godname;
object target,odin;
   if(busy!=0) {
      write("You're busy doing other things right now. \n");
      return 1;
      }
   if(!str) return 0;
   if(str=="mug") {
      write("Whose mug do you want to empty? \n");
      return 1;
      }
   if(sscanf(str,"mug of %s",godname)!=1) {
      if(sscanf(str,"%s's mug",godname)!=1) {
         return 0;
         }
      }
   if(godname!="odin" && godname!="thor" && godname!="loki") {
      write("This God does not have a mug on this table. \n");
      return 1;
      }
      if(ft!=0) {
         loki_done[1]=0;
         ft=0;
         }
   if(loki_done[1]==1) {
      write("The gods know this trick and don't fall for it again. \n");
      return 1;
      }
   busy=1;
   write("You pull " + capitalize(godname) + "'s mug to the ground. Divine mead flows away... \n");
   target=present(godname);
   target->irritated(level);
   if(godname=="loki") {
      level++;
      loki_done[1]=1;
      }
   if(level==6) {
      odin=present("odin");
      odin->end_test();
      }
   return 1;
   }

int blow_it(string str) {
string godname;
object target,odin;
   if(busy!=0) {
      write("You're busy doing other things right now. \n");
      return 1;
      }
   if(!str) return 0;
   if(str=="pepper") {
      write("Blow pepper at whom? \n");
      return 1;
      }
   if(sscanf(str,"pepper at %s",godname)!=1) {
         return 0;
         }
   if(godname!="odin" && godname!="thor" && godname!="loki") {
      write("This God is not seated at this table right now. \n");
      return 1;
      }
      if(ft!=0) {
         loki_done[2]=0;
         ft=0;
         }
   if(loki_done[2]==1) {
      write("The gods know this trick and don't fall for it again. \n");
      return 1;
      }
   busy=1;
   write("You blow a handful of black pepper at " + capitalize(godname) + ". He starts to S N E E Z E !! \n");
   target=present(godname);
   target->irritated(level);
   if(godname=="loki") {
      level++;
      loki_done[2]=1;
      }
   if(level==6) {
      odin=present("odin");
      odin->end_test();
      }
   return 1;
   }

curse(string str) {
string godname;
object target,odin;
   if(busy!=0) {
      write("You're busy doing other things right now. \n");
      return 1;
      }
   if(str!="odin" && str!="thor" && str!="loki") {
      write("Your curse doesn't find a target and fades away. \n");
      return 1;
      }
   godname=str;
      if(ft!=0) {
         loki_done[3]=0;
         ft=0;
         }
   if(loki_done[3]==1) {
      write("The gods know this trick and don't fall for it again. \n");
      return 1;
      }
   busy=1;
   write("Your curse shoots directly to the heart of " + capitalize(godname) + ". He looks hurt. \n");
   target=present(godname);
   target->irritated(level);
   if(godname=="loki") {
      level++;
      loki_done[3]=1;
      }
   if(level==6) {
      odin=present("odin");
      odin->end_test();
      }
   return 1;
   }

int throw_it(string str) {
string godname;
object target,odin;
   if(busy!=0) {
      write("You're busy doing other things right now. \n");
      return 1;
      }
   if(!str) return 0;
   if(str == "knife") {
      write("Throw a knife at whom? \n");
      return 1;
      }
   if(sscanf(str,"knife at %s",godname)!=1) {
      return 0;
      }
   if(godname!="odin" && godname!="thor" && godname!="loki") {
      write("This God is not seated at this table. \n");
      return 1;
      }
      if(ft!=0) {
         loki_done[4]=0;
         ft=0;
         }
   if(loki_done[4]==1) {
      write("The gods know this trick and don't fall for it again. \n");
      return 1;
      }
   busy=1;
   write("You throw a knife at " +capitalize(godname)+ ". He dodges it with ease,\n"
      + "but is deeply insulted by your attempt.\n");
   target=present(godname);
   target->irritated(level);
   if(godname=="loki") {
      level++;
      loki_done[4]=1;
      }
   if(level==6) {
      odin=present("odin");
      odin->end_test();
      }
   return 1;
   }

int search(string str) {
object gem;
   if(present("sapphire") && present("emerald") && present("ruby")) return 0;
   write("You find some valuable gems hidden under a plate. \n");
   gem=clone_object("/obj/treasure");
   gem->set_name("sapphire");
   gem->set_short("A sapphire");
   gem->set_long("A craftly cut sapphire. In its centre blue shining symbols read 'Odin'. \n");
   transfer(gem,this_object());
   gem=clone_object("/obj/treasure");
   gem->set_name("emerald");
   gem->set_short("An emerald");
   gem->set_long("A craftly cut emerald. In its centre green shining symbols read 'Thor'. \n");
   transfer(gem,this_object());
   gem=clone_object("/obj/treasure");
   gem->set_name("ruby");
   gem->set_short("A ruby");
   gem->set_long("A craftly cut ruby. In its centre red shining symbols read 'Loki'. \n");
   transfer(gem,this_object());
   return 1;
   }

int get_it(string str) {
string godname;
object target,odin,gem;
   if(str == "all") {
      write("Odin says: Your mortal movements seem to be slowed in the fabric of\n"
         + "devine space. You'll have to take one item at a time.\n");
      return 1;
      }
   if(str!="sapphire" && str!="emerald" && str!="ruby") return 0;
   if(busy!=0) {
      write("You're busy doing other things right now. \n");
      return 1;
      }
   if(str=="sapphire") godname="odin";
   if(str=="emerald") godname="thor";
   if(str=="ruby")    godname="loki";
      if(ft!=0) {
         loki_done[5]=0;
         ft=0;
         }
   if(loki_done[5]==1) {
      write("The gods know you're greedy and hide away their gems. \n");
      gem=present("sapphire");
      if(gem) destruct(gem);
      gem=present("emerald");
      if(gem) destruct(gem);
      gem=present("ruby");
      if(gem) destruct(gem);
      return 1;
      }
   busy=1;
   write(capitalize(godname) + " is annoyed about your materialistic thoughts and shields his gem. \n");
   target=present(godname);
   target->irritated(level);
   if(godname=="loki") {
      level++;
      loki_done[5]=1;
      }
   if(level==6) {
      odin=present("odin");
      odin->end_test();
      }
   return 1;
   }

void set_busy(int arg) {
   busy=arg;
   return 0;
   }

void failed_test() {
   level--;
   ft=1;
   return 0;
   }

int complete_test() {
int i;
object medal,ob;
   this_player()->move_player("X#players/uglymouth/vikings/falltop");
   medal=present("the village medallion of symria",this_player());
   medal->set_parts_done();
   level=0;
   busy=0;
   for(i=0;i<6;i++) {
      loki_done[i]=0;
      }
   if(ob = present("ruby")) destruct(ob);
   if(ob = present("emerald")) destruct(ob);
   if(ob = present("sapphire")) destruct(ob);
   return 0;
   }
