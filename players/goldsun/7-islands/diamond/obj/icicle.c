inherit "/obj/weapon";

void reset(int i)
{
 ::reset(i);
 if (i) return;
 set_name("icicle");
 set_class(19);
 set_short("A icicle");
 set_long("This is long ice staff with Sighart sign on it.\n"+
          "It looks fragile but it is strong weapon.\n");
 set_weight(3);
 set_value(4320);
}

