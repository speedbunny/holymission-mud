
inherit "/obj/treasure";

int reset(int tick)
{
    ::reset(tick);

    set_name("candle");
   set_short("A white candle");
   set_alias("candle");
   set_long("A white candle with runes");
    set_weight(1);
    set_value(10);
}

int query_object_type(){
    return 1;
}

int query_three_quest(){
    return 1;
}
