/* viking keepar guards the chief's tent */
inherit "obj/monster";
int bloodalc;

void reset(int arg) {
   bloodalc=0;
   ::reset(arg);

   if(!arg) {
      set_name("viking keepar");
      set_alt_name("keepar");
      set_alias("viking");
      set_short("Viking Keepar");
      set_long("Viking Keepar is a big and strong man. \n"
             + "He obviously is on guard duty. Although he looks very \n"
             + "determined, the look in his eyes betrays he regrets not \n"
             + "being with his comrades to feast. \n");
      set_level(16);
      set_al(-15);
      set_no_steal(1);
      set_race("human");
      set_gender(1);

      transfer(clone_object("/players/uglymouth/vikings/items/vikaxe"),this_object());
      transfer(clone_object("/players/uglymouth/vikings/items/viktunic"),this_object());
      transfer(clone_object("/players/uglymouth/vikings/items/vikhelm"),this_object());
      command("wield axe");
      command("wear tunic");
      command("wear helm");

      load_chat(30,
         ({"Viking Keepar says: I don't take orders from anybody but Vikings. \n",
           "Viking Keepar says: Vikings respect each other. Others are mere scum. \n",
           "Viking Keepar says: I cannot let you enter the chief's tent. \n",
           "Viking Keepar says softly: I wish I could be at the feast. Guard duty makes \nme so thirsty. \n",
           "Viking Keepar looks suspiciously at you. \n",
           }));
      }
   }

void do_drink() {
   write("Viking Keepar's eyes grow big with desire as he smells the mead. \n");
   command("drink mead");
   tell_room(environment(this_object()),"Viking Keepar feels in Walhalla as he empties a mug of mead. \n");
   write("Viking Keepar tells you: Thanks friend, I needed that. \n");
   bloodalc=bloodalc+25;
   if(bloodalc > 60) {
      tell_room(environment(this_object()),"Viking Keepar looks drunk. \n");
      call_out("sober_up",60);
      }
   return;
   }

int drunk() { return bloodalc; }

void sober_up() {
   bloodalc=bloodalc-20;
   if(bloodalc > 20) {
      call_out("sober_up",60);
      }
   return;
   }

void init() {
   ::init();
   add_action("give","give");
   }

int give(string str) {
object vik,bev;
   if(str!="mead to viking" && str!="mead to viking keepar" &&
      str!="mead to keepar" && str!="mug of mead to keepar" &&
      str!="mug of mead to viking" && str!="mug of mead to viking keepar") return 0;
   bev=present("mead",this_player());
   if(!bev) {
      write("Viking Keepar is disappointed as he notices you don't have any mead. \n");
      return 1;
      }
   destruct(bev);
   do_drink();
   return 1;
   }
