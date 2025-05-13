// 12-29-94 Mangla: corrected the attack messages.
#define TP this_player()
#define E environment

inherit "/obj/monster";

reset(arg) {
  ::reset (arg);
  if (!arg) { 
  set_name("cobra");
  set_short("Venomous Cobra");
  set_long("This is a 10 foot long viper with 6 inch fangs.\n");
  set_level(25);
      set_wc(40);
  set_al(-200);
  add_money(2000);
  return 1;
  }
 }

  attack() {                          /* redefine of the attack function */
    object tp;
    string NA,POSS;

   if (::attack()) {

      tp=this_object()->query_attack();
      NA=tp->query_name();
      POSS=tp->query_possessive();

      if (random(100)<20) {             /* 20% chance */
         tp->add_poison(8); /* thats 8+7+6..=36Hp */
         switch(random(4)) {
         case 0:
         tell_room(E(),"The cobra bites "+NA+" in "+POSS+" left foot!\n");
         break;
         case 1:
         tell_room(E(),"The cobra bites "+NA+" in "+POSS+" right foot!\n");
         break;
         case 2:
         tell_room(E(),"The cobra bites "+NA+" in "+POSS+" right hand!\n");
         break;
         case 3:
         tell_room(E(),"The cobra bites "+NA+" in "+POSS+" left hand!\n");
         break;
         return 1;
        }
    return 1;
    }
   return 1;
   }
  return 1;
  } 


