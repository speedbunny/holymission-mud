inherit "/obj/weapon";
#define TP this_player()
#define NAME query_name()
object p;

reset(arg)
{
    ::reset(arg);
    set_name("Lightsaber");
    set_alias("saber");
    set_hit_func(this_object());
    set_short("Luke's Lightsaber");
    set_long(
      "This short, stout piece of metal is mostly nondescript.  There\n"+
      "is a small pressure plate near one end.  The metal of this\n"+
      "object is quite strong, and very light, but you have never seen\n"+
      "it before.  You wonder how something like this could be used by\n"+
      "anyone not connected with the Force.\n");
    set_weight(2);
    set_class(20);
    set_value(5000);
}

weapon_hit(ob)
{
    int guild;

    guild = this_player()->query_guild();
    if (random(10) <=4)
    {
	printf("You nearly decapitate your opponent with a well-placed\n"+
	  "swipe of the green blade.\n");
	say(" "+TP->NAME+" does tremendous damage with the lightsaber's\n"+
	  "green blade, nearly decapitating the opponent.\n",TP);
	if (guild == 4)
	    return(40+random(25));
	else
	    return (0+random(5));
    }
    if (guild !=4)
    {
	write(
	  "From your obvious lack of experience with the Force,\n"+
	  "you activate the saber backwards, and the blade\n"+
	  "forms a very neat hole through your abdomen.\n");
	TP->hit_player(40 + random(25),20);
	return 0;
    }
    return 1;
}
int query_quest_object() {
    return 1;
}
int wield (string str) {
    int w;
    if (w = ::wield(str)) {
	p = TP;
	tell_room(environment(p),""+p->NAME+" ignites the saber with a snap-hiss\n"+
	  "of greenish light.  It hums powerfully.\n");
    }
    return w;
}

int un_wield() {

    tell_room(environment(p),p->NAME+"'s blade of light disappears.\n");
    return ::un_wield();
}
