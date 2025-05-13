/* A pie full of cream. You can throw it... (*grin*) */
#define TP   this_player()
#define QSN  query_short_name()
#define QPN  query_pronoun()

inherit "obj/food";

reset(arg) {
   ::reset(arg);

   if(!arg) {
      set_name("cream pie");
      set_alias("pie");
      set_short("A cream pie");
      set_long("A nice round pie stuffed with cream. It looks more sticky than tasty. \n"
             + "Don't you just wonder if you can throw it at someone...? \n");
      set_eater_mess("The sticky stuff slithers down your throat... Bweehh! \n");
      set_eating_mess(" tries to eat a pie stuffed with cream without making \n"
         + "a mess of it. Of course, " + TP->QPN + " fails badly... \n");
      set_strength(random(3)+1);
      set_value(10);
      set_weight(1);
      }
   }

init() {
   ::init();
   add_action("throw_it","throw");
   }

throw_it(str) {
string name;   
object target;  
int i;   
   if(sscanf(str,"pie at %s",name)!=1 &&
      sscanf(str,"cream pie at %s",name)!=1) return;
   if(environment(TP) == find_object("/players/uglymouth/cakeshop/cakeshop")) {
      write("Candy forbids you to start a cakefight in her shop. \n");
      return 1;
      }
   if(name=="candy") {
      write("The pie explodes in your hands, as it refuses to hit its baker. \n"
          + "The cream covers everyone present here. \n");
      say("A cream pie explodes in " + TP->QSN + "'s hands, covering you and \n"
          + "everyone else with a sweet, sticky sludge. \n",TP);
      target = all_inventory(environment(TP));
      for(i=0;i<sizeof(target);i++) {
         if(target[i]->query_player()) {
            target[i]->set_smell(target[i]->QPN + " has a very strong sweet smell about " + target[i]->query_objective() + ".\n");
            }
         }
      destruct(this_object());
      return 1;
      }
   target = find_living(name);
   if(!target) {
      write("As you throw the pie in the air, you wonder where " +name+ " actually is... \n"
          + "SPLUTSH!! The pie falls straight back into your face, covering you all over \n"
          + "with sweet, sticky cream. You see an imp smiling amusedly in the distance. \n");
      say(TP->QSN + " throws up a cream pie, but fails to catch it again. \n"
          + TP->QPN + " is covered all over with sweet, sticky cream. \n",TP);
      TP->set_smell(TP->QPN + " has a very strong sweet smell about " + TP->query_objective() + ".\n");
      destruct(this_object());
      return 1;
      }
   if(environment(target) == find_object("/players/uglymouth/cakeshop/cakeshop")) {
      write(capitalize(name) + " is in Candy's Confectioner's shop. You are not allowed \n"
          + "to start a cakefight there. \n");
      return 1;
      }
   if(environment(TP) == environment(target)) {
      write("You throw a cream pie in " + capitalize(name) + "'s face. \n");
      tell_object(target,TP->QSN + " throws a cream pie into your face, covering you all over \n"
         + "with a sweet, sticky sludge. " + TP->QPN + " smiles amusedly. \n");
      say(TP->QSN + " throws a cream pie in " + capitalize(name) + "'s face. \n",target);
      target->set_smell(target->QPN + " has a very strong sweet smell about " + target->query_objective() + ".\n");
      if(!(target->query_player())) {
         write(capitalize(name) + " feels deeply insulted and decides to avenge your deed. \n");
         target->attack();
         }
      destruct(this_object());
      return 1;
      }
   if(TP->query_sp() < 10  || !(target->query_player())) {
      write("You can't focus enough on " + capitalize(name) + ". \n");
      return 1;
      }
   write("You throw a cream pie in " + capitalize(name) + "'s face. \n");
   transfer(this_object(),target);
   tell_object(target,".....SPLUTSH!! A cream pie lands in your face, covering you all over with a \n"
      + "sweet, sticky sludge. You see " + TP->QSN + " smiling amusedly in the distance. \n");
   say(".....SPLUTSH!! A cream pie lands in " + capitalize(name) + "'s face. \n",target);
   target->set_smell(target->QPN + " has a very strong sweet smell about " + target->query_objective() + ".\n");
   TP->restore_spell_points(-10);
   destruct(this_object());
   return 1;
   }

