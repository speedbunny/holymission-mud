inherit "obj/thing";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("megalith");
      set_alias("stone");
      set_short("A megalith");
      set_long("A tall rectangular stone. It's black \n"
             + "and there are symbols carved in it. \n");
      set_can_get(0);
      }
   }

void init() {
   ::init();
   add_action("exam","examine");
   add_action("exam","look");
   }

int exam(string str) {
   if(str!="symbols" && str!="at symbols") return 0;
   write(read_message);
   return 1;
   }
