#pragma strict_types

inherit "obj/soft_drink";

int alchemic_value, doses;

void reset(int arg)
{
    ::reset(arg);
    if (!arg) 
    {
	set_name("poison");
	set_alias("potion");
	set_short("A vial of poison");
	set_drinker_mess("You put the vial to your lips and take a long draw.\n");
	set_drinking_mess(" drinks from a small vial.\n");
	set_empty_container("vial");
	doses = random(3) + 1;
    }
}

int disintegrate()       {  destruct(this_object()); return 1;  }

int drink(string str) 
{
    if (!str || !id(str)) 
	return 0;

    if (doses < 1)
    {
	write("The vial is empty\n");
	return 1;
    }

    full=0;
    food=0;
    write(drinker_mess);
    say(this_player()->query_name() + drinking_mess);
    this_player()->add_poison(strength);
    call_out("disintegrate",100);
    return 1;
}

int dec_doses(int arg)
{
    if (!arg)
	arg = 1;
    if (doses < 1)
	arg = 0;
    doses -= arg;
    if (doses == 0)
    {
	full = 0;
	food = 0;
        call_out("disintegrate",100);
    }
    return doses;
}

int query_doses()    {  return doses; }

int set_empty()      {  full=0; food=0;  return 1; } 

int query_alchemic() {  return 1;  }

int query_alchemic_value() {  return alchemic_value;  }

int query_poison()   {  return 1;  }

int set_alchemic_value(int arg) {
    alchemic_value = arg;
    return alchemic_value;
}

