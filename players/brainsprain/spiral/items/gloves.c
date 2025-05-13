inherit "obj/armour";
void reset(int arg) {
  ::reset(arg);

    set_name("gloves");
    set_alias("gloves");
    set_short("Leather gloves");
    set_long(
"  These gloves are made of a thick, supple leather.  There are several slash\n"+
"  marks that run the length of the right glove.  The left glove is stained in\n"+
"  in several places.  Little metal spikes adorn the knuckles of both gloves.\n");
    set_value(150);
    set_weight(1);
    set_type("glove");
    set_ac(1);
  }
