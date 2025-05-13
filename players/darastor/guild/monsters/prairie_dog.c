
inherit "obj/monster";

reset(arg) {
 ::reset(arg);
 if(arg) return;

    set_name("Prairie Dog");
    set_alias("dog");
    set_short("Praire Dog");
    set_long("This small creature lives peacefully on this plain.\n");
    set_level(1 + random(3) );
    set_hp(10 +random(70));
    set_gender(1);
    set_race("rodent");
    set_ac(1);
    set_wc(4);

}
