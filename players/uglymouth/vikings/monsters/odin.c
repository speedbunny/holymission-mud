/* the highest vikinggod himself */
inherit "obj/monster";
string name,hero;
int busy_catching;
int i;

void reset(int arg) {
   ::reset(arg);

   if(!hero) {
      if(i == 3) {
         hero = 0;
         i = 0;
         }
      else i++;
      }

   if(!arg) {
   set_name("odin");
   set_short("Odin, deity superior and lover of mead");
   set_long("Odin, the highest of the viking gods. \n"
          + "He is the mightiest viking that ever lived, and looks like it. \n"
          + "He is just but severe, so beware, O Daring One. \n");
   set_level(20);     /* symbolic value */
   set_al(1000);
   set_race("deity");
   set_gender(1);
   i = 0;
   }
}

void irritated(int i) {
   write("Odin frowns. \n"
       + "Odin says: Don't tempt my patience mortal! \n");
   environment(this_object())->set_busy(0);
   return;
   }

int catch_tell(string str) {
   if(sscanf(str,"%s arrives",name)!=1) return 0;
   if(busy_catching!=0) return 0;
   busy_catching=1;
   if(name==hero) {
      write("Odin smiles amusedly. \n"
          + "Odin says: Have you come back for another try, mortal? \n"
          + "Odin says: Brave move! Good luck then. \n");
      busy_catching=0;
      return 1;
      }
   call_out("arrival_speech",5);
   environment(this_object())->start_test();
   hero=name;
   busy_catching=0;
   return 1;
   }

void arrival_speech() {
   write("Odin says: welcome "+name+" \n");
   write("We granted you this visit, for we think you worthy of the help you seek. \n"
       + "But no one gets something for nothing, as is good viking custom. \n"
       + "So we will only help you if you manage to get Mjolnir, Thor's hammer moved. \n");
   return;
   }

void end_test() {
object raven,env;
int i;
   write("Odin says: Smart move, mortal. You made Thor's hammer move. \n"
       + "Therefore I will grant you our help, but only once, so use it wisely. \n"
       + "You can 'call the raven' if you need our help. Leave now. \n\n");
   raven=clone_object("/players/uglymouth/vikings/items/ravenhelp");
   transfer(raven,this_player());
   env = find_object("/players/uglymouth/vikings/walhalla");
   env->complete_test();
   hero=0;
   return;
   }

string query_hero() {
   return hero;
   }

void hero_left() {
   hero = 0;
   return;
   }
