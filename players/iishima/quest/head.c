
inherit "obj/treasure";

void reset(int arg)
{
 ::reset();
 if (arg) return;
  set_alias("#headoflamtrashara#");
  set_id("head");
  short_desc = "Head of Lamtrashara";
  long_desc = "This is the head of the great dragonlord, Lamtrashara.\n";
  set_value(100);
  set_weight(1);
}
