inherit "obj/treasure";
int i;

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("uglymouth's wand");
      set_alias("wand");
      set_short("Uglymouth's wand");
      set_long("A granite wand engraved with an ugly mouth. \n");
      set_value(0);
      }
   }

void init() {
   ::init();
   add_action("wave","wave");
   }

int wave(string str) {
object env;
   if(str!="wand" && str!="ship" && str!="boat") return 0;
   env=environment(this_object());
   if(env->query_real_name()!="uglymouth") {
      write("This is not your wand! The wand disintegrates. \n");
      destruct(this_object());
      return 1;
      }

   if(str=="ship") {
      env=find_object("players/uglymouth/vikings/ship");
      if(env->query_location()==1) {
         env->move_back();
         return 1;
         }
      env->sail_away();
      return 1;
      }
   if(str=="boat") {
      ("/players/uglymouth/vikings/rowboat")->row();
      return 1;
      }
   if(str=="wand") {
      write("Your invisibility level is: "
          + this_player()->query_invis() + ". \n");
      return 1;
      }
   }
