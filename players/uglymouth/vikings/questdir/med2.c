/* a questitem: without it no help from the vikinggods */
inherit "obj/armour";
int parts_done;

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("the village medallion of symria");
      set_alias("medallion");
      set_short("The village medallion of Symria");
      set_long("It is a wooden medallion with the picture of a mermaid \n"
             + "engraved in it with great craftsmanship. It feels like \n"
             + "it's powered with some kind of lifeforce. \n");
      set_value(100);
      set_type("amulet");
      set_ac(1);
      set_weight(0);
      }
   }

query_quest_item() {
   return 1;
   }

void init() {
   ::init();
   add_action("give","give");
   add_action("quit_it","quit");
   }

drop() {
   write("As you drop the medallion it transforms into a white dove and flies away.\n");
   destruct(this_object());
   return 1;
   }

quit_it() {
  write("As you drop the medallion, it transforms into a white dove and flies away.\n");
  destruct(this_object());
  return 0;
  }

int give(string str) {
string item,name;
object eldest;
   if(sscanf(str,"%s to %s",item,name)!=2) return 0;
   if(item!="medallion" && item!="village medallion of symria") return 0;
   if(name!="eldest" && name!="village eldest") {
      if(name!="hagar" && name!="high lord hagar") {
         write("You feel you're not allowed to give such a valuable item to just anybody. \n");
         return 1;
         }
      eldest=present("high lord hagar",environment(this_player()));
      if(!eldest) {
         write("High Lord Hagar is not here right now. \n");
         return 1;
         }
      write("You give the medallion to High Lord Hagar as a token of the vikings' conquest. \n");
      transfer(this_object(),eldest);
      eldest->end_quest();
      return 1;
      }
   eldest=present("village eldest",environment(this_player()));
   if(!eldest) {
      write("The village eldest is not here right now. \n");
      return 1;
      }
   write("You give the medallion back. \n"
       + "The village eldest looks very disappointed at you. \n");
   transfer(this_object(),eldest);
   eldest->init_command("wear medallion");
   return 1;
   }

void set_parts_done() {
   parts_done++;
   return;
   }

int query_parts_done() {
   return parts_done;
   }
