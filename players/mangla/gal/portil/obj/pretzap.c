get() { return 1;}
drop() { return 0; }
id() {return "prezap" || "pretzap"; }

init() {
     add_action("remtit","remtit");
}

remtit(arg) {
         if(!arg) return;
         if(!find_player(arg)) {
                  write("That player isn't logged on.\n");
                  return 1;
           }
         find_player(arg)->set_pretitle("none");
        return 1;
        }
