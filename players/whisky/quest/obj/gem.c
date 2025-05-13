inherit "/obj/treasure";

void reset(int flag)
{
   if (flag == 0)
   {
    set_id("gem");
    set_alias("gem of arcarnaton");
    set_short("A blue gem");
    set_long("This was once the famous gem of the Archmage of "+
             "Arcanaton.\n");
    set_weight(1);
    set_value(400);
   }
}
int get()
{
  return 1;
}

int drop()
{
  return 0;
}
