#define TELL(x) (tell_object(environment(this_object()),x));
#define SAY(x)  (tell_room(environment(this_object()),x));

int fused;
int ok_to_drop;
object thrower;

query_value() { return 1000; }
get() { return 1; }
drop() 
{
    if(fused && !ok_to_drop) {
        write("WHAT! Drop it at your feet?! 'Throw' it away from you.\n");
        return 1;
    }
    return 0;
}

id(str)
{
    return (str == "molotov cocktail" || str == "cocktail"
            || str == "bottle");
}

short()
{
    return "molotov cocktail";
}

long()
{
    write("This is a bottle filled with an unidentifiable liquid. A rag \n");
    write("has been stuck into the liquid through the top of the bottle. \n");
    write("A small label has been stuck to the side of the bottle.\n");
    write("The rag has "+(fused?"been lit":"not been lit")+".\n");
}
_read(str)
{
    if(!str) return 0;
    if(id(str) || str == "label") {
        write("<light rag> to light the Molotov cocktail.\n");
        write("<throw cocktail> to throw the Molotov cocktail.\n");

        write("This weapon can be extremely dangerous if directions are not\n");
        write("followed. I will not be responsible for any damages or losses\n");
        write("caused by this device.\n");
        write("Sendrigo\n");
	return 1;
    }
    return 0;
}

init()
{
    add_action("_light","light");
    add_action("_throw","throw");
    add_action("_read","read");
}

_light(str)
{
    if(environment(this_object()) != this_player()) {
	return 0;
    }
    if(str && str == "rag") {
	if(fused) {
	    write("The rag has already been lit.\n");
	    return 1;
	}
        write("You light the rag and the flame slowly eats its ");
        write("way down to the liquid...\n");
	say(this_player()->query_name() + " lights the rag " +
            "of the Molotov cocktail.\n");
	fused = 1;
	ok_to_drop = 0;
	call_out("explode", 7);
	return 1;
    }
}

_throw(str)
{
    if(environment(this_object()) != this_player()) {
	return 0;
    }
    if(id(str)) {
        write("You throw the Molotov cocktail into the air.\n");
	say(this_player()->query_name() + " throws a Molotov " +
	    "cocktail into the air!!\n");
	thrower = this_player();
	ok_to_drop = 1;
	transfer(this_object(),environment(this_player()));
	return 1;
    }
}

reset(a)
{
    if(a) create();
}
void create()
{
    fused = 0;
    ok_to_drop = 1;
}
explode()
{
    int i, s;
    object inv, owner;
    owner = environment(this_object());
    if(!owner) return;
    if(living(owner)) {
        TELL("BOOM! The Molotov cocktail explodes in your hands and hurls\n");
        TELL("flames and glass fragments into your face. You are injured!\n");
	tell_room(environment(owner), owner->query_name() + " seems to"+
		 " turn into a fireball as an accident happens!\n");
	owner->hit_player(50+random(20));
	destruct(this_object());
        return 1;
    }
    inv = all_inventory(environment(this_object()));
    SAY("BOOOM! The Molotov cocktail hits the ground and explodes in a\n");
    SAY("shower of fire and glass!\n");
    for(s = sizeof(inv), i = 0; i < s; i++) {
	if(inv[i] && living(inv[i])) {
	    if(inv[i]==thrower) {
		tell_object(thrower,
                "Your quick movements help you to escape most of the blast.\n");
	        owner->hit_player(15+random(5));
		continue;
	    }
	    tell_object(inv[i],"The flames and glass burn you! Aieee!\n");
	    SAY(inv[i]->query_name()+" is cut and burnt by the explosion!\n");
	    inv[i]->hit_player(50+random(30));
	}
    }
    destruct(this_object());
}
