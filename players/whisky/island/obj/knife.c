
inherit "/obj/weapon";

string *col;
int i;


void reset(int arg)
{
   ::reset(arg);

   if (arg) return;
    col = ({"pink","yellow","green","aquamarin","blue","violet","red"});
   
   i = random(6);

   set_name("knife");
   set_alias(col[i]+" gnomish knife");
   set_short("A "+col[i]+" gnomish knife");
   set_long( 
   "You see a small gnomish knife. Its made of iron and is very "+
   "sharp. Funny its blade is painted in "+col[i]+".\n");
   set_class( (8+i) );
   set_weight(1);
   set_value( (20 + (40 * i)) );
   set_type(2);
}

