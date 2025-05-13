string short_desc, name, message;
int value, strength, heal;
int numleft;
 
#define DESTRUCT 1200/* time to destruct */
 
set_value(str) {
    if (sscanf(str, "%s#%s#%s#%d#%d#%d#%d", name, short_desc, message,
               heal, value, strength, numleft) != 7)
    return 0;
    return 1;
}
 
id(str) {
    if ((str == name || (str == "keg")) && numleft)
          return 1;
     return str == "keg" || (!numleft && str == "empty keg");
}
 
short() {
    if (numleft)
    return short_desc;
    return "A empty keg";
}
 
/* The shop only buys empty bottles ! */
 
query_value()
{
    if (!numleft) return 20;
    return numleft * value;
}
 
long() {
    write(short() + ".\n");
    write("It has-> "+numleft+" taps left.\n");
    write("Use:  'tap <"+name+">' or 'tap <keg>'.\n");
}
 
reset(arg) {
    if (arg)
        return;
}
 
drink(str)
{
    int level, npc;
    string p_name;
    if (!str || !id(str))
          return 0;
    if (!numleft)
          return 0;
    level = this_player()->query_level();
    p_name = this_player()->query_name();
    npc = this_player()->query_npc();
    if (strength >= 12 && level < 10) {
    write("You sputter liquid all over the room.\n");
    say(p_name + " tries a " + name + " but coughs and sputters\n" +
    "all over you.\n");
    numleft--;
	fix_w();
    if(!numleft)
    call_out("my_destruct",DESTRUCT);
    return 1;
    }
    if (strength >= 8 && level < 5) {
     write("You throw it all up.\n");
     say(p_name + " tries to drink a " + name + " but throws up.\n");
     numleft--;
	fix_w();
      if(!numleft)
     call_out("my_destruct",DESTRUCT);
     return 1;
    }
    if (!this_player()->drink_alcohol(strength) && !npc)
     return 1;
    this_player()->heal_self(heal);
    write(message + ".\n");
    say(p_name+" drinks " + name + ".\n");
    numleft--;
	fix_w();
     if(!numleft)
    call_out("my_destruct",DESTRUCT);
    return 1;
}
 
my_destruct() {
     object money,old_env;
     money = clone_object("obj/money");
     money->set_money(random(20));
     old_env=environment(this_object());
     transfer(this_object(),"room/void");
     transfer(money, old_env);
     destruct(this_object());
     return 1;
}
 
init() {
    add_action("drink", "tap");
     add_action("drop","drop");
}
 
get() {
    return 1;
}
 
query_weight() {
    return numleft;
}


drop(str) {
	if(numleft) return 0;
	if (str =="all") {
	drop("keg");
	return;
	}
	if(!id(str)) return 0;
     transfer(this_object(), "room/void");
     write("The keg explodes when it hits the ground!\n");
     destruct(this_object());
     return 1;
}
fix_w() {
	this_player()->add_weight(-1);
}
