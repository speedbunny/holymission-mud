inherit "obj/treasure";

void reset(int arg)
{
 ::reset(arg);
 if (arg) return;
 set_id("shovel");
 set_alias("#QUESTSHOVEL");
 set_short("A shovel");
 set_long("A small, Zalpur shovel that is used in the fields by the Zalpur Peasants.\n");
 set_weight(1);
 set_value(10);
}
