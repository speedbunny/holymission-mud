inherit "/obj/monster";
object o1;
string a_chat_str;

reset(arg) {
  ::reset(arg);
 a_chat_str = ({
   "The Zombie shouts: I'll kill you, bastard !\n",
   "The Zombie shouts: Damned humans, I'll eat you !!!.\n",
   "The Zombie tries to tear off your ribs.\n",
   "The Zombie shouts: ARrrrrrrrrrgggggggggggg.\n",
   "The Zombie slashes its bloody bone against you.\n",
   "The Zombie shouts: Dead humans are cool.\n",
   "The Zombie shouts: Kill the human, before it runs away.\n",
   "The Zombie shouts: I'll convert you to hash !!!!!!\n",
   "The Zombie says: Have you ever tried drinking human blood?\n",
   "The Zombie tries to tear off your clothes !!!!!\n",
   "The Zombie shouts: Humans stink.\n",
   "The Zombie shouts: I'll heat the oven !!!!!!\n",
   "The Zombie shouts: I'll cook you !!!!!!\n",
   "The Zombie smashes a bloody piece of flesh against your face.\n",
                                               });
 if (arg) return 1;

   set_name("zombie");
   set_alias("stinking Zombie");
   set_level(8);
   set_short("A stinking Zombie");
   set_long("He looks like he wants to eat you.\n");
   set_gender(1+random(2));
   set_race("human");
   set_aggressive(1);
   set_al(-100);
   load_a_chat(60,a_chat_str);
   o1=clone_object("players/whisky/hole/obj/bone");
   move_object(o1,this_object());
   init_command("wield bone");
  return 1;
  }
