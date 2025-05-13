#include "../../../obj/living.h"
 
object kill_ob;
 
object dead_ob;
object init_ob;
 
int spell_chance, spell_dam;
string spell_mess1, spell_mess2,alias;
object me;
 
reset(arg)
{
    int n;
    if(arg)
 return;
 
    n = random(3);
    call_out("random_move",30);
    if (n == 0) {
 name = "thing";
 spell_mess1 = "The Undead thing screams a death dry.";
 spell_mess2 = "The Undead thing screams a death cry at you.";
 spell_dam = 5;
 weapon_class = 10;
 armor_class = 2;
}
    if (n == 1) {
 name = "zombie";
 spell_mess1 = "The Zombie throws it's head.";
 spell_mess2 = "The Zombie throws it's head at you.";
 spell_dam = 10;
 weapon_class = 15;
 armor_class = 3;
}
    if (n == 2) {
 name = "wraith";
 spell_mess1 = "The Wraith screams.";
 spell_mess2 = "The Wraith screams, and breaks your eardrums.";
 spell_dam = 15;
 weapon_class = 18;
 armor_class = 4;
}
    alias = "zombie";
    set_living_name("zombie");
    spell_chance = 15;
    cap_name = capitalize(name);
    move_object(clone_object("obj/soul"), this_object());
    alignment = -200 * n -300;
    max_hp = 50 + 30 * n;
    hit_point = 50 + 30 * n;
    level = random(2) + 2 + 5*n;
    experience = call_other("room/adv_guild", "query_cost", level-1);
    is_npc = 1;
    me = this_object();
    set_heart_beat(1);
    enable_commands();
    random_move();
}
 
random_move()
{
    int n;
 
    age += 30;
 
    if (age>2000) {
	say("The zombie withers away to dust.\n");
 destruct(this_object());
 return 1;
    }
    if(!environment(this_object()))
 return 1;
    if(attacker_ob)
 return;
    n = random(6);
    if (n == 0)
command("west");
    else if (n == 1)
command("east");
    else if (n == 2)
command("south");
    else if (n == 3)
command("north");
    if (n == 4)
 if (random(100) <= 10)
      command("down");
    if (n == 5)
 if (random(100) <= 10) {
      tell_room(environment(this_object()),
  cap_name+" goes back to protect the evil world.\n");
	move_object(this_object(),"players/animal/evil5");
      tell_room(environment(this_object()),
  cap_name+" arrives, ready to defend the guild.\n");
 }
    check_environment();
    call_out("random_move",30);
    return 1;
}
 
short() {
	return ("A "+cap_name+" is standing here");
}
 
long() {
    write("This "+cap_name+" is the walking dead.\n");
    write("It despises good people.\n");
    if (hit_point > max_hp - 20)
       write("It seems to be in a good shape.\n");
}
 
id(str) { return str == name || str == "zombie"; }
 
check_environment() {
     object ob;
     if(!environment())
  return;
     ob = first_inventory(environment(me));
     while(ob) {
  if (!kill_ob && !attacker_ob && call_other(ob,"query_alignment",0)>300 && !call_other(ob,"query_npc",1))
       kill_ob = ob;
  if (present("assoul",ob) && ob->query_level()>level && !random(12))
       say("The "+cap_name+" bows to "+ob->query_name()+".\n");
  ob = next_inventory(ob);
     }
     if (kill_ob && present(kill_ob, environment(this_object()))) {
  say("The "+cap_name+" attacks the good player.\n");
  set_heart_beat(1);
  attack_object(kill_ob);
  kill_ob = 0;
  return;
     }
}
 
heart_beat() {
    object ob;
    int c;
    age += 1;
    if (attacker_ob && present(attacker_ob, environment(this_object())) &&
      spell_chance > random(100)) {
      say(spell_mess1 + "\n", attacker_ob);
      tell_object(attacker_ob, spell_mess2 + "\n");
      call_other(attacker_ob, "hit_player", random(spell_dam));
    }
    attack();
    if (attacker_ob && hit_point < max_hp/5)
     run_away();
    if(!attacker_ob)
     set_heart_beat(0);
}
 
init_command(cmd) {
    command(cmd);
}
 
set_dead_ob(ob)
{
    dead_ob = ob;
}
 
set_init_ob(ob)
{
    init_ob = ob;
}
 
init() {
    if(dead_ob)
if(call_other(dead_ob,"monster_init",this_object()))
    return;
    check_environment();
}
 
query_undead() {
     return 1;
}
 
