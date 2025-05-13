#define TP  this_player()
#define TO  this_object()
#define TPN TP->query_name()
#define TPRN capitalize(TPN)
#define PARTNER "/players/portil/guild/room"
#define MAXPR  95 
#define _wiz "/players/portil/"

inherit "/obj/npc";
int chk, is_berz;

void reset(int flag) {
   ::reset(flag);
   if (flag == 0) {
   set_name("Fighter Sledge");
   set_living_name("sledge");
   set_alt_name("sledge");
   set_short(query_name());
   set_level(127);
   set_hp(35000);
   set_race("human");
   set_size(3);
   set_gender(1);
   load_chat(5,
      ({ 
"Fighter Sledge says: Type practice to train your skills with me.\n",
      "Fighter Sledge says: My skills improve your damage !\n",
      "Fighter Sledge says: Type 'practice' to see your skills.\n",
      "Fighter Sledge says: Type 'practice <skill>' and I will teach you.\n",
      "Fighter Sledge says: Use 'help weapontype' for more information!\n",
      "Fighter Sledge grins evilly.\n",
      }));
   load_a_chat(9,
      ({
      "Fighter Sledge growls: You had better leave now or\nI will be forced to kill you!\n",
      "Fighter Sledge growls: I will cut you into so many pieces,\n your mother will not even recognize you.\n",
      "Fighter Sledge growls: Here let me teach you some lessons!\n",
      "Fighter Sledge roars in anger.\n",
      }));
   set_long(
      "You see a big, muscular Human Fighter. He is well known\n"+
      "as one of the best fighters in this world. With his grinning\n"+
      "face he looks at you like he would say:\n\n"+
      "             Get some 'practice' weakling !\n");
   set_spell_mess1("Fighter Sledge attacks with his shield!\n");
   set_spell_mess2("Fighter Sledge bashes you with his shield.\n");
   set_chance(80);
   set_dead_ob(TO);
   set_spell_dam(150);
   set_attacks(6);
   set_attacks_change(100);
   set_no_steal();
   set_n_ac(30);
   add_money(1+random(1));
   move_object(clone_object("/players/llort/secure/thammer"),TO);
   move_object(clone_object("/players/llort/animals_stuff/diring"),TO);
   move_object(clone_object("/players/whisky/obj/arms"),TO);
   move_object(clone_object("/players/whisky/obj/scales/steel_scale"),TO);
   move_object(clone_object("/players/whisky/obj/tower_shield"),TO);
   move_object(clone_object("/players/uglymouth/vikings/items/vikhelm"),TO);
   init_command("wield hammer");
   init_command("wear arms");
   init_command("wear dragonhide");
   init_command("wear shield");
   init_command("wear helm");
   init_command("wear ring");
   chk = 1;
   is_berz = 0;
   }
}

int attack() {
   if (::attack()) {
      if (!random(2) && attacker_ob && environment()==environment(attacker_ob)
        && !is_berz) {
         tell_room(environment(),"Fighter Sledge goes berzerk !\n");
         is_berz = 1;
         set_attacks(6);
         call_out("remove_berzerk",200);
         return 1;
      }
   return 0;
   }
}

void remove_berzerk() {
     is_berz = 0;
}
    
        
int query_str() {
    return 130;
}

void init() {
   ::init();
   add_action("do_practice","practice");
   add_action("do_practice","pr");
}

/* practice */

int do_practice(string arg) {
   int cost, sklev;

   if (TP->query_guild() != 3) {
      notify_fail("Fighter Sledge tells you:\n"+
         "You are not a Fighter. Go home !\n");
      return 0;
   }
   else if (catch(call_other(PARTNER,"???"))) {
      notify_fail("Fighter Sledge tells you:\n"+
         "I have no time for you. Go home !\n");
      return 0;
   }
   else if (!arg) {
      write("Fighter Sledge tells you: "+
         "Here are the skills I can teach you:\n");
      tell_object(TP,PARTNER->list_skills(TP,2));
      return 1;
   }
   else if (!(sklev=PARTNER->query_skill(TP,"fighter_"+arg)) ) {
      notify_fail("Fighter Sledge tells you:\n"+
         "This is not a skill I know !\n");
      return 0;
   }
   else if (TP->query_money()<(cost=PARTNER->query_cost(TP,"fighter_"+arg))) {
      notify_fail("Fighter Sledge tells you:\n"+
         "Further practice in "+arg+" would cost you "+
         to_string(cost)+" coins.\n");
      return 0;
   }
   else if (sklev > (MAXPR - 20) && TP->query_property("fighter_legend")==-1) {
      notify_fail("Fighter Sledge tells you:\n"+
         "You have to be a Legend for me to teach you more !\n");
      return 0;
   }
   else if (sklev >= MAXPR) {
      notify_fail("Fighter Sledge tells you:\n"+
         "Sorry, but I can't teach you more, you are now almost "+
         "as good as i am !\n");
      return 0;
   }
   else {
      if (chk && sklev > random(MAXPR + TP->query_int() + TP->query_dex())) {
         write("You practice your "+arg+" skill with Fighter Sledge for "+
            to_string(cost)+" gold coins.\n");
         say("Fighter Sledge shows something to "+TPN+"\n",TP);
         TP->add_money(-cost);
         write("You are confused.\n");
         say(TPN+" looks confused.\n");
            chk--;
            return 1;
      }
      if (PARTNER->raise_skill(TP,"fighter_"+arg,1)) {
         write("You practice your "+arg+" skill with Fighter Sledge for "+
            to_string(cost)+" gold coins.\n");
         say("Fighter Sledge shows something to "+TPN+"\n",TP);
         TP->add_money(-cost);
         chk=1;
       }
       else {
          write("Oops, Fighter Sledge made a mistake. He seems too tired to teach.\n");
          write("You pay nothing.\n");
       }
   }
   return 1;
}


int monster_died(object mob) {
   object ob;

   if (!TP->query_immortal()) {
      shout(TPRN+" sucessfully challenged Fighter Sledge !\n");
   }

   if (ob)
      destruct(ob);
   return 0;
}

int hold(object caller, int time) {
   return ::hold(caller,0);
}

int add_poison(int x) {
   return (x/30);
}

int run_away() {
   return 1;
}
