/* an oyster on the beach, sometimes it contains a pearl */
inherit "obj/thing";

void reset(int arg) {
   ::reset(arg);

  if(!arg) {
      set_name("oyster");
      set_alias("shell");
      set_short("A shell");
      set_long("It looks like an oyster. It's closed, but WOW! maybe it holds a pearl...\n");
      set_value(6);
      }
   }

void init() {
   ::init();
   add_action("open","open");
   }

int open(string str) {
object pearl;
int i;

   if(str!="oyster" && str!="shell") return 0;
   write("As you break open the oyster it shatters into small fragments. \n");
      i=(random(10));
      if(i<2) {
         write("This is your lucky day! You found a pearl. \n");
         pearl=clone_object("obj/treasure");
         pearl->set_id("pearl");
         pearl->set_alias("a pearl");
         pearl->set_short("A pearl");
         pearl->set_long("A small pearl. Too bad it's got some bad spots. \n");
         pearl->set_value(175 + random(50));
         transfer(pearl,this_player());
      destruct(this_object());
      return 1;
      }
   write("Unfortunately it was empty. \n");
   destruct(this_object());
   return 1;
   }
