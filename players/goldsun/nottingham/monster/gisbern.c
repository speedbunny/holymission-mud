#define SAY(x) tell_room(environment(),x)
inherit "obj/monster";

reset(a) 
{
    ::reset(a);
    if (a) return 0;
    set_name("gisbern");
    set_alias("guard");
    set_alt_name("soldier");
    set_short("Soldier Gisbern");
    set_long("Guarding soldier Gisbern. You can see strong athletic body.\n"+
	     "he looks like he is ready to protect Nottingham treasure\n"+
	     "from enemies.\n");
    set_gender(1);
    set_race("gnome");
    set_size(3);
    set_level(50);
    set_dead_ob(this_object());
    add_money(1000+random(500));
    move_object(clone_object("/players/goldsun/nottingham/obj/blacksword"),this_object());
    init_command("wield sword");
    move_object(clone_object("/players/goldsun/nottingham/obj/shield"),this_object());
    init_command("wear shield");
}


hold(caller,time)
{
        return ::hold(caller,1);
}

init()
{
    ::init();
add_action("south","south");
add_action("melt","melt");
add_action("south","sneak");
add_action("hold_it","hold");
}

int south(){
 write("Guarding soldier Gisbern noticed you !!!\n");
 attack_object(this_player());
 return 1;
}

int hold_it(string str){
  if (!str)
   if (this_player()->query_attack()==this_object()){
    SAY("Gisbern laughs at you.\nGisbern says: I am protected.\n");
    return 1;
  }
  if (id (str) ){
    SAY("Gisbern laughs at you.\nGisbern says: I am protected.\n");
    return 1;
  }
}

int query_property(string str)
{
    return str=="no_steal";
}

int monster_died(object ob)
{
    if (interactive(this_player()))
	shout(this_player()->query_name()+" sent Gisbern to his creator.\n");
    return 0;
}

run_away(){
 write("This is a Gisbern.\nYou cannot fear him.\n");
 return 1;
}

int add_poison(int amount)
{
 add_poison(6);
    return 1;
}

int melt(){
 SAY("The soldier extinguish his sword.\n");
 return 1;
}

int query_dex(){ return 120;}
int query_str(){ return 120;}
