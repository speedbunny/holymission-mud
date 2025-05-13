inherit "obj/weapon";

void reset(int i)
{
 ::reset(i);
 if (i) return;
 set_name("hell hammer");
 set_alias("hammer");
 set_short("A hell hammer");
 set_long(
"This massive hammer was forged in hell, or at least in the heart of "+
"a volcano.  One end is flat, as you would expect from a hammer, but the "+
"other end has been sharpened to a point.  Either end looks dangerous.  "+
"There is a Cermor's sign on it.\n");
 set_weight(5);
 set_class(19);
 set_value(7000);
}  
