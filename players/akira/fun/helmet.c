inherit "obj/armour";
object who;
reset(tick){
if(tick) return;
set_light(1);

set_name("Delphi Helmet");
set_alias("helmet");
set_short("Delphi Helmet");
set_long(" ");
set_weight(0);
set_type("helmet");
set_ac(2);
}
init(){
::init();
add_action("_psi_blast", "psi_blast");
add_action("_psi_bleed", "psi_bleed");
add_action("_psi-prison", "psi-prison");
add_action("_psi-hero", "psi-hero");    
}
int _psi_blast (string str){
if(!str) return 0;
who= find_living(str);
present(str, environment(this_player()));
if(who){
write("Your mind shots a powerful bolt of force at your target!\n");
tell_object(who, this_player()->query_name()+" hits you with a powerful"+
           "mind bolt. Your head feels like shit!\n");
who->hit_player(1000);
return 1;
}
else{
write("Who do you want to blast?\n");
return 1;
}
}
int _psi_bleed (string str){
if(!str) return 0;
who= find_living(str);
present(str, environment(this_player()));
if(who){
write("Your mind forcers your victims blood to boil!\n");
tell_object(who, this_player()->query_name()+" reaches out with his mind"+
            " and makes your blood boil within your body!\n");
who->add_posion(25);
return 1;
}
else{
write("Whos mind do you want to bleed?\n");
return 1;
}
return 1;
}
