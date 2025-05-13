/* Changed by Ethereal Cashimor, 260493, smell added to eat */

inherit "obj/weapon";
  int charges;

   reset(arg) {
    charges=300;
     ::reset(arg);
   if (arg) return;
   set_name("hank");
    set_short("A garlic hank");
   set_long("A simple garlic hank, but the witch hates garlic\n");
   set_weight(1);
   set_value(20);
   set_hit_func(this_object());
   }
 weapon_hit(attacker) {
  if (attacker->query_race()=="whiskywitch") {
     write("As you throw the garlic hank against the witch she screams from pain.\n");
     say(this_player()->query_name()+" throws the garlic hank against the witch.\n");
    charges=charges-1;
   return 3000;
  }
   if (charges<1) { 
     write("Suddenly, your hank bursts into small pieces\n"+
           "which fills the air with a bad smell.\n");
           destruct(this_object());
     return 1;
    }
   return 1;
   }

init() {
  add_action("eat","eat");
 ::init();
  }

eat(str) {
  if(id(str)) {
    write("As you eat the delicious galaric hank, you feel a bad smell\n"
        + "coming from your mouth.\n");
    say(this_player()->query_name()+ " eats a delicous galaric hank\n.");
    this_player()->set_smell(capitalize(this_player()->query_pronoun())
                           + " is surrounded by a terrible garlic smell!");
    destruct(this_object());
    return 1;
  }
}

   query_quest_item() { return 1; }

