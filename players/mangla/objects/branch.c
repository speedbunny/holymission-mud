inherit "obj/weapon";

#define WBAN    ob->query_name()

void reset (int arg) {
  ::reset(arg);
     set_alt_name("limb");
     set_alias("branch");
     set_name("branch");
     set_hit_func(this_object());
     set_weight(4);
     set_value(1000);
     set_class(19);
     set_type(3);
     set_short("A Branch");
     set_long("A thorny branch that seems to be crossbred with nightshade.\n");
}

int weapon_hit(object ob) {

   if (!random(4)) {
     say("Sap from the branch runs into the "+WBAN+"'s wounds.\n");
     write("Sap from the branch runs into the "+WBAN+"'s wounds.\n");
     if (ob->is_npc())
     ob->add_poison(10);
   }
   return 1;
}

/* 
int magic_hit(object ob) {

    int dam;

    dam = 1;
   switch(random(5)) {
     case 0: {
        say("The barbed thorns gouge out chunks from "+WBAN+"!\n");
        write("You angle the thorns on the branch to gouge out chunks from "+WBAN+"!\n");
        dam = 30;
        break;
     }
     case 1: {
        say("The barbed thorns tear out pieces from "+WBAN+"!\n");
        write("You angle the thorns on the branch to tear out pieces from "+WBAN+"!\n");
        dam = 20;
        break;
     }
     case 2: {
        say("The barbed thorns scratch "+WBAN+"!\n");
        write("You angle the thorns on the branch to scratch "+WBAN+"!\n");
        dam = 10;
        break;
     }
     default:
              dam = 2;
   }
   return dam;
}
  */
