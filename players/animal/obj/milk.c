int charges,i;
 
id(str) {
       return str == "goat's milk" || str == "milk";
        }
 
 
reset() {
       }
 
long() {
    write("The milk looks fresh and tasty.\n");
    }
 
short() {
     return "Goat's milk";
}
 
query_magic() { return 1;}
 
query_value()
{
    return 500;
}
 
 
init() {
    add_action("drink"); add_verb("drink");
}
 
drink(arg) {
    if (!id(arg)) 
       return 0;
    say(call_other(this_player(),"query_name",0) 
                     + " drink some goat's milk.\n");
    write("You feel much better...\n");
    call_other(this_player(),"heal_self",15+random(25));
    destruct(this_object());
    return 1;
}
 
get() {
    return 1;
}
 
query_weight() {
    return 2;
}
