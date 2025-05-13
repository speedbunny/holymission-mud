inherit "obj/treasure";
object madness;
reset(arg){
::reset(arg);
set_light(1);

set_short("A Glowing Vial");
set_alias("vial");
set_alt_name("potion");
set_long("This is a small glowing bottle. On the side of the bottle\n"+
         "is writen the words 'AKIRA STRAIN' is large letters. Something\n"+
          "about this vial makes you think it would not be safe for you\n"+
          "to drink this.\n");
set_weight(1);
set_value(5000);
}
init(){
::init();
add_action("_drink", "drink");
}
_drink(str) {
if(!str){
notify_fail("What would you like to drink");
return 0;
}
if(str== "vial"){
write("You drink the strange glowing liquid from the vial. God Help You!\n");
madness = clone_object("/players/akira/fun/strain");
move_object ( madness, this_player());
madness->start_madness( this_player());
}
}
