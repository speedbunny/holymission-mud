/* This is a new weapon in special for too hard monsters */
short() {
return "A green Striker";
}
long() {
write("This is a new kind of weapon. You can use it beside your.\n"+
    "generell weapon just if you are attacked by a monster type.\n"+
      "<strike> a few times during the fight.\n"+
     "But this weapon can only be used a several times.\n"+
    "and dare to attack another players with this weapon.\n");}
int counter;
init() {
add_action("do_kill","strike");
}
id(str) { return str == "striker"; }
reset(arg) {
  if (arg) return;
counter = 0;
}
do_kill(str) {
object victim;
string player_name, victim_name;
int how_hard;
if (this_player()->query_attack() == 0) {
write("You arn't hunted by anybody\n");
return 1;
}
if (!str) { victim =call_other(this_player(),"query_attack");
}
if (this_player() != environment(this_object())) return 0;
if (counter >= 15) {
write("Suddenly your striker gets hot and falls to ashes\n");
destruct(this_object());
return 1;
}
else
{
player_name= call_other(this_player(),"query_name");
say(player_name + " plays the march of death "+victim->query_name()+" growls from pain.\n");
write("You are striking "+victim->query_name()+" extreamly hard "+victim->query_name()+" growls from pain.\n");
call_other(victim,"hit_player",15);
counter = counter+1;
}
return 1;
}
query_weight() { return 1; }
get() { return 1; }
query_value() { return 200; }
