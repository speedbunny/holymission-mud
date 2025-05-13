inherit "/obj/armour";
reset(tick){
if (tick) return;

set_name("Cloak of Rags");
set_alias("cloak");
set_alt_name("rags");
set_short("Cloak of Rags");
set_long("This is a cloak made of old rags. Legends say that it was\n"+
         "a gift from the god Mask to the thief guild. It was said\n"+
         "that the cloak made it easier to rob the monks temples and\n"+
         "even the monks, but no one knows how it does this.\n");
set_type("cloak");
set_weight(1);
set_value(2000);
}
init(){
 ::init();
              add_action("block", "smash");
              add_action("block", "choke");
              add_action("block", "death");
}
block (arg){
if(query_verb()== "smash"){
write("The Cloak of Rags jumps out and blocks your attack.\n");
return 1;
}
if(query_verb()=="choke"){
write("The Cloak of Rags gets in the way of your choke!\n");
return 1;
}
if(query_verb()=="death"){
write("The Cloak of Rags seems to parry the attack!\n");
return 1;
}
}
