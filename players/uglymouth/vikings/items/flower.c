/* a lovely flower */
inherit "obj/treasure";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_id("flower");
      set_alias("tropical flower");
      set_short("A tropical flower");
      set_value(5);
      }
   }

void init() {
   ::init();
   add_action("smell","smell");
   add_action("rid","drop");
   add_action("eat","eat");
   }

int smell(string str) {
   if(str!="flower") return 0;
   write("Its scent is herbal, combined with the sweetness of nectar. \n");
   return 1;
   }

int rid(string str) {
   if(str!="flower") return 0;
   write("The flower gets caught in the air and is blown away. \n");
   destruct(this_object());
   return 1;
   }

int eat(string str) {
   if(str!="flower") return 0;
   write("As nice as is smells, so awfull it tastes! Bweeehh!! \n");
   say(this_player()->query_name() + " eats a beautiful flower.\n");
   this_player()->heal_self(random(5));
   destruct(this_object());
   return 1;
   }
