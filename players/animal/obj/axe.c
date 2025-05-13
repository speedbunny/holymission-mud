object me;
string name_of_weapon;
string alt_name;
int value, rust;
int local_weight;
    string who;
 
query_name() { return "axe"; }
 
long() {
       if(!rust) {
    write("This axe has been used a lot. It is so rusty, that it\n" +
          " could not dig through a paper bag! It needs to be cleaned bad!\n");
	write("It is VERY fragile looking....VERY.\n");
          }else{
    write("The axe looks MUCH better (ie. usable) BUT it is still fragile.\n");
    }
}
 
init() {
          add_action("clean","clean");
          add_action("clean","oil");
          add_action("clean","rub");
}
 
 
 
short() {
        if(rust) {
     return "A small and light pick axe";
     }else{
     return "A small and rusty pick axe";
        }
}
 
id(str) {
        if(rust) {
    return (str == "clean pick axe" || str == "axe");
     }else{
        return(str == "rusty pick axe" || str == "axe");
        }
}
 
/*drop_object(str) {
    if (str == "all") {
        drop_object("axe");
        return;
    }
    if (!str || !id(str)) return 0;
    write("I TOLD you it was fragile! The axe breaks, and is gone.\n");
    say(call_other(this_player(), "query_name") +
    " drops an axe. It breaks because it is an OLD axe.\n");
    destruct(this_object());
    return 1;
}*/

/* Moonchild: use calls appropriate to Holy Mission mudlib & get rid of bug with   transfer */

drop() {
    write("I TOLD you it was fragile! The axe breaks, and is gone.\n");
    say(call_other(this_player(), "query_name") +
    " drops an axe. It breaks because it is an OLD axe.\n");
    destruct(this_object());
    return 1;
}

sell_object(str) { if(id(str)) return drop(); }
 
/*sell_object(str) {
     if(str == "all") {
          drop_object("axe");
          return;
     }
     if (id(str)) {
     drop_object("axe");
     return 1;
     }
}*/
 
set_name() {
    name_of_weapon ="axe";
}
 
query_value() {
    return 100;
}
 
 
query_weight() { return 1; }
 
set_weight() { local_weight =5; }
 
get() {
       rust = 0;
       return 1;
}
 
set_alt_name()
{
    alt_name = "pick axe";
}
 
clean(str)  {
            object name;
            name = capitalize(call_other(this_player(),"query_real_name"));
          if(!str) str == "axe";
          if(str == "axe" || str == "pick axe") {
          rust = 1;
          write("You succeed in cleaning the rust away.\n");
          write("The axe looks as good as new.\n");
          return 1;
     }
}
