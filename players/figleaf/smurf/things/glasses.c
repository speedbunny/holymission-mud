inherit "/obj/treasure";

void reset(int arg){

  ::reset(arg);
   if (arg)return;
    set_name("glasses");
    set_short("Brainy smurf's glasses");
    set_long("Brainy must have REALLY bad eyesight - these glasses are the"
" thickest you've ever seen!.\n");
    set_value(26);
    set_weight(1);
}
init()
{
 add_action("wear", "wear");
}

int wear(string str) {
 if(str !="glasses") {
 notify_fail("Wear what?\n");
 return 0;
 }
 write("You put the glasses on but they're so strong you can't see!\n");
 write("You stagger around until you trip over and hurt yourself.\n");
 write("The glasses fall off of your face.\n");
 say(capitalize(this_player()->query_name())+" puts on a thick pair of "+
"glasses and starts staggering \n"+
"around the room. Oops! "+capitalize(this_player()->query_pronoun())+" tripped and got hurt.\n");
 this_player()->hit_player(random(10)+1);
 return 1;
}
