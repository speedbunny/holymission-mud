inherit "obj/treasure";

reset(arg) 
{
    ::reset(arg);
    if(arg) return;
    set_name("alchemy stick");
    set_alias("stick");
    set_short("Alchemy stick");
    set_long("Alchemists use these to stir their experimental potions.\n");
    set_weight(1);
}

query_alchemic()       {  return 1;  }

