/* Axlrose - Human Army */
/* Broad Sword Fragments */
inherit "obj/treasure";

reset(arg) {
    if (arg) return;
    set_name("dull metal fragments");
    set_alt_name("scraps");
    set_alias("pieces");
    set_short("shattered steel scrap pieces");
    set_long
    ("Various shaped and sized pieces of both dull and sharp edged steel \n"
      +"scraps along with a mixture of other alloys from a sword of some type.\n");
    set_value(5);
    set_weight(1);
}
