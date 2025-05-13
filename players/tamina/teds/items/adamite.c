inherit "obj/treasure";

void reset(int arg) 
{
    if(arg) return 0;

    set_name("adamite");
    set_alias("adamite");
    set_short("A Large Lump of Raw Adamite");
    set_long("This lump of metal looks more like a meteor than anything else.\n");
    //    set_weight(6);
    set_value(100000);
}

string query_alias() 
{ 
    return "raw adamite meteor"; 
}

int query_no_steal() 
{ 
    return 1; 
}

int drop() 
{
    write("As you drop the adamite, it fades away into nothing.\n");
    call_out("done", 2);
    return 0;
}

done() 
{
    remove_call_out("done");
    destruct(this_object());
}
