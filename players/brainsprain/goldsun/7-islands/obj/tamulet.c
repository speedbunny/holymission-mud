inherit "obj/armour";

void reset(int i)
{
 ::reset(i);
 if (i) return;
 set_name("amulet");
 set_short("Topaz amulet");
 set_type("amulet");
 set_ac(1);
 set_long(
"A middle sized leather disk has a small topaz eye mounted in the center "+
"of it.  A rawhide thong can be used to tie it around your neck.\n");
 set_value(100);
 set_weight(1);
}


