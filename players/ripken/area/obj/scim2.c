inherit "/obj/weapon";

reset(arg)
{
    ::reset(arg);
    set_name("scimitar");
    set_short("The King's Scimitar");
    set_long(
      "The King's Scimitar is highly polished, and the grip is well worn,\n"+
      "but comfortable, like an old pair of Keds.  The blade is some four\n"+
      "feet long, and is wrought from the finest Spanish Steel.  The King\n"+
      "must have spent hours with the stone and oil, as it is VERY sharp,\n"+
      "and the hilt must be laced with lead to explain the fine balance.\n"+
      "All in all, a fearsome weapon worthy of a great warrior.\n");
    set_weight(7);
    set_class(14);
    set_value(1000);
}

