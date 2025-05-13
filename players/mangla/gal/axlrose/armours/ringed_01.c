/* Axlrose - Human Army */
/* Soldier's Ringed Armor */
inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("circular-shaped ferrous pieces");
    set_alias("ringed");
    set_type("armour");
    set_ac(2);
    set_short("Ringed metal and leather armor");
    set_long
    ("A course leather tunic embedded with numerous circular rings of \n"
      +"ferrous metal pieces.  Small weld points appear in various strategic \n"
      +"places, though the occasional ring appears missing.\n");
    set_size(3);
    set_value(300);
    set_weight(2);
}
