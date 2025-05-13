/* Candy, chief confectioner */
inherit "obj/monster";
int busy_catching;

reset(arg) {
object cap;
   ::reset(arg);

   if(!arg) {
      set_name("candy, the chief confectioner");
      set_alias("candy");
      set_alt_name("confectioner");
      set_long("Candy is a corpulent little hobbit with a broad smile on her red \n"
         + "face. A few brown hairs stand stubbornly upright from under her baker's cap. \n"
         + "She seems to do her job with great pleasure. \n");
      set_race("hobbit");
      set_gender(2);
      set_size(2);
      set_level(3);
      set_trapped(1);

      cap=clone_object("/obj/armour");
      cap->set_name("baker's cap");
      cap->set_alias("cap");
      cap->set_short("A baker's cap");
      cap->set_long("A small white cylinder, with upon it cloth shaped like a cloud. It's \n"
         + "covered with a layer of flour. \n");
      cap->set_value(10);
      cap->set_ac(0);
      cap->set_type("helmet");
      set_size(2);
      transfer(cap,this_object());
      command("wear cap");
      }
   }

catch_tell(str) {
string name,prefix;
   if(sscanf(str,"%s arrives",name)!=1) return;
   if(busy_catching) return;
   busy_catching=1;
   prefix = "Master";
   if(this_player()->query_gender()==2) prefix = "Mistress";
   write("Candy tells you: Welcome to my store, " +prefix+" "+name+ ".\n"
      + "    How may I help you? \n");
   busy_catching=0;
   return 1;
   }
